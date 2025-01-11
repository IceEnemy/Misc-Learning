import os
import cv2
import numpy as np

model_loaded = False
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

model_path = "frm.yml"
train_path = "dataset/train"
test_path = "dataset/test"

face_recognizer = cv2.face.LBPHFaceRecognizer_create()

person_name = os.listdir(train_path)

def train_model():
    global model_loaded
    if model_loaded:
        return
    if os.path.exists(model_path):
        face_recognizer.read(model_path)
        model_loaded = True
        return
    person_list = []
    class_list = []

    for idx, name in enumerate(person_name):
        full_path = os.path.join(train_path, name)

        for img_name in os.listdir(full_path):
            full_img_path = os.path.join(full_path, img_name)

            img = cv2.imread(full_img_path, cv2.IMREAD_GRAYSCALE)

            detected_faces = face_cascade.detectMultiScale(img, scaleFactor = 1.1, minNeighbors= 10)

            if len(detected_faces) < 1:
                continue

            for face_rect in detected_faces:
                x,y,w,h = face_rect
                face = img[y:y+h, x:x+w]

                person_list.append(face)
                class_list.append(idx)

    face_recognizer.train(person_list, np.array(class_list))
    face_recognizer.save('frm.yml')
    model_loaded = True

    correct = 0
    total = len(person_list)

    for i, face_img in enumerate(person_list):
        # Predict the label
        predicted_label, confidence = face_recognizer.predict(face_img)
        # Compare with the actual label
        if predicted_label == class_list[i]:
            correct += 1

    accuracy = (correct / total) * 100 if total > 0 else 0
    print(f"Training accuracy: {accuracy:.2f}%")

    return

def test_model():
    global person_name
    if model_loaded == False:
        return
    for img_name in os.listdir(test_path):
        full_path = os.path.join(test_path, img_name)

        img_gray = cv2.imread(full_path, cv2.IMREAD_GRAYSCALE)
        img = cv2.imread(full_path)

        detected_faces = face_cascade.detectMultiScale(img_gray, scaleFactor = 1.1, minNeighbors = 5)

        if len(detected_faces) < 1:
            continue
        for face_rect in detected_faces:
            x,y,w,h = face_rect
            face = img_gray[y:y+h, x:x+w]

            label, confindence = face_recognizer.predict(face)

            text = f"{person_name[label]} : {confindence:.2f}"
            cv2.rectangle(img,(x,y), (x+w, y+h), (255,0,0), 2)
            cv2.putText(img, text, (x, y-10), cv2.FONT_HERSHEY_PLAIN, 1.5, (0,255,0), 2)

        cv2.imshow("Result", img)
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


