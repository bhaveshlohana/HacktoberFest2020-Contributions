import cv2
import face_recognition
import numpy as np
import os      #used for automatically making a list of images and its encodings from a folder

path = 'ImageBasic'
images = []
classNames = []
myList = os.listdir(path)   # This will make a list of all the images in the dir
print(myList)
for cl in myList:       # Split : is used to avoid the .DS_Store File
    curImg = cv2.imread(f'{path}/{cl}')
    images.append(curImg)                       # This images list will have the Numeric codes of every image
    classNames.append(os.path.splitext(cl)[0])  # This splits the text of the Path, i.e. => Anurag Gupta from Anurag Gupta.jpg
print(classNames)

def findEncoding(images):       # Function to find the encodings of all the above images
    encodeList = []
    for img in images:
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        encode = face_recognition.face_encodings(img)[0]
        encodeList.append(encode)
    return encodeList

encodeListKnown = findEncoding(images)
print('Encoding Complete')

cap = cv2.VideoCapture(0)

while True:
    success, img = cap.read()
    imgS = cv2.resize(img,(0,0),None, 0.25, 0.25)
    imgS = cv2.cvtColor(imgS, cv2.COLOR_BGR2RGB)
    facesCurFrame = face_recognition.face_locations(imgS)
    encodeCurFrame = face_recognition.face_encodings(imgS, facesCurFrame)

    for encodeFace,faceLoc in zip(encodeCurFrame, facesCurFrame):
        matches = face_recognition.compare_faces(encodeListKnown, encodeFace)
        faceDis = face_recognition.face_distance(encodeListKnown, encodeFace)
        print(faceDis)
        matchIndex = np.argmin(faceDis)
        if matches[matchIndex]:
            name = classNames[matchIndex].upper()
            print(name)
            y1,x2,y2,x1 = faceLoc
            y1,x2,y2,x1 = y1*4, x2*4, y2*4, x1*4
            cv2.rectangle(img, (x1,y1),(x2,y2),(255,0,0),2)
            cv2.rectangle(img, (x1,y2-35), (x2,y2),(255,0,0), cv2.FILLED)
            cv2.putText(img, name,(x1+6,y2-6),cv2.FONT_ITALIC,1, (255,255,255),2)


    cv2.imshow('Webcam', img)
    cv2.waitKey(1)












