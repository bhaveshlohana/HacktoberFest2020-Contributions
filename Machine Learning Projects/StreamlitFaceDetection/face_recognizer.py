import numpy as np
import os
import cv2
from PIL import Image

recognizer = cv2.face.LBPHFaceRecognizer_create()
#Local Binary Pattern Histogram uses pixel intensity+variations to map and recognize a particular image
path = 'dataSet'

def getImg(path):
    #supply path that grabs images and automatically converts these captured images to numpy arrays
    imgPaths = [os.path.join(path,f) for f in os.listdir(path)]
    faces = []
    ids = []

    for imgPath in imgPaths:
        face = Image.open(imgPath).convert('L') #first open the image
        numpyFaces = np.array(face, 'uint8') #convert image to a numpy array
        print(imgPath)
        id = int(os.path.split(imgPath)[-1].split('.')[1])
        faces.append(numpyFaces)
        ids.append(id)
        cv2.imshow('Training', numpyFaces)
        cv2.waitKey(30)

    return np.array(ids), faces

ids, faces = getImg(path)
recognizer.train(faces,ids)
recognizer.save('trainingData.yml')
cv2.destroyAllWindows()

