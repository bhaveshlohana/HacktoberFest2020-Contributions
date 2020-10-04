# -*- coding: utf-8 -*-
"""
Created on Wed Apr 17 15:35:46 2019

@author: edoardottt
"""
import random

class Enemy:
    x_n = 0
    y_n = 0
    destra = False
    def __init__(self, x_n, y_n):
        self.x_n = x_n
        self.y_n = y_n
        intero = random.randint(0,1)
        if (intero):
            self.destra = True
    def paintNemico(self,x,y,image,screen):
        screen.blit(image,(x,y))
    def __del__(self):
        self.x_n = -400
        self.y_n = -400