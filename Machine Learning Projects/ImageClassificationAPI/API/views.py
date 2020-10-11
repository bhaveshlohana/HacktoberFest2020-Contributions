from django.shortcuts import render
from rest_framework import status
from rest_framework.response import Response
from urllib.request import urlopen
from PIL import Image
from tensorflow.keras.preprocessing import image
import numpy as np
from .apps import ApiConfig
from rest_framework.views import APIView
from django.contrib.auth.models import User, auth
# Create your views here.


class Image_Class_Model(APIView):
    def post(self, request, format=None):
        data = request.data
        response_dict = {}
        
        try:
            url = data['url']
            username = data['username']
            password = data['password']
            
        except:
            return Response(response_dict, status=status.HTTP_401_UNAUTHORIZED)
        
        user = auth.authenticate(username=username,password=password)
        if user is not None:
            img_height, img_width = 224, 224
            model = ApiConfig.model
            labelInfo = ApiConfig.labelInfo
            im = Image.open(urlopen(url))
            img = im.resize((img_height, img_width))
            x = image.img_to_array(img)
            x /= 255
            x = x.reshape(1, img_height, img_width, 3)
            predi = model.predict(x)
            final_prediction = labelInfo[str(np.argmax(predi[0]))][1]
            response_dict = {"prediction":final_prediction, "accuracy":max(predi[0])}
            return Response(response_dict, status=status.HTTP_200_OK)
        else:
            return Response(response_dict, status=status.HTTP_401_UNAUTHORIZED)
        

