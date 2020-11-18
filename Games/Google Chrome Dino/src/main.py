import pygame

from dino import Dino
from voador import Voador
from carregar_sprites import carregar_imagem

tela = pygame.display.set_mode((600,300))
pygame.display.set_caption("Google Chrome Dino Game")

clock = pygame.time.Clock()
fps = 15

dino = Dino()
sprites_dino = pygame.sprite.Group(dino)

voador = Voador()
sprites_voador = pygame.sprite.Group(voador)

chao = carregar_imagem('chao.png')
game_over = carregar_imagem('game_over.png')

EVENTO_MORRER = pygame.USEREVENT + 1

executando = True
while executando:
    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            executando = False
        
        if evento.type == EVENTO_MORRER:
            dino.vivo = False

        if dino.vivo:
            if evento.type == pygame.KEYDOWN:
                if evento.key == pygame.K_LEFT:
                    dino.velocidade_x = -10
                if evento.key == pygame.K_RIGHT:
                    dino.velocidade_x = 10
                if evento.key == pygame.K_DOWN:
                    dino.abaixar()
            if evento.type == pygame.KEYUP:
                if evento.key in [pygame.K_LEFT, pygame.K_RIGHT, pygame.K_DOWN]:
                    dino.stop()


    tela.fill((255,255,255))
    tela.blit(chao, [0,235])

    if dino.colisao(voador):
        if dino.vivo:
            print('GAME OVER')
            dino.animar_morte()
            pygame.time.set_timer(EVENTO_MORRER, 100)
            
    sprites_dino.update()
    sprites_dino.draw(tela)

    if dino.vivo:
        sprites_voador.update()
        sprites_voador.draw(tela)
    else:
        tela.blit(game_over, [200,100])

    clock.tick(fps)
    pygame.display.flip()

pygame.quit()