import cv2
import numpy as np
import pyautogui
import mediapipe as mp
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
import warnings
import time
import pickle
import tkinter as tk
from PIL import Image, ImageTk
import threading
import queue


warnings.filterwarnings("ignore")

# Initiliaze current label
current_label = "Ready"

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

# Train the classifier and save the model
def train_and_save_classifier(landmarks_list, labels):
    print("\nTraining classifier...")
    X = np.array(landmarks_list)
    y = np.array(labels)

    # Encode labels
    le = LabelEncoder()
    y_encoded = le.fit_transform(y)

    # Split data
    X_train, X_test, y_train, y_test = train_test_split(
        X, y_encoded, test_size=0.2, random_state=42
    )

    # Train Random Forest Classifier
    clf = RandomForestClassifier(n_estimators=100)
    clf.fit(X_train, y_train)

    # Evaluate
    accuracy = clf.score(X_test, y_test)
    print(f"Classifier accuracy: {accuracy * 100:.2f}%")

    # Save the classifier, label encoder to a pickle file
    with open('gesture_model.pkl', 'wb') as f:
        pickle.dump((clf, le), f)
    print("Model saved to 'gesture_model.pkl'")
    return clf, le

# Load the classifier from the pickle file
def load_classifier():
    try:
        with open('gesture_model.pkl', 'rb') as f:
            clf, le = pickle.load(f)
        current_label = "Model loaded from 'gesture_model.pkl'"
        return clf, le
    except FileNotFoundError:
        print("No saved model found. Please train a new model first.")
        exit()

# Main function for gesture recognition

class App:
    def __init__(self, root):
        self.root = root
        self.root.title("Hand Gesture Recognition")

        self.landmarks_list = []
        self.labels = []

        # self.current_label = "Ready"
        self.flag_update_frame = True

        self.app_label = tk.Label(root, text=current_label, font=("Arial", 16))
        self.app_label.grid(row=0, column=0)

        # Create a Label to display the video frames
        self.video_label = tk.Label(root)
        self.video_label.grid(row=1, column=0)

        # Create dynamic Button
        self.dynamic_button_flag = False
        self.dynamic_button = tk.Button(root, text="Execute", command=self.execute_btn)
        self.dynamic_button.grid(row=2, column=0, padx=10, pady=10)
        self.dynamic_button.grid_forget()


        # Start updating frames
        self.update_frame()

        # Buttons for options
        self.train_button = tk.Button(
            root, text="Create and Train New Model", command=self.train_new_model
        )
        self.train_button.grid(row=3, column=0, padx=10, pady=10)

        self.use_button = tk.Button(
            root, text="Use Existing Model", command=self.use_existing_model
        )
        self.use_button.grid(row=4, column=0, padx=10, pady=10)

        # Add a quit button
        self.quit_button = tk.Button(root, text="Quit", command=self.quit_app)
        self.quit_button.grid(row=5, column=0, padx=10, pady=10)


        self.previous_label = current_label
        self.update_label()

    def update_frame(self):
        if cap and self.flag_update_frame:
            ret, frame = cap.read()
            if ret:
                frame = cv2.flip(frame, 1)
                frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                img = Image.fromarray(frame)
                imgtk = ImageTk.PhotoImage(image=img)
                self.video_label.config(image=imgtk)
                self.video_label.image = imgtk

        self.video_label.after(10, self.update_frame)

    def quit_app(self):
        if cap:
            cap.release()
        self.root.destroy()
        return

    def update_label(self):
        global current_label

        if current_label != self.previous_label:
            self.app_label.config(text=current_label)  # Update the label widget
            self.previous_label = current_label  # Update the previous value

        # Schedule the next check
        self.root.after(30, self.update_label)

    def execute_btn(self):
        self.dynamic_button_flag = True
        self.root.after(50, self.reset_dynamic_button_flag)
    
    def reset_dynamic_button_flag(self):
        self.dynamic_button_flag = False

    def hide_dynamic_button(self):
        self.dynamic_button.grid_forget()  # Hide the button

    def show_dynamic_button(self):
        self.dynamic_button.grid(row=2, column=0, padx=10, pady=10)  # Show the button

    def disable_dynamic_button(self):
        self.dynamic_button.config(state="disabled")  # Disable the button

    def enable_dynamic_button(self):
        self.dynamic_button.config(state="normal")  # Enable the button

    def change_dynamic_button_text(self, new_text):
        self.dynamic_button.config(text=new_text)  # Change the button text


    def train_new_model(self):
        global current_label
        current_label = "Starting training process..."

        def training_workflow():
            self.collect_training_data()
            classifier, label_encoder = train_and_save_classifier(self.landmarks_list, self.labels)
            self.gesture_recognition(classifier, label_encoder)

        threading.Thread(target=training_workflow).start()
    
    def use_existing_model(self):
        global current_label
        current_label = "Using existing model..."
        classifier, label_encoder = load_classifier()
        threading.Thread(target=self.gesture_recognition, args=(classifier, label_encoder)).start()

    def collect_training_data(self):
        global current_label
        gestures = ['next', 'previous', 'none']
        current_label = "Starting data collection..."
        time.sleep(1)

        for gesture in gestures:
            current_label = f"Prepare for collecting data for gesture: '{gesture}'."
            time.sleep(1)
            current_label = "Press Start to start collecting data for this gesture."

            while True:
                ret, frame = cap.read()
                if not ret:
                    print("Warning: Could not read frame.")
                    continue
                frame = cv2.flip(frame, 1)
                # frame = preprocess_frame(frame)  # Apply preprocessing

                # Draw the text on the video frame
                cv2.putText(
                    frame, f"Prepare for '{gesture}' gesture", (10, 50),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255), 2
                )

                # Convert the frame to ImageTk format and update the video label
                self.flag_update_frame = False
                self.change_dynamic_button_text("Start")
                self.enable_dynamic_button()
                self.show_dynamic_button()

                frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                img = Image.fromarray(frame_rgb)
                imgtk = ImageTk.PhotoImage(image=img)
                self.video_label.config(image=imgtk)
                self.video_label.image = imgtk

                # Check for key input
                if self.dynamic_button_flag:
                    self.disable_dynamic_button()
                    self.hide_dynamic_button()
                    break

            count = 0
            target_count = 1000 if gesture == 'none' else 500
            current_label = f"Collecting data for gesture: '{gesture}'..."

            while count < target_count:
                ret, frame = cap.read()
                if not ret:
                    print("Warning: Could not read frame.")
                    continue
                frame = cv2.flip(frame, 1)
                # frame = preprocess_frame(frame)  # Apply preprocessing
                frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                results = hands.process(frame_rgb)

                if results.multi_hand_landmarks:
                    for hand_landmarks in results.multi_hand_landmarks:
                        normalized_landmarks = normalize_landmarks(hand_landmarks.landmark)
                        self.landmarks_list.append(normalized_landmarks)
                        self.labels.append(gesture)
                        count += 1

                        # Draw the text and hand landmarks on the video frame
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

                # Update the video label
                self.change_dynamic_button_text("Exit")
                self.enable_dynamic_button()
                self.show_dynamic_button()

                frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                img = Image.fromarray(frame_rgb)
                imgtk = ImageTk.PhotoImage(image=img)
                self.video_label.config(image=imgtk)
                self.video_label.image = imgtk

                if self.dynamic_button_flag:
                    break

            current_label = f"Data collection for gesture '{gesture}' completed."

        self.flag_update_frame = True
        self.hide_dynamic_button()
        self.disable_dynamic_button()
        current_label = "Data collection for all gestures completed."

    def gesture_recognition(self, clf, le):
        global current_label
        current_label = "Starting gesture recognition..."
        last_action_times = {}
        action_delay = 1.0

        while True:
            ret, frame = cap.read()
            if not ret:
                current_label = "Warning: Could not read frame."
                continue
            frame = cv2.flip(frame, 1)
            # frame = preprocess_frame(frame)  # Apply preprocessing
            frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            results = hands.process(frame_rgb)

            if results.multi_hand_landmarks:
                for idx, hand_landmarks in enumerate(results.multi_hand_landmarks):
                    normalized_landmarks = normalize_landmarks(hand_landmarks.landmark)
                    landmarks = np.array(normalized_landmarks).reshape(1, -1)
                    prediction = clf.predict(landmarks)
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

            # Update the video label
            self.change_dynamic_button_text("Exit")
            self.enable_dynamic_button()
            self.show_dynamic_button()

            self.flag_update_frame = False
            frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            img = Image.fromarray(frame_rgb)
            imgtk = ImageTk.PhotoImage(image=img)
            self.video_label.config(image=imgtk)
            self.video_label.image = imgtk

            if self.dynamic_button_flag:
                break
        
        current_label = "Gesture recognition ended."
        self.flag_update_frame = True
        self.disable_dynamic_button()
        self.hide_dynamic_button()

# Run the steps
if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()