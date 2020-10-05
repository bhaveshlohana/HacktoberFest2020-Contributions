#2 step process take image of background and select a colour for the cloth.
#code for image of the background
import cv2
#This is my webcam
cap = cv2.VideoCapture(0)
#back is what camera is reading
while cap.isOpened():
    ret,back=cap.read()  #Here i am simply reading from my webcam
    if ret:  #same as writing if ret == True
        cv2.imshow("image",back)


        if cv2.waitKey(5)==ord('q'):#ord is giving unicode value of q ie when q is
             cv2.imwrite('image.jpg',back)#pressed on keypad capture and save the image
             break
cap.release()
cap.destroyAllWindows()
