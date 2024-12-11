import cv2
import numpy as np
import pyautogui
import mediapipe as mp
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder, StandardScaler
import warnings
import time
import pickle

warnings.filterwarnings("ignore")

# Initialize the webcam
cap = cv2.VideoCapture(0)

# Check if camera is opened
if not cap.isOpened():
    print("Error: Could not access the camera.")
    exit()

# Initialize MediaPipe Hand model
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(
    static_image_mode=False,
    max_num_hands=2,
    min_detection_confidence=0.7,
    min_tracking_confidence=0.7
)
mp_drawing = mp.solutions.drawing_utils

# Placeholder for training data
landmarks_list = []
labels = []

# Function to normalize landmarks
def normalize_landmarks(landmarks):
    landmarks_array = np.array([[lm.x, lm.y, lm.z] for lm in landmarks])
    centroid = np.mean(landmarks_array, axis=0)
    landmarks_centered = landmarks_array - centroid
    max_distance = np.max(np.linalg.norm(landmarks_centered, axis=1))
    if max_distance > 0:
        landmarks_normalized = landmarks_centered / max_distance
    else:
        landmarks_normalized = landmarks_centered
    normalized_landmarks = landmarks_normalized.flatten().tolist()
    return normalized_landmarks

# Apply image processing functions
def preprocess_frame(frame):
    # Apply Gaussian Blur
    frame_blur = cv2.GaussianBlur(frame, (5, 5), 0)
    # Apply Canny edge detection
    frame_edges = cv2.Canny(frame_blur, 100, 200)
    return frame_edges

# Collect training data
def collect_training_data():
    gestures = ['next', 'previous', 'none']
    print("Starting data collection...")
    for gesture in gestures:
        print(f"\nPrepare for collecting data for gesture: '{gesture}'.")
        print("Press 's' to start collecting data for this gesture.")
        while True:
            ret, frame = cap.read()
            if not ret:
                print("Warning: Could not read frame.")
                continue
            frame = cv2.flip(frame, 1)
            frame = preprocess_frame(frame)  # Apply preprocessing
            cv2.putText(
                frame, f"Prepare for '{gesture}' gesture", (10, 50),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255), 2
            )
            cv2.putText(
                frame, "Press 's' to start", (10, 100),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2
            )
            cv2.imshow('Preparation', frame)
            key = cv2.waitKey(1) & 0xFF
            if key == ord('s'):
                cv2.destroyWindow('Preparation')
                break
            elif key == ord('q'):
                cap.release()
                cv2.destroyAllWindows()
                print("Data collection aborted by user.")
                exit()
        count = 0
        target_count = 1000 if gesture == 'none' else 500
        print(f"Collecting data for gesture: '{gesture}'")
        while count < target_count:
            ret, frame = cap.read()
            if not ret:
                print("Warning: Could not read frame.")
                continue
            frame = cv2.flip(frame, 1)
            frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            results = hands.process(frame_rgb)
            if results.multi_hand_landmarks:
                for hand_landmarks in results.multi_hand_landmarks:
                    normalized_landmarks = normalize_landmarks(hand_landmarks.landmark)
                    landmarks_list.append(normalized_landmarks)
                    labels.append(gesture)
                    count += 1
                    cv2.putText(
                        frame, f"Gesture: '{gesture}', Count: {count}/{target_count}", (10, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2
                    )
                    mp_drawing.draw_landmarks(
                        frame, hand_landmarks, mp_hands.HAND_CONNECTIONS
                    )
                    if count >= target_count:
                        break
            else:
                cv2.putText(
                    frame, "No hands detected", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2
                )
            cv2.imshow('Data Collection (MediaPipe)', frame)
            if cv2.waitKey(1) & 0xFF == ord('q') or count >= target_count:
                break
        print(f"Data collection for gesture '{gesture}' completed.")
    print("Data collection for all gestures completed.")
    cv2.destroyAllWindows()

# Train the classifier and save the model
def train_and_save_classifier():
    print("\nTraining classifier...")
    X = np.array(landmarks_list)
    y = np.array(labels)

    # Encode labels
    le = LabelEncoder()
    y_encoded = le.fit_transform(y)

    # Standardize features
    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)

    # Split data
    X_train, X_test, y_train, y_test = train_test_split(
        X_scaled, y_encoded, test_size=0.2, random_state=42
    )

    # Train Random Forest Classifier
    clf = RandomForestClassifier(n_estimators=100)
    clf.fit(X_train, y_train)

    # Evaluate
    accuracy = clf.score(X_test, y_test)
    print(f"Classifier accuracy: {accuracy * 100:.2f}%")

    # Save the classifier, label encoder, and scaler to a pickle file
    with open('gesture_model.pkl', 'wb') as f:
        pickle.dump((clf, le, scaler), f)
    print("Model saved to 'gesture_model.pkl'")
    return clf, le, scaler

# Load the classifier from the pickle file
def load_classifier():
    try:
        with open('gesture_model.pkl', 'rb') as f:
            clf, le, scaler = pickle.load(f)
        print("Model loaded from 'gesture_model.pkl'")
        return clf, le, scaler
    except FileNotFoundError:
        print("No saved model found. Please train a new model first.")
        exit()

# Main function for gesture recognition
def gesture_recognition(clf, le, scaler):
    print("\nStarting gesture recognition...")
    print("Press 'q' to quit.")
    last_action_times = {}
    action_delay = 1.0

    while True:
        ret, frame = cap.read()
        if not ret:
            print("Warning: Could not read frame.")
            continue
        frame = cv2.flip(frame, 1)
        frame = preprocess_frame(frame)  # Apply preprocessing
        frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = hands.process(frame_rgb)

        if results.multi_hand_landmarks:
            for idx, hand_landmarks in enumerate(results.multi_hand_landmarks):
                normalized_landmarks = normalize_landmarks(hand_landmarks.landmark)
                landmarks = np.array(normalized_landmarks).reshape(1, -1)
                landmarks_scaled = scaler.transform(landmarks)
                prediction = clf.predict(landmarks_scaled)
                gesture = le.inverse_transform(prediction)[0]

                # Display gesture prediction on the frame
                cv2.putText(
                    frame, f"Gesture: {gesture}", (10, 30 + idx * 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2
                )
                mp_drawing.draw_landmarks(
                    frame, hand_landmarks, mp_hands.HAND_CONNECTIONS
                )

                # Trigger actions based on gesture
                current_time = time.time()
                hand_id = idx
                if hand_id not in last_action_times:
                    last_action_times[hand_id] = 0
                if gesture in ['next', 'previous']:
                    if (current_time - last_action_times[hand_id]) > action_delay:
                        if gesture == 'next':
                            pyautogui.press('right')
                        elif gesture == 'previous':
                            pyautogui.press('left')
                        last_action_times[hand_id] = current_time

        else:
            cv2.putText(
                frame, "No hands detected", (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2
            )

        # Show the gesture recognition frame
        cv2.imshow('Gesture Recognition (MediaPipe)', frame)

        # Exit on 'q' key
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
    print("Gesture recognition ended.")

# Run the steps
if __name__ == "__main__":
    print("Choose an option:")
    print("1. Create a new gesture dataset and train a new model")
    print("2. Use the existing model")
    choice = input("Enter 1 or 2: ")

    if choice == '1':
        collect_training_data()
        classifier, label_encoder, scaler = train_and_save_classifier()
        gesture_recognition(classifier, label_encoder, scaler)
    elif choice == '2':
        classifier, label_encoder, scaler = load_classifier()
        gesture_recognition(classifier, label_encoder, scaler)
    else:
        print("Invalid choice. Exiting.")
        cap.release()
        cv2.destroyAllWindows()
        exit()
