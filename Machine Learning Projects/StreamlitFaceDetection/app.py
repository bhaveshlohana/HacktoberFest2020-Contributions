import streamlit as st
import cv2
from PIL import Image
import numpy as np

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

rec = cv2.face.LBPHFaceRecognizer_create()
rec.read('trainingData.yml')

def detect(img):
    img = np.array(img.convert('RGB'))
    imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    #detection
    faces = face_cascade.detectMultiScale(imgGray, 1.1, 4)
    name='??'
    for (x,y,w,h) in faces:
        cv2.rectangle(img, (x,y), (x+w, y+h), (255,255,0), 2)
        id, uncert = rec.predict(imgGray[y:y+h, x:x+w])
        print(id, uncert)

        if uncert < 53 :
            if (id == 1 or id==3 or id==5):
                name='Devangi'
                cv2.putText(img, name, (x,y+h), cv2.FONT_HERSHEY_COMPLEX, 2, (8,8,255))

            else:
                cv2.putText(img, name, (x, y + h), cv2.FONT_HERSHEY_COMPLEX, 2, (8, 8, 255))

    return img, faces, name

def main():
    st.set_option('deprecation.showfileUploaderEncoding', False)
    st.title("Face Recognizer App")
    #html_body = """<body style="background-color:cyan;"</body> """

    html_temp = """
    <body style="background-color:cyan;">
    <div style="background-color:teal; padding:10px">
    <h2 style="color:white; text-align:center; "> Face Recognition App</h2>
    </div>
    </body>
    """

    st.markdown(html_temp, unsafe_allow_html=True)

    img = st.file_uploader('Upload The Image', type=['png', 'jpg', 'jpeg'])
    if img is not None:
        myImg = Image.open(img)
        st.text('Original Image')
        st.image(myImg)

    if st.button('Recognize'):
        res = detect(myImg)
        st.image(res)

if __name__=='__main__':
    main()