# -*- coding: utf-8 -*-
"""
Created on Wed Apr 17 17:05:14 2019

@author: edoardottt
"""

class Bomb:
    x_m = 0
    y_m = 0
    def __init__(self, x_m, y_m):
        self.x_m = x_m
        self.y_m = y_m
    def paintBomb(self,x,y,image,screen):
        screen.blit(image,(x,y))
    def __del__(self):
        self.x_m= -400
        self.y_m = -400