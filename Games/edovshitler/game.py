# -*- coding: utf-8 -*-
"""
Created on Tue Apr 16 15:18:48 2019

@author: edoardottt

Copyright (c) 2020 Edoardo Ottavianelli

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
"""
version = "0.1.2"
print("https://www.edoardoottavianelli.it")
print("edovshitler v"+version)
print("MIT License")
# pygame libraries required
import pygame
import random
from Enemy import Enemy
from Missile import Missile
from Bomb import Bomb
import results
import sys,time

#initialize pygame-------------------------------------------------------------
pygame.init()

# display game definitions-----------------------------------------------------
screenWidth=800
screenHeight=600
screen = pygame.display.set_mode((screenWidth,screenHeight)) # set the screen dimension
pygame.display.set_caption("edovshitler") # set the title of the screen
pygame.key.set_repeat(0,0) # allow repeat key with 1st (before the first reapeat) and 2st(between 2 repeats)

# images loading
edo = pygame.image.load("edo.png")
screenDisplay = pygame.image.load("wallpaper.png")
missilepaint = pygame.image.load("missile.png")
hitlersx = pygame.image.load("hitlersx.png")
hitlerdx = pygame.image.load("hitlerdx.png")
explo = pygame.image.load("explosion.png")
bomb = pygame.image.load("bomb.png")
end = pygame.image.load("end.jpg")
gameoverdisplay = pygame.image.load("gameover.jpg")
x = (screenWidth*0.45) # Edo x coordinate
y = (screenHeight*0.74) # Edo y coordinate


#function definitions----------------------------------------------------------
def paintEdo(x,y):	# Edo painting function
    screen.blit(edo,(x,y))
def paintExplo(x,y):	# explotion painting function
    screen.blit(explo,(x,y))

# variables definitions--------------------------------------------------------
timee = 0	# loopGame iterations
movimentox = 0	# Edo x movement 
incrementoy = 25	# Edo y movement
incrementohit = 30	
y_missile = y - 15	# missile init painting
inc_bomba = 15	# bomb y increment movement
nemici_sconfitti = 0	# enemies defeated number
bombe_evitate = 0	#bombs avoided
missili_sparati = 0	# missiles shooted
missilen = 0	# missiles number
missili = []	# missiles array
nemici = []		# enemies array
bombe = []		# bombs array
loopGame = True	# game while loop controller
spara = False	# True if the gamer shoots
hit = False		# True if almost an enemy is present
bombes = False	# True if almost a bomb is present
pressright = False	# True if right key is held down
pressleft = False	# True if left key is held down
abbassa = False		# True if an enemy is on a side of the screen and It has to go down
gameover = False	# True if game is over
quitting = False	# True if the gamer quits the game
fine = True		# It becomes False if the gamer quits before the gameover
every_enemy = 8	# Every how many iterations an enemy appears
every_bomb = 13	# Every how many iterations a bomb appears
font = 'freesansbold.ttf'	# Font definition

# colors definition
white=(255, 255, 255)	
black=(0, 0, 0)
gray=(50, 50, 50)
red=(255, 0, 0)
green=(0, 255, 0)
blue=(0, 0, 255)
yellow=(255, 255, 0)

# start menu-------------------------------------------------------------------

menu=True
selected = 0
menu_object = ["start","commands","info","quit"]
pygame.font.init()

def text_format(message, textFont, textSize, textColor):
    newFont=pygame.font.Font(textFont, textSize)
    newText=newFont.render(message, 0, textColor)
 
    return newText

while menu:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type==pygame.KEYDOWN:
            if event.key==pygame.K_UP:
                if(selected!=0):
                    selected -=1
            elif event.key==pygame.K_DOWN:
                if(selected!=3):
                    selected +=1
            if event.key==pygame.K_RETURN:
                if (selected == 0):
                    menu = False
                elif (selected == 1):
                    screen.fill(blue)
                    pygame.display.set_caption("edovshitler | Commands") # set the title of the screen
                    move_string = 'press left or right key to move edo'
                    shoot_string = 'press space key for shoot'
                    pause_string = 'press P key for pause/resume the game'
                    string5 = 'press enter to return to menu'
                    text_move = text_format(move_string, font, 24, white)
                    text_shoot = text_format(shoot_string, font, 24, white)
                    text_pause = text_format(pause_string, font, 24, white)
                    text5 = text_format(string5, font, 15, yellow)
                    move_rect = text_move.get_rect()
                    shoot_rect = text_shoot.get_rect()
                    pause_rect = text_pause.get_rect()
                    rect5 = text5.get_rect()
                    screen.blit(text_move, (screenWidth/2 - (move_rect[2]/2), 200))
                    screen.blit(text_shoot, (screenWidth/2 - (shoot_rect[2]/2), 280))
                    screen.blit(text_pause, (screenWidth/2 - (pause_rect[2]/2), 360))
                    screen.blit(text5, (screenWidth/2 - (rect5[2]/2), 550))
                    loop = True
                    pygame.display.update()
                    while loop:
                        for event in pygame.event.get():
                            if event.type==pygame.QUIT:
                                pygame.quit()
                                sys.exit()
                            if event.type==pygame.KEYDOWN:
                                if event.key==pygame.K_RETURN:
                                    loop = False
                elif (selected == 2):
                    screen.fill(blue)
                    pygame.display.set_caption("edovshitler | Info") # set the title of the screen
                    string1 = 'Edoardo Ottavianelli ©'
                    string2 = 'https://www.edoardoottavianelli.it'
                    string3 = 'This product is kept on https://github.com/edoardottt/edovshitler'
                    string4 = 'Under MIT License'
                    string5 = 'press enter to return to menu'
                    text1 = text_format(string1, font, 24, white)
                    text2 = text_format(string2, font, 22, white)
                    text3 = text_format(string3, font, 14, white)
                    text4 = text_format(string4, font, 20, white)
                    text5 = text_format(string5, font, 15, yellow)
                    rect1 = text1.get_rect()
                    rect2 = text2.get_rect()
                    rect3 = text3.get_rect()
                    rect4 = text4.get_rect()
                    rect5 = text5.get_rect()
                    screen.blit(text1, (screenWidth/2 - (rect1[2]/2), 200))
                    screen.blit(text2, (screenWidth/2 - (rect2[2]/2), 260))
                    screen.blit(text3, (screenWidth/2 - (rect3[2]/2), 320))
                    screen.blit(text4, (screenWidth/2 - (rect4[2]/2), 380))
                    screen.blit(text5, (screenWidth/2 - (rect5[2]/2), 550))
                    loop = True
                    pygame.display.update()
                    while loop:
                        for event in pygame.event.get():
                            if event.type==pygame.QUIT:
                                pygame.quit()
                                sys.exit()
                            if event.type==pygame.KEYDOWN:
                                if event.key==pygame.K_RETURN:
                                    loop = False
                else:
                    pygame.quit()
                    sys.exit()
 
        # Main Menu UI
        screen.fill(blue)
        title=text_format("edovshitler", font, 90, yellow)
        if selected==0:
            text_start = text_format("START", font, 75, white)
        else:
            text_start = text_format("START", font, 75, black)
        if selected==1:
            text_commands = text_format("COMMANDS", font, 75, white)
        else:
            text_commands = text_format("COMMANDS", font, 75, black)
        if selected==2:
            text_info = text_format("INFO", font, 75, white)
        else:
            text_info = text_format("INFO", font, 75, black)
        if selected==3:
            text_quit = text_format("QUIT", font, 75, white)
        else:
            text_quit = text_format("QUIT", font, 75, black)
 
        title_rect=title.get_rect()
        start_rect=text_start.get_rect()
        commands_rect = text_commands.get_rect()
        info_rect = text_info.get_rect()
        quit_rect=text_quit.get_rect()
 
        # Main Menu Text
        screen.blit(title, (screenWidth/2 - (title_rect[2]/2), 80))
        screen.blit(text_start, (screenWidth/2 - (start_rect[2]/2), 260))
        screen.blit(text_commands, (screenWidth/2 - (commands_rect[2]/2), 320))
        screen.blit(text_info, (screenWidth/2 - (info_rect[2]/2), 380))
        screen.blit(text_quit, (screenWidth/2 - (quit_rect[2]/2), 440))
        pygame.display.update()
        pygame.display.set_caption("edovshitler | Menu") # set the title of the screen

# The game---------------------------------------------------------------------
pygame.display.set_caption("edovshitler") # set the title of the screen
while(loopGame):
    if (gameover):
        loopGame=False
    else:
        for event in pygame.event.get():
            if (event.type==pygame.QUIT):
                loopGame=False
                quitting = True
                fine = False
            if (event.type==pygame.KEYDOWN): # if I press a key
                if (event.key==pygame.K_RIGHT): # right button held down
                    movimentox = 26
                    pressright= True
                if (event.key==pygame.K_LEFT): # left button held down
                    movimentox = -26
                    pressleft= True
            if (event.type==pygame.KEYUP): # if I release a key
                if (event.key==pygame.K_RIGHT): # right button released
                    pressright= False
                    if (pressleft):
                        movimentox = -26
                    else:
                        movimentox = 0
                elif (event.key==pygame.K_LEFT): # left button released
                    pressleft = False
                    if (pressright):
                        movimentox = 26
                    else:
                        movimentox = 0
                if (event.key==pygame.K_SPACE):
                    y_missile = y - 15
                    missile = missili.append(Missile(x+30,y_missile))
                    incrementoy = 28
                    spara = True
                    missili_sparati +=1
                if (event.key==pygame.K_p): # PAUSE
                    loop = True
                    while(loop):
                        for event in pygame.event.get():
                            if (event.type==pygame.KEYUP):
                                if (event.key==pygame.K_p): # RESUME THE GAME
                                    loop = False

        screen.blit(screenDisplay,(0,0))
        x = x + movimentox
        if (x < 0):
            x = 0
        elif (x > 700):
            x = 700
        timee = timee + 1
        result = []
        for item in missili:
          if (item.y_m<-10) is False:
            result.append(item)
        missili = result
        if (spara):
            for i in range(len(missili)):
                missile = missili[i]
                missile.y_m = missile.y_m -incrementoy
                missile.paintMissile(missile.x_m,missile.y_m,missilepaint,screen)
        result = []
        for item in nemici:
          if (item.y_n<-10) is False:
            result.append(item)
        nemici = result
        if (hit):
            for i in range(len(nemici)):
                nemico = nemici[i]
                if (490<=nemico.y_n<=600 and 0<=nemico.x_n<=760):
                    gameover = True
                    time.sleep(1)
                if (nemico.destra):
                    nemico.x_n = nemico.x_n + incrementohit
                else:
                    nemico.x_n = nemico.x_n - incrementohit
                if (nemico.x_n>=730):
                    nemico.destra = False
                    abbassa = True
                elif (nemico.x_n<=0):
                    nemico.destra = True
                    abbassa = True
                if (nemico.destra):
                    nemico.paintNemico(nemico.x_n,nemico.y_n,hitlerdx,screen)
                    if(abbassa):
                        abbassa = False
                        nemico.y_n = nemico.y_n + 90
                else:
                    nemico.paintNemico(nemico.x_n,nemico.y_n,hitlersx,screen)
                    if(abbassa):
                        abbassa = False
                        nemico.y_n = nemico.y_n + 90
        result = []
        for item in bombe:
          if (item.y_m<-10) is False:
            result.append(item)
        bombe = result
        if(bombes):
            for i in range(len(bombe)):
                bomba = bombe[i]
                if (x-35<=bomba.x_m<=x+90 and y-50<=bomba.y_m<=y+155):
                    paintExplo(bomba.x_m,bomba.y_m-100)
                    paintExplo(bomba.x_m,bomba.y_m-50)
                    paintExplo(bomba.x_m,bomba.y_m)
                    paintExplo(bomba.x_m+100,bomba.y_m-100)
                    paintExplo(bomba.x_m-100,bomba.y_m-100)
                    pygame.display.update()
                    gameover = True
                    time.sleep(1)
                if (bomba.y_m>500):
                    paintExplo(bomba.x_m,bomba.y_m-100)
                    bombe[i].__del__()
                    bombe_evitate += 1
                bomba.y_m = bomba.y_m + inc_bomba
                bomba.paintBomb(bomba.x_m,bomba.y_m,bomb,screen)
                        
        for i in range(len(missili)):
            for j in range(len(nemici)):
                x_missile = missili[i].x_m
                y_missile = missili[i].y_m
                x_nemico = nemici[j].x_n
                y_nemico = nemici[j].y_n
                if (x_nemico-20<x_missile<x_nemico+70):
                    if (y_nemico<y_missile<y_nemico+90):
                        paintExplo(x_nemico,y_nemico)
                        pygame.display.update()
                        nemici[j].__del__()
                        nemici_sconfitti += 1
        result = []
        for item in nemici:
          if (item.y_n<-10) is False:
            result.append(item)
        nemici = result
        if (timee%every_enemy==0):
            if(every_enemy!=1 and (timee%500 == 0)):
                every_enemy-=1
            hit = True
            random1 = random.randint(1,600)
            nemico = nemici.append(Enemy(random1,0))
        if (timee%every_bomb==0):
            if(every_bomb!=3 and (timee%500 == 0)):
                every_bomb-=1
            bombes = True
            lennemici = len(nemici) - 1
            if(lennemici>=1):
                random2 = random.randint(1,lennemici)
                bombarolo = nemici[random2]
                bomba = bombe.append(Bomb(bombarolo.x_n,bombarolo.y_n))
        if (0<=x<=693):
            paintEdo(x,y)
        elif (x<0):
            paintEdo(0,y)
        else:
            paintEdo(693,y)
        #pygame.display.update() update only a part of the screen
        pygame.display.flip() #update the whole screen
        
# RESULT SAVING AND RECORD CHECKING-------------------------------------
if(not quitting):
    screen.blit(gameoverdisplay,(0,0))
    pygame.display.flip() #update the whole screen
    stringarecord = results.save(missili_sparati,bombe_evitate,nemici_sconfitti)  
    pygame.time.wait(4000)
    record = False
    if (int(stringarecord[0])==bombe_evitate or int(stringarecord[1])==missili_sparati or int(stringarecord[2])==nemici_sconfitti):
        record = True
        
#RESULT VISUALIZATION------------------------------------------------------------------------------
    
if(fine):
    pygame.font.init()
    font = pygame.font.Font('freesansbold.ttf', 32) 
    stringaresult = "Bombs: " + str(bombe_evitate) + " | Missiles: " + str(missili_sparati) + " | Enemies: " + str(nemici_sconfitti)
    text = font.render(stringaresult, True, green, blue)
    screen.fill(white)
    screen.blit(end,(0,0))
    screen.blit(text, (100,0))
    if (record):
        text1 = font.render("VERY NICE!! NEW RECORD!", True, green, blue)
        screen.blit(text1, (150,100))
    text2 = font.render("BOMBS RECORD: " + stringarecord[0], True, green, blue)
    screen.blit(text2, (150,250))
    text3 = font.render("MISSILES RECORD: " + stringarecord[1], True, green, blue)
    screen.blit(text3, (150,310))
    text4 = font.render("ENEMIES RECORD: " + stringarecord[2], True, green, blue)
    screen.blit(text4, (150,370))
    text5 = font.render("?ENTER TO QUIT", True, red, white)
    screen.blit(text5, (250,550))
    pygame.display.flip() #update the whole screen
    yes = True
    while(yes):
        for event in pygame.event.get():
            if (event.type==pygame.KEYDOWN): # if I press a key
                if (event.key==pygame.K_RETURN): # right button held down
                    yes = False
pygame.quit()
sys.exit()