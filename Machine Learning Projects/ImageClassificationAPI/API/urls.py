from django.urls import path
from . import views
urlpatterns = [
    path('', views.Image_Class_Model.as_view(), name='predict'),
    ]