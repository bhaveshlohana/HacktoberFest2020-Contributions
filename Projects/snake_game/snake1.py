import pygame
import random
import numpy as np
import time
#initialize pygame
#display apple
def display_apple(screen,apple_pos,apple_image):
    screen.blit(apple_image,(apple_pos[0],apple_pos[1]))


#attackers
def display_attackers(attaker_pos):
    pygame.draw.rect(screen,(255,0,0),pygame.Rect(attaker_pos[0],attaker_pos[1],10,10))


#snake
def display_snake(snake_pos):
    for pos in snake_pos:
        pygame.draw.rect(screen,(0,255,0),pygame.Rect(pos[0],pos[1],10,10))
#all about collisions
'''
#collision with apple
def collision_with_apple(apple_pos,score):
    apple_pos=[random.randrange(1,45,10)*10,random.randrange(1,45,10)*10]
    score+=1
    return apple_pos,score
'''
#collison with boundaries
def collision_with_boundaries(snake_head):
    if snake_head[0]>=500 or snake_head[0]<0 or snake_head[1]>=500 or snake_head[1]<0 :
        return 1
    else:
        return 0

#collision with self
def collision_with_self(snake_pos):
    snake_head=snake_pos[0]
    if snake_head in snake_pos[1:]:
        return 1
    else:
        return 0

#collision with attacker
def collision_with_attacker(attaker_pos,snake_pos):
    if attaker_pos==snake_pos[0]:
        
        return 1
    else:
        return 0

#direction blocked
def isdirectionblocked(snake_pos,current_dir_vector):
    next_step=snake_pos[0]+current_dir_vector
    snake_head=snake_pos[0]
    if collision_with_boundaries(snake_head)==1 or collision_with_self(snake_pos)==1 :
        return 1
    else:
        return 0


#generating snake
def generate_snake(snake_head,snake_pos,apple_pos,button_direction,score,direction):
    
    if button_direction==1:
        snake_head[0]+=10
        
    elif button_direction==0:
        snake_head[0]-=10
        
    elif button_direction==2:
        snake_head[1]+=10
        
    elif button_direction==3:
        snake_head[1]-=10
        
    else:
        pass

    if direction==1:
        attaker_pos[0]+=10
    elif direction==2:
        attaker_pos[0]-=10
    elif direction==3:
        attaker_pos[1]+=10
    elif direction==4:
        attaker_pos[1]-=10
    else:
        pass
    
    
    
    
    
    '''
    if snake_head==apple_pos:
        snake_pos.insert(0,apple_pos)
        apple_pos,score=collision_with_apple(apple_pos,score)
    ''' 
    
    snake_pos.insert(0,list(snake_head))
    snake_pos.pop()
    return snake_pos,apple_pos,score,attaker_pos


#play game
def play_game(snake_head,snake_pos,apple_pos,button_direction,apple_image,score,attaker_pos):
    crashed=False
    prev_button_direction=1
    button_direction=1
    direction=1
    current_dir_vector=np.array(snake_pos[0])-np.array(snake_pos[1])
    while crashed is not True:
        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                crashed = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT and prev_button_direction != 1:
                    button_direction = 0
                    direction=random.randint(1,5)
                elif event.key == pygame.K_RIGHT and prev_button_direction != 0:
                    button_direction = 1
                    direction=random.randint(1,5)
                elif event.key == pygame.K_UP and prev_button_direction != 2:
                    button_direction = 3
                    direction=random.randint(1,5)
                elif event.key == pygame.K_DOWN and prev_button_direction != 3:
                    button_direction = 2
                    direction=random.randint(1,5)
                else:
                    button_direction = button_direction
        screen.fill((160,56,245))

      

        display_attackers(attaker_pos)
        display_apple(screen,apple_pos,apple_image)
        display_snake(snake_pos)
        snake_pos,apple_pos,score,attaker_pos=generate_snake(snake_head,snake_pos,apple_pos,button_direction,score,direction)
        
        if collision_with_attacker(attaker_pos,snake_pos):
            score +=10
            snake_pos.insert(0,attaker_pos)
            
        prev_button_direction=button_direction
        pygame.display.set_caption('snake_game'+'score : '+str(score))
        pygame.display.update()
        if isdirectionblocked(snake_pos,current_dir_vector):
            crashed=True
        clock.tick(10)
        
        
        #attacker boundary check

        if attaker_pos[0]>490 :
            
            attaker_pos[0]=10
        if attaker_pos[0]<0:
            attaker_pos[0]=490
            
        if attaker_pos[1]>490 :
            attaker_pos[1]=10
            
        if attaker_pos[1]<0:
            attaker_pos[1]=490
            
    return score
def display_final_score(display_text, final_score):
    largeText = pygame.font.Font('freesansbold.ttf',35)
    TextSurf = largeText.render(display_text, True, black)
    TextRect = TextSurf.get_rect()
    TextRect.center = ((500/2),(500/2))
    screen.blit(TextSurf, TextRect)
    pygame.display.update()
    time.sleep(2)
#main

if __name__=='__main__':


    
    pygame.init()
    red = (255,0,0)
    black = (0,0,0)
    clock=pygame.time.Clock()
    #initialize display
    screen_width=500
    screen_height=500
    screen=pygame.display.set_mode((screen_width,screen_height))
    screen.fill((0,0,0))
    pygame.display.set_caption('snake game created by fscty')
    pygame.display.update()


    #apple
    apple_image=pygame.image.load('dot1.png')
    apple_pos=[random.randrange(1,45,10)*10,random.randrange(1,45,10)*10]
    
    #attacker pos
    attaker_pos=[140,245]

    #snake
    snake_head=[250,250]
    snake_pos=[[250,250],[240,250],[230,250],[220,250],[210,250],[200,250],[190,250]]

    score=0
    final_score=play_game(snake_head,snake_pos,apple_pos,1,apple_image,score,attaker_pos)
    #updating all the thing in screen
    screen=pygame.display.set_mode((screen_width,screen_height))
    screen.fill((0,250,150))
    pygame.display.update()
    display_text = 'Your Score is: ' + str(final_score)
    display_final_score(display_text, final_score)
    pygame.quit()