import cv2
face_cascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

img = cv2.imread("group.jpg")
gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
faces = face_cascade.detectMultiScale(gray_img)

for x,y,w,h in faces:
    final_img = cv2.rectangle(img, (x,y), (x+w, y+h), (0,255,0), 1)

output = cv2.imshow("output", final_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

