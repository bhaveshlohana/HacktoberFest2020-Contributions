import random
import pygame
from pygame.locals import *
img = "1.jpg"
imgw=682
imgh=521
width=imgw
height=imgh
boxw = imgw/4
boxh = imgh/3
COLUMNS = 4
ROWS = 3
bbox = (COLUMNS-1, ROWS-1)   
BLACK = (0, 0, 0)
image = pygame.image.load(img)
image=pygame.transform.scale(image,(imgw,imgh))
solution = False
boardercolour=(0,0,0)
boxes = {}
for c in range(COLUMNS) :
    for r in range(ROWS) :
        box = image.subsurface(c*boxw, r*boxh,boxw,boxh)
        boxes [(c, r)] = box
boxes[bbox].fill(BLACK)
state = {(col, row): (col, row) for col in range(COLUMNS) for row in range(ROWS)}
win={(0, 0): (0, 0), (0, 1): (0, 1), (0, 2): (0, 2), (1, 0): (1, 0), (1, 1): (1, 1), (1, 2): (1, 2), (2, 0): (2, 0), (2, 1): (2, 1), (2, 2): (2, 2), (3, 0): (3, 0), (3, 1): (3, 1), (3, 2): (3, 2)}
(ec, er) = bbox
pygame.init()
screen = pygame.display.set_mode((width,height))
pygame.display.set_caption("Image Puzzle")
screen.blit (image, (0,0))
pygame.draw.rect(screen,(boardercolour),(0,0,imgw,imgh),3)
pygame.draw.rect(screen,(boardercolour),(0,0,boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),(boxw,0,boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),((boxw+boxw),0,boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),0,boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),(0,boxh,boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),(boxw,boxh,boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),((boxw+boxw),boxh,boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),boxh,boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),(0,(boxh+boxh),boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),(boxw,(boxh+boxh),boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),((boxw+boxw),(boxh+boxh),boxw,boxh),3)
pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),(boxh+boxh),boxw,boxh),3)
pygame.display.update()
def shift(c,r) :
    global ec,er 
    screen.blit(boxes[state[(c, r)]],(ec*boxw, er*boxh))
    screen.blit(boxes[bbox],(c*boxw, r*boxh))
    state[(ec,er)] = state[(c,r)]
    state[(c,r)] = bbox
    (ec,er) = (c,r)
    pygame.draw.rect(screen,(boardercolour),(0,0,imgw,imgh),3)
    pygame.draw.rect(screen,(boardercolour),(0,0,boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),(boxw,0,boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),((boxw+boxw),0,boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),0,boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),(0,boxh,boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),(boxw,boxh,boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),((boxw+boxw),boxh,boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),boxh,boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),(0,(boxh+boxh),boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),(boxw,(boxh+boxh),boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),((boxw+boxw),(boxh+boxh),boxw,boxh),3)
    pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),(boxh+boxh),boxw,boxh),3) 
    pygame.display.update()
def shuffle():
    global ec,er
    ls = 0 
    for i in range(40):
        pygame.time.delay(80)
        while True:
            r = random.randint(1, 4)
            #1=l,4=r,2=u,3=d
            if (ls + r == 5):
                continue
            if r == 1 and (ec > 0):
                shift(ec - 1, er)
            elif r == 4 and (ec < COLUMNS - 1):
                shift(ec + 1, er) 
            elif r == 2 and (er > 0):
                shift(ec, er - 1)
            elif r == 3 and (er < ROWS - 1):
                shift(ec, er + 1) 
            else:
                continue
            ls=r
            break
font = pygame.font.SysFont("Arial", 80)
won = font.render("Well Played", 1, (192,1,192))
start = True
end = False
run =1
while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            run=0
        elif end:
            screen.blit(won,((width/(1/2)),(height/(1/2))))
        elif event.type == pygame.MOUSEBUTTONDOWN :
            if start:
                shuffle()
                start = False
            elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                mx,my = pygame.mouse.get_pos()
                c= int(mx/boxw)
                r = int(my/boxh)
                if((abs(c-ec)==1 and r==er)or(abs(r-er)==1 and c==ec)):
                    shift(c,r)
                if(state==win):
                    end=True
                    print("1")
            elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 3:
                simage = screen.copy()
                screen.blit(image,(0,0))
                pygame.draw.rect(screen,(boardercolour),(0,0,imgw,imgh),3)
                pygame.draw.rect(screen,(boardercolour),(0,0,boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),(boxw,0,boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),((boxw+boxw),0,boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),0,boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),(0,boxh,boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),(boxw,boxh,boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),((boxw+boxw),boxh,boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),boxh,boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),(0,(boxh+boxh),boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),(boxw,(boxh+boxh),boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),((boxw+boxw),(boxh+boxh),boxw,boxh),3)
                pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),(boxh+boxh),boxw,boxh),3)
                pygame.display.update()
                solution = True
        elif solution and (event.type == pygame.MOUSEBUTTONUP):
            screen.blit (simage, (0,0))
            pygame.draw.rect(screen,(boardercolour),(0,0,imgw,imgh),3)
            pygame.draw.rect(screen,(boardercolour),(0,0,boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),(boxw,0,boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),((boxw+boxw),0,boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),0,boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),(0,boxh,boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),(boxw,boxh,boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),((boxw+boxw),boxh,boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),boxh,boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),(0,(boxh+boxh),boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),(boxw,(boxh+boxh),boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),((boxw+boxw),(boxh+boxh),boxw,boxh),3)
            pygame.draw.rect(screen,(boardercolour),((boxw+boxw+boxw),(boxh+boxh),boxw,boxh),3)
            pygame.display.update()
            solution = False
pygame.quit()
