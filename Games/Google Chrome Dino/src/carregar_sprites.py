import pygame, pathlib

def carregar_imagem(imagem: str):
    return pygame.image.load(str(pathlib.Path(__file__).parent.absolute()) + "/sprites/" + imagem)
