import pygame

from carregar_sprites import carregar_imagem

class Dino(pygame.sprite.Sprite):

    def __init__(self, x=200, y=200):
        super(Dino, self).__init__()
     
        self.images = [
            [
                carregar_imagem('dino1.png'),
                carregar_imagem('dino2.png'),
                carregar_imagem('dino3.png')
            ],
            [
                carregar_imagem('dino4.png'),
                carregar_imagem('dino5.png')
            ],
            [
                carregar_imagem('dino_morto.png')
            ]            
        ]
        self.set = 0
        self.index = 0
        self.image = self.images[0][self.index]

        self.velocidade_x = 0
        self.velocidade_y = 0
        self.x = x
        self.y = y
        self.rect = pygame.rect.Rect(self.x, self.y, 44, 47)

        self.vivo = True
        self.pulando = False
        self.abaixado = False


    def update(self):
        self.rect.move_ip(self.velocidade_x, self.velocidade_y)

        if(self.velocidade_x != 0):
            self.index += 1
            if self.index == len(self.images[self.set]):
                self.index = 0
            self.image = self.images[self.set][self.index]

    def stop(self):
        self.velocidade_x = 0

        if self.set == 1:
            x = self.rect.left
            y = self.rect.top - 17
            self.rect = pygame.rect.Rect(x, y, 44, 27)

        self.index = 0
        self.set = 0
        self.image = self.images[self.set][self.index]

    def colisao(self, sprite: pygame.sprite.Sprite):
        return self.rect.colliderect(sprite.rect)

    def animar_morte(self):
        self.velocidade_x = 0
        self.set = 2
        self.index = 0
        self.image = self.images[self.set][self.index]

    def abaixar(self):
        x = self.rect.left
        y = self.rect.top + 17
        self.set = 1
        self.index = 0
        self.rect = pygame.rect.Rect(x, y, 59, 30)
        self.image = self.images[self.set][self.index]