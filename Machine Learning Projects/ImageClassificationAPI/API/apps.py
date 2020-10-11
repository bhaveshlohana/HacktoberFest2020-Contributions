from django.apps import AppConfig
from tensorflow.keras.models import load_model
import json
class ApiConfig(AppConfig):
    name = 'API'
    model = load_model('./models/img_class.h5')
    with open('./models/imagenet_classes.json','r') as f:
        labelInfo1 = f.read()

    labelInfo = json.loads(labelInfo1)
