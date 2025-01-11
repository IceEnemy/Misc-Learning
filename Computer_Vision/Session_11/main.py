import os
import cv2
import numpy as np

# Load the pre-trained model to detect faces
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

model_path = 'face_recognizer_model.yml'
train_path = 'dataset/train'
test_path = 'dataset/test'

model_loaded = False
face_recognizer = cv2.face.LBPHFaceRecognizer_create()  # Ensure `opencv-contrib-python` is installed

# Declare `person_name` as a global variable
person_name = []
person_name = os.listdir(train_path)


def train_model():
    global model_loaded, person_name
    if model_loaded:
        print("Model is already loaded")
        return

    if os.path.exists(model_path):
        print("Loading the model...")
        face_recognizer.read(model_path)
        model_loaded = True
        print("Model loaded successfully")
        return

    print("Training the model...")
    face_list = []
    class_list = []

    for idx, name in enumerate(person_name):
        full_path = os.path.join(train_path, name)

        for img_name in os.listdir(full_path):
            img_full_path = os.path.join(full_path, img_name)

            # Read image in grayscale
            img = cv2.imread(img_full_path, cv2.IMREAD_GRAYSCALE)

            # Detect faces in the image
            detected_faces = face_cascade.detectMultiScale(img, scaleFactor=1.1, minNeighbors=10)

            if len(detected_faces) < 1:
                continue

            for face_rect in detected_faces:
                x, y, w, h = face_rect
                face_img = img[y:y + h, x:x + w]

                # Store the face and its corresponding class index
                face_list.append(face_img)
                class_list.append(idx)

    face_recognizer.train(face_list, np.array(class_list))
    face_recognizer.save(model_path)
    model_loaded = True
    print("Model trained and saved successfully")


def test_model():
    global person_name

    if not model_loaded:
        print("Model is not loaded. Please train the model first")
        return

    print("Testing the model...")
    for img_name in os.listdir(test_path):
        img_full_path = os.path.join(test_path, img_name)

        # Read images for both processing and visualization
        img_gray = cv2.imread(img_full_path, 0)
        img_bgr = cv2.imread(img_full_path)

        # Detect faces in the test image
        detected_faces = face_cascade.detectMultiScale(img_gray, scaleFactor=1.1, minNeighbors=5)

        if len(detected_faces) < 1:
            continue

        for face_rect in detected_faces:
            x, y, w, h = face_rect
            face_img = img_gray[y:y + h, x:x + w]

            # Predict the identity of the face
            label, confidence = face_recognizer.predict(face_img)

            # Annotate the image with the prediction
            result_text = f"{person_name[label]}: {confidence:.2f}"
            cv2.rectangle(img_bgr, (x, y), (x + w, y + h), (255, 0, 0), 2)
            cv2.putText(img_bgr, result_text, (x, y - 10), cv2.FONT_HERSHEY_PLAIN, 1.5, (0, 255, 0), 2)

        # Display the annotated image
        cv2.imshow('Result', img_bgr)
        cv2.waitKey(0)

    cv2.destroyAllWindows()


while True:
    print("My Application")
    print("1. Train / read the model")
    print("2. Test the model")
    print("3. Exit")
    choice = input("Enter your choice: ")

    if choice == '1':
        train_model()
    elif choice == '2':
        test_model()
    elif choice == '3':
        print("Exiting the application")
        break
    else:
        print("Invalid choice. Please try again")
