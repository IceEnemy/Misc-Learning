import os
import cv2
import numpy as np

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

model_path = 'frm.yml'
train_path = 'dataset/train'
test_path = 'dataset/test'

model_loaded = False
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
    
    face_list = []
    class_list = []

    for idx, name in enumerate(person_name):
        full_path = os.path.join(train_path, name)

        for img_name in os.listdir(full_path):
            full_img_path = os.path.join(full_path, img_name)

            img = cv2.imread(full_img_path, cv2.IMREAD_GRAYSCALE)

            detected_faces = face_cascade.detectMultiScale(img, scaleFactor=1.1, minNeighbors=10)

            if len(detected_faces) < 1:
                continue
            for face_rect in detected_faces:
                x,y,w,h = face_rect

                face = img[y:y+h, x:x+w]

                face_list.append(face)
                class_list.append(idx)
    face_recognizer.train(face_list, np.array(class_list))
    face_recognizer.save(model_path)
    model_loaded = True

    correct = 0

    for i, face in enumerate(face_list):
        label, confidence = face_recognizer.predict(face)
        if label == class_list[i]:
            correct+=1
    
    total = len(face_list)
    if total == 0:
        print("0%")
    else:
        res = correct/total
        print(f"Accuracy: {100 * res:.2f}%")

    return

def test_model():
    if not model_loaded:
        return
    for img_name in os.listdir(test_path):
        full_img_path = os.path.join(test_path, img_name)

        img_gray = cv2.imread(full_img_path, cv2.IMREAD_GRAYSCALE)
        img = cv2.imread(full_img_path)

        detected_faces = face_cascade.detectMultiScale(img_gray, scaleFactor=1.1,minNeighbors=5)

        if len(detected_faces) < 1:
            continue
        for face_rect in detected_faces:
            x,y,w,h = face_rect
            face = img_gray[y:y+h, x:x+w]

            label, confidence = face_recognizer.predict(face)

            text = f"{person_name[label]} : {confidence:.2f}"
            cv2.rectangle(img, (x,y), (x+w,y+h), (255,0,0), 2)
            cv2.putText(img, text, (x,y-10), cv2.FONT_HERSHEY_PLAIN, 1.5, (0,255,0), 2)
        cv2.imshow("Result", img)
        cv2.waitKey(0)
    cv2.destroyAllWindows()

while True:
    print("My Application")
    print("1. Train / Read Model")
    print("2. Test the model")
    print("3. Exit")
    
    choice = int(input("Enter your choice: "))

    if choice == 1:
        train_model()
    elif choice == 2:
        test_model()
    elif choice == 3:
        break
    else:
        print("try again")
