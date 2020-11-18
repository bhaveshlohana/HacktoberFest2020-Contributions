import cv2
import numpy as np

cap=cv2.VideoCapture(0)



if cap.isOpened():
    ret, frame = cap.read()
   
else:
   ret = False    


while ret:
    ret,frame=cap.read()
    hsv=cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    #Blue color
    #low= np.array([100,50,50])
    #high= np.array([140,255,255])
    #green color
    #low= np.array([40,50,50])
    #high=np.array([80,255,255])
   # red color
    low= np.array([140,150,0])
    high= np.array([180,255,255])
   # yellow shades
    #low=np.array([0,50,50])
    #high=np.array([30,255,255])
    
    imaage_mask= cv2.inRange(hsv,low,high)
    output1= cv2.bitwise_and(frame,frame,mask=imaage_mask)
    #print(imaage_mask)
    cv2.imshow("Image Mask",imaage_mask)
    cv2.imshow("Blue Color Tracking",output1)

    cv2.imshow("Original WebCam Feed",frame)
    #cv2.imshow(windowName,output)

    if cv2.waitKey(1)==27:
        break

cv2.destroyAllWindows()

cap.release() #releasing the camera