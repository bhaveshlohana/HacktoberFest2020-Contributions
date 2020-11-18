import pygame

from carregar_sprites import carregar_imagem

class Voador(pygame.sprite.Sprite):

    def __init__(self, x=600, y=180):
        super(Voador, self).__init__()
     
        self.images = [
            carregar_imagem('voador1.png'),
            carregar_imagem('voador2.png')
        ]
        self.index = 0
        self.image = self.images[self.index]

        self.velocidade_x = -10
        self.velocidade_y = 0
        self.x = x
        self.y = y
        self.rect = pygame.rect.Rect(self.x, self.y, 43, 34)

    def update(self):
        self.rect.move_ip(self.velocidade_x, self.velocidade_y)
        
        if self.rect.left < -10:
            self.rect = pygame.rect.Rect(self.x, self.y, 43, 34)

        if(self.velocidade_x != 0):
            self.index += 1
            if self.index == len(self.images):
                self.index = 0
            self.image = self.images[self.index]

    def stop(self):
        self.velocidade_x = 0
        self.index = 0
        self.image = self.images[self.index]