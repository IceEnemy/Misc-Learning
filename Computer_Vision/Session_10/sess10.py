import cv2
import os
import numpy as np

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

face_list = []
class_list = []

train_path = 'dataset/train'
person_name = os.listdir(train_path)

for idx, name in enumerate(person_name):
    full_path = train_path + '/' + name

    for img_name in os.listdir(full_path):
        img_full_path = full_path + '/' + img_name

        #read for gray scale
        img = cv2.imread(img_full_path, 0)

        #minNeighbors: how many neighbors each candidate rectangle should have to retain it
        #scaleFactor: how much the image size is reduced at each image scale
        detected_face = face_cascade.detectMultiScale(img, scaleFactor=1.1, minNeighbors=10)

        if len(detected_face) < 1:
            continue

        for face_rect in detected_face:
            x, y, h, w = face_rect
            face_img = img[y:y+h, x:x+w]

            face_list.append(face_img)
            class_list.append(idx)

face_recognizer = cv2.face.LBPHFaceRecognizer_create()
face_recognizer.train(face_list, np.array(class_list))

test_path = 'dataset/test'

for img_name in os.listdir(test_path):
    img_full_path = test_path + '/' + img_name

    img_gray = cv2.imread(img_full_path, 0)
    img_bgr = cv2.imread(img_full_path)

    detected_face = face_cascade.detectMultiScale(img_gray, scaleFactor=1.1, minNeighbors=10)

    if len(detected_face) < 1:
        continue

    for face_rect in detected_face:
        x, y, h, w = face_rect
        face_img = img_gray[y:y+h, x:x+w]

        res, confidence = face_recognizer.predict(face_img)

        cv2.rectangle(img_bgr, (x, y), (x+w, y+h), (255, 0, 0), 1)
        text = person_name[res] + ": " + str(confidence)
        cv2.putText(img_bgr, text, (x, y-10), cv2.FONT_HERSHEY_PLAIN, 1.5, (255, 0, 0), 1)
    
    cv2.imshow('Result', img_bgr)
    cv2.waitKey(0)
    
cv2.destroyAllWindows()

