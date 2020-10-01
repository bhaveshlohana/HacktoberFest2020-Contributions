#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Aug 19 19:33:42 2020
@author: archit
"""

import pygame

import _thread

pygame.init() # Its a default statement, do every time

# SCREEN LAYOUT VARIABLES

WINDOW_HEIGHT = 600
WINDOW_WIDTH = 1000
BORDER_WIDTH = WINDOW_WIDTH
BORDER_HEIGHT = 20
WALL_COLOR = "white"
BALL_COLOR = "blue"

# END SCREEN LAYOUT VARIABLES

screen = pygame.display.set_mode((WINDOW_WIDTH,WINDOW_HEIGHT))

# Setup the borders
# Define Classes

class Ball:
    RADIUS = 10
    score = 0
    def __init__(self,x,y,vx,vy):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
    
    def show(self,color):
        global screen
        pygame.draw.circle(
            screen,
            pygame.Color(color),
            (self.x,self.y),
            self.RADIUS
        )
    
    def update(self,racket):
        self.show("black")
        newx = self.x + self.vx
        newy = self.y + self.vy
        # Collision with the walls
        if newx < BORDER_HEIGHT+self.RADIUS:
            self.vx = -self.vx
        if newy < BORDER_HEIGHT+self.RADIUS or newy > WINDOW_HEIGHT-BORDER_HEIGHT-self.RADIUS:
            self.vy = -self.vy
        # Collision with paddle
        if newx == WINDOW_WIDTH-racket.length and newy>racket.y and newy<racket.y+racket.height:
            self.vx = -self.vx
            self.vy = -self.vy
            self.score+=1
        if newx > WINDOW_WIDTH-racket.length:
            self.game_over()
        
            
        self.x += self.vx
        self.y += self.vy
        self.show("white")
     
    def game_over(self):
        print("Game Over, Your Score: {}".format(self.score))
        pygame.quit()
        

class Paddle:
    length = 16
    height = 52
    x = WINDOW_WIDTH - length
    def __init__(self,y):
        self.y = y
    
    def show(self,color):
        global screen
        pygame.draw.rect(
                screen,
                pygame.Color(color),
                pygame.Rect((self.x,self.y),
                (self.length,self.height))
                
            )
    def update(self):
        self.show('black')
        newx , newy = pygame.mouse.get_pos()
        newy -= self.height//2
        newy1 = newy + self.height
        if newy>BORDER_HEIGHT and newy1<WINDOW_HEIGHT-BORDER_HEIGHT:
            self.y = newy
        self.show('white')
        

# Classes defined
# Initialize BALL and PADDLE Object
ball_play = Ball(WINDOW_WIDTH-Ball.RADIUS-16, WINDOW_HEIGHT//2, -1,1)
racket = Paddle(WINDOW_HEIGHT//2-26)
# Setup the borders
pygame.draw.rect(
        screen,
        pygame.Color("white"),
        pygame.Rect((0,0),
        (BORDER_WIDTH,BORDER_HEIGHT))
    )
pygame.draw.rect(
        screen,
        pygame.Color(WALL_COLOR),
        pygame.Rect((0,0),
        (BORDER_HEIGHT,WINDOW_HEIGHT))
    )
pygame.draw.rect(
        screen,
        pygame.Color(WALL_COLOR),
        pygame.Rect((0,WINDOW_HEIGHT-10),
        (BORDER_WIDTH,BORDER_HEIGHT))
    )
# Borders are setup
ball_play.show("white")
racket.show("white")

# On pressing X, it doesnt exit. To exit, listen for events and if the type is quit, quit.
while True:
    e = pygame.event.poll()
    if e.type == pygame.QUIT:
        pygame.quit()
    ball_play.update(racket)
    racket.update()        
    pygame.display.flip()
