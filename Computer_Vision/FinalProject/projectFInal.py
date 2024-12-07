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

# Collect training data with preparation pause
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

# Implement feature detection and keypoints matching
def find_keypoints_and_match(frame1, frame2):
    orb = cv2.ORB_create()  # Using ORB as a local feature detector
    kp1, des1 = orb.detectAndCompute(frame1, None)
    kp2, des2 = orb.detectAndCompute(frame2, None)

    # Use BFMatcher to find correspondences
    bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
    matches_orb = bf.match(des1, des2)
    matches_orb = sorted(matches_orb, key=lambda x: x.distance)

    # Draw ORB matches
    match_img_orb = cv2.drawMatches(frame1, kp1, frame2, kp2, matches_orb[:10], None, flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)
    cv2.imshow('ORB Keypoints Matching', match_img_orb)

    # Using SIFT as a local feature detector
    sift = cv2.SIFT_create()
    kp1_sift, des1_sift = sift.detectAndCompute(frame1, None)
    kp2_sift, des2_sift = sift.detectAndCompute(frame2, None)

    # Use BFMatcher to find correspondences for SIFT
    bf_sift = cv2.BFMatcher()
    matches_sift = bf_sift.match(des1_sift, des2_sift)
    matches_sift = sorted(matches_sift, key=lambda x: x.distance)

    # Draw SIFT matches
    match_img_sift = cv2.drawMatches(frame1, kp1_sift, frame2, kp2_sift, matches_sift[:10], None, flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)
    cv2.imshow('SIFT Keypoints Matching', match_img_sift)

    # Wait for a key press to close the windows
    cv2.waitKey(0)
    cv2.destroyAllWindows()

    # Comparison between ORB and SIFT
    print(f"ORB: Number of keypoints in Image 1: {len(kp1)}, Image 2: {len(kp2)}")
    print(f"SIFT: Number of keypoints in Image 1: {len(kp1_sift)}, Image 2: {len(kp2_sift)}")
    print(f"ORB: Number of matches: {len(matches_orb)}")
    print(f"SIFT: Number of matches: {len(matches_sift)}")

    # Use keypoints matches to find correspondences and compare images
    if len(matches_sift) > 10:  # Ensure there are enough matches to proceed
        src_pts = np.float32([kp1_sift[m.queryIdx].pt for m in matches_sift[:10]]).reshape(-1, 1, 2)
        dst_pts = np.float32([kp2_sift[m.trainIdx].pt for m in matches_sift[:10]]).reshape(-1, 1, 2)
        M, mask = cv2.findHomography(src_pts, dst_pts, cv2.RANSAC, 5.0)
        if M is not None:
            h, w = frame1.shape[:2]
            pts = np.float32([[0, 0], [0, h - 1], [w - 1, h - 1], [w - 1, 0]]).reshape(-1, 1, 2)
            dst = cv2.perspectiveTransform(pts, M)
            frame2 = cv2.polylines(frame2, [np.int32(dst)], True, 255, 3, cv2.LINE_AA)
            cv2.imshow('SIFT Correspondence', frame2)
            cv2.waitKey(0)
            cv2.destroyAllWindows()

# Main function for gesture recognition
def gesture_recognition(clf, le, scaler):
    print("\nStarting gesture recognition...")
    print("Press 'q' to quit.")
    last_action_times = {}
    action_delay = 1.0

    reference_frame = None  # For keypoints matching

    while True:
        ret, frame = cap.read()
        if not ret:
            print("Warning: Could not read frame.")
            continue
        frame = cv2.flip(frame, 1)
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

        # Run SIFT and ORB on the current frame with the reference frame
        if reference_frame is None:
            reference_frame = frame.copy()
        else:
            orb = cv2.ORB_create()
            kp1, des1 = orb.detectAndCompute(reference_frame, None)
            kp2, des2 = orb.detectAndCompute(frame, None)
            if des1 is not None and des2 is not None:
                bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
                matches_orb = bf.match(des1, des2)
                matches_orb = sorted(matches_orb, key=lambda x: x.distance)
                match_img_orb = cv2.drawMatches(reference_frame, kp1, frame, kp2, matches_orb[:10], None, flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)
                cv2.imshow('ORB Keypoints Matching', match_img_orb)

            sift = cv2.SIFT_create()
            kp1_sift, des1_sift = sift.detectAndCompute(reference_frame, None)
            kp2_sift, des2_sift = sift.detectAndCompute(frame, None)
            if des1_sift is not None and des2_sift is not None:
                bf_sift = cv2.BFMatcher()
                matches_sift = bf_sift.match(des1_sift, des2_sift)
                matches_sift = sorted(matches_sift, key=lambda x: x.distance)
                match_img_sift = cv2.drawMatches(reference_frame, kp1_sift, frame, kp2_sift, matches_sift[:10], None, flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)
                cv2.imshow('SIFT Keypoints Matching', match_img_sift)

            # Update the reference frame periodically
            reference_frame = frame.copy()

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
