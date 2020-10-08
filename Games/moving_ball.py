import pygame
pygame.init()
screen = pygame.display.set_mode((1000,500))
red = 22, 70, 70
screen.fill(red)
moveX = 1
moveY = 1
x = 100
y = 100
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()
    pygame.draw.circle(screen, (111, 200, 30), (x, y), 80)
    pygame.display.update()
    screen.fill(red)
    x += moveX
    y += moveY
    if x > 1000-50:
        moveX =- 1
    elif y > 500-50:
        moveY =- 1
    elif x < 50:
        moveX = 1
    elif y < 50:
        moveY = 1
