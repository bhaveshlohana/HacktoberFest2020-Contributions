import cv2
import numpy as np

cap=cv2.VideoCapture(0)
back=cv2.imread('./image.jpg')
kernel = np.ones((5,5),np.uint8)

while cap.isOpened():
    #take each frame
    ret,frame=cap.read()

    if ret:
        #how do we convert rgb to hsv?
        hsv=cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        #cv2.imshow("hsv",hsv)
        #how to get hsv value?
        #lower: h-10,100,100 ; higher h+10,255,255
        red = np.uint8([[[0,0,255]]])# bgr value of red is high
        hsv_red=cv2.cvtColor(red,cv2.COLOR_BGR2HSV)#get hsv value or red from bgr
        #print(hsv_red)
        #threshold the hsv value to get only red colours
        l_red=np.array([0,100,100])
        u_red=np.array([10,255,255])
        #we are disappering those reds that fall under range l_red and u_red

        mask=cv2.inRange(hsv , l_red , u_red)

        #cv2.imshow("mask",mask)

        # show all things red
        part1= cv2.bitwise_and(back,back,mask=mask)#doing and of back and red
        #cv2.imshow("part1",part1)

        mask=cv2.bitwise_not(mask)

        #all things not red
        part2 = cv2.bitwise_and(frame,frame,mask=mask)
        #cv2.imshow("mask",part2)
        mask= cv2.dilate(mask,kernel,iterations = 1)
        mask= cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        mask= cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)

        cv2.imshow("cloak",part1+part2)

        if cv2.waitKey(5)==ord('q'):
            break

cap.release()
cap.destroyAllWindows()

#as edges are not clear using opencv morphology


#using hsv here and not rgb cuz hsv(hue saturation value) is more similar to the
#way humans see colours its a mixture of colours and intensity and light while rgb
#is just a mixture of colours
