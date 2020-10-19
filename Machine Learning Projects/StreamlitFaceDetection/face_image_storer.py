import cv2
import numpy as np
import sqlite3
import os

cam = cv2.VideoCapture(0)
detector = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

conn = sqlite3.connect('database.db')
if not os.path.exists('./dataSet'):
    os.makedirs('./dataSet')

c = conn.cursor()

id = input('Enter your name: ')
sample = 0
while True:
    ret, img = cam.read()
    ImgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = detector.detectMultiScale(ImgGray, 1.3, 5) #helps to detect images of many sizes
    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x,y), (x+w, y+h), (30,30,80), 2)
        cv2.imwrite('dataSet/User.'+id+'.'+str(sample)+'.jpg', ImgGray)
        sample+=1
        cv2.imshow('image', img)
    #wait 50 milliseconds
    key = cv2.waitKey(1) & 0xFF
    if key == ord('q'):
        break
    elif sample > 20:
        break

cam.release()
cv2.destroyAllWindows()