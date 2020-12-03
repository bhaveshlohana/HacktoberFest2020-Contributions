from django.urls import path
from . import views



app_name='spotify'
urlpatterns=[
    path('',views.index,name='index'),
    path('choice',views.choices,name='choices'),
    path('game-over',views.gameOver,name='game-over'),
    path('data',views.data,name='data'),
    path('page',views.page,name='page')



]