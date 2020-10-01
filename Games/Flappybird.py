#!/usr/bin/env python3

"""Flappy Bird, implemented using Pygame."""

import math
import os
from random import randint

import pygame
from pygame.locals import *


FPS = 60
EVENT_NEWPIPE = USEREVENT + 1  # custom event
PIPE_ADD_INTERVAL = 3000       # milliseconds
FRAME_ANIMATION_WIDTH = 3      # pixels per frame
FRAME_BIRD_DROP_HEIGHT = 3     # pixels per frame
FRAME_BIRD_JUMP_HEIGHT = 5     # pixels per frame
BIRD_JUMP_STEPS = 20           # see get_frame_jump_height docstring
WIN_WIDTH = 284 * 2            # BG image size: 284x512 px; tiled twice
WIN_HEIGHT = 512
PIPE_WIDTH = 80
PIPE_PIECE_HEIGHT = BIRD_WIDTH = BIRD_HEIGHT = 32


class PipePair:
    """Represents an obstacle.

    A PipePair has a top and a bottom pipe, and only between them can
    the bird pass -- if it collides with either part, the game is over.

    Attributes:
    x: The PipePair's X position.  Note that there is no y attribute,
        as it will only ever be 0.
    surface: A pygame.Surface which can be blitted to the main surface
        to display the PipePair.
    top_pieces: The number of pieces, including the end piece, in the
        top pipe.
    bottom_pieces: The number of pieces, including the end piece, in
        the bottom pipe.
    """

    def __init__(self, surface, top_pieces, bottom_pieces):
        """Initialises a new PipePair with the given arguments.

        The new PipePair will automatically be assigned an x attribute of
        WIN_WIDTH.

        Arguments:
        surface: A pygame.Surface which can be blitted to the main
            surface to display the PipePair.  You are responsible for
            converting it, if desired.
        top_pieces: The number of pieces, including the end piece, which
            make up the top pipe.
        bottom_pieces: The number of pieces, including the end piece,
            which make up the bottom pipe.
        """
        self.x = WIN_WIDTH
        self.surface = surface
        self.top_pieces = top_pieces
        self.bottom_pieces = bottom_pieces
        self.score_counted = False

    @property
    def top_height_px(self):
        """Get the top pipe's height, in pixels."""
        return self.top_pieces * PIPE_PIECE_HEIGHT

    @property
    def bottom_height_px(self):
        """Get the bottom pipe's height, in pixels."""
        return self.bottom_pieces * PIPE_PIECE_HEIGHT

    def is_bird_collision(self, bird_position):
        """Get whether the bird crashed into a pipe in this PipePair.

        Arguments:
        bird_position: The bird's position on screen, as a tuple in
            the form (X, Y).
        """
        bx, by = bird_position
        in_x_range = bx + BIRD_WIDTH > self.x and bx < self.x + PIPE_WIDTH
        in_y_range = (by < self.top_height_px or
                      by + BIRD_HEIGHT > WIN_HEIGHT - self.bottom_height_px)
        return in_x_range and in_y_range


def load_images():
    """Load all images required by the game and return a dict of them.

    The returned dict has the following keys:
    background: The game's background image.
    bird-wingup: An image of the bird with its wing pointing upward.
        Use this and bird-wingdown to create a flapping bird.
    bird-wingdown: An image of the bird with its wing pointing downward.
        Use this and bird-wingup to create a flapping bird.
    pipe-end: An image of a pipe's end piece (the slightly wider bit).
        Use this and pipe-body to make pipes.
    pipe-body: An image of a slice of a pipe's body.  Use this and
        pipe-body to make pipes.
    """

    def load_image(img_file_name):
        """Return the loaded pygame image with the specified file name.

        This function looks for images in the game's images folder
        (./images/).  All images are converted before being returned to
        speed up blitting.

        Arguments:
        img_file_name: The file name (including its extension, e.g.
            '.png') of the required image, without a file path.
        """
        file_name = os.path.join('.', 'images', img_file_name)
        img = pygame.image.load(file_name)
        # converting all images before use speeds up blitting
        img.convert()
        return img

    return {'background': load_image('background.png'),
            'pipe-end': load_image('pipe_end.png'),
            'pipe-body': load_image('pipe_body.png'),            
            # images for animating the flapping bird -- animated GIFs are
            # not supported in pygame
            'bird-wingup': load_image('bird_wing_up.png'),
            'bird-wingdown': load_image('bird_wing_down.png')}


def get_frame_jump_height(jump_step):
    """Calculate how high the bird should jump in a particular frame.

    This function uses the cosine function to achieve a smooth jump:
    In the first and last few frames, the bird jumps very little, in the
    middle of the jump, it jumps a lot.
    After a completed jump, the bird will have jumped
    FRAME_BIRD_JUMP_HEIGHT * BIRD_JUMP_STEPS pixels high, thus jumping,
    on average, FRAME_BIRD_JUMP_HEIGHT pixels every step.

    Arguments:
    jump_step: Which frame of the jump this is, where one complete jump
        consists of BIRD_JUMP_STEPS frames.
    """
    frac_jump_done = jump_step / float(BIRD_JUMP_STEPS)
    return (1 - math.cos(frac_jump_done * math.pi)) * FRAME_BIRD_JUMP_HEIGHT


def random_pipe_pair(pipe_end_img, pipe_body_img):
    """Return a PipePair with pipes of random height.

    The returned PipePair's surface will contain one bottom-up pipe
    and one top-down pipe.  The pipes will have a distance of
    BIRD_HEIGHT*3.
    Both passed images are assumed to have a size of (PIPE_WIDTH,
    PIPE_PIECE_HEIGHT).

    Arguments:
    pipe_end_img: The image to use to represent a pipe's endpiece.
    pipe_body_img: The image to use to represent one horizontal slice
        of a pipe's body.
    """
    surface = pygame.Surface((PIPE_WIDTH, WIN_HEIGHT), SRCALPHA)
    surface.convert()   # speeds up blitting
    surface.fill((0, 0, 0, 0))
    max_pipe_body_pieces = int(
        (WIN_HEIGHT -            # fill window from top to bottom
        3 * BIRD_HEIGHT -        # make room for bird to fit through
        3 * PIPE_PIECE_HEIGHT) / # 2 end pieces and 1 body piece for top pipe
        PIPE_PIECE_HEIGHT        # to get number of pipe pieces
    )
    bottom_pipe_pieces = randint(1, max_pipe_body_pieces)
    top_pipe_pieces = max_pipe_body_pieces - bottom_pipe_pieces
    # bottom pipe
    for i in range(1, bottom_pipe_pieces + 1):
        surface.blit(pipe_body_img, (0, WIN_HEIGHT - i*PIPE_PIECE_HEIGHT))
    bottom_pipe_end_y = WIN_HEIGHT - bottom_pipe_pieces*PIPE_PIECE_HEIGHT
    surface.blit(pipe_end_img, (0, bottom_pipe_end_y - PIPE_PIECE_HEIGHT))
    # top pipe
    for i in range(top_pipe_pieces):
        surface.blit(pipe_body_img, (0, i * PIPE_PIECE_HEIGHT))
    top_pipe_end_y = top_pipe_pieces * PIPE_PIECE_HEIGHT
    surface.blit(pipe_end_img, (0, top_pipe_end_y))
    # compensate for added end pieces
    top_pipe_pieces += 1
    bottom_pipe_pieces += 1
    return PipePair(surface, top_pipe_pieces, bottom_pipe_pieces)


def main():
    """The application's entry point.

    If someone executes this module (instead of importing it, for
    example), this function is called.
    """

    pygame.init()

    display_surface = pygame.display.set_mode((WIN_WIDTH, WIN_HEIGHT))
    pygame.display.set_caption('Pygame Flappy Bird')

    clock = pygame.time.Clock()

    score_font = pygame.font.SysFont(None, 32, bold=True)  # default font

    # the bird stays in the same x position, so BIRD_X is a constant
    BIRD_X = 50
    bird_y = int(WIN_HEIGHT/2 - BIRD_HEIGHT/2)  # center bird on screen

    images = load_images()

    # timer for adding new pipes
    pygame.time.set_timer(EVENT_NEWPIPE, PIPE_ADD_INTERVAL)
    pipes = []

    steps_to_jump = 2
    score = 0
    done = paused = False
    while not done:
        for e in pygame.event.get():
            if e.type == QUIT or (e.type == KEYUP and e.key == K_ESCAPE):
                done = True
                break
            elif e.type == KEYUP and e.key in (K_PAUSE, K_p):
                paused = not paused
            elif e.type == MOUSEBUTTONUP or (e.type == KEYUP and
                    e.key in (K_UP, K_RETURN, K_SPACE)):
                steps_to_jump = BIRD_JUMP_STEPS
            elif e.type == EVENT_NEWPIPE:
                pp = random_pipe_pair(images['pipe-end'], images['pipe-body'])
                pipes.append(pp)

        clock.tick(FPS)
        if paused:
            continue  # don't draw anything

        for x in (0, WIN_WIDTH / 2):
            display_surface.blit(images['background'], (x, 0))

        for p in pipes:
            p.x -= FRAME_ANIMATION_WIDTH
            if p.x <= -PIPE_WIDTH:  # PipePair is off screen
                pipes.remove(p)
            else:
                display_surface.blit(p.surface, (p.x, 0))

        # calculate position of jumping bird
        if steps_to_jump > 0:
            bird_y -= get_frame_jump_height(BIRD_JUMP_STEPS - steps_to_jump)
            steps_to_jump -= 1
        else:
            bird_y += FRAME_BIRD_DROP_HEIGHT

        # because pygame doesn't support animated GIFs, we have to
        # animate the flapping bird ourselves
        if pygame.time.get_ticks() % 500 >= 250:
            display_surface.blit(images['bird-wingup'], (BIRD_X, bird_y))
        else:
            display_surface.blit(images['bird-wingdown'], (BIRD_X, bird_y))

        # update and display score
        for p in pipes:
            if p.x + PIPE_WIDTH < BIRD_X and not p.score_counted:
                score += 1
                p.score_counted = True

        score_surface = score_font.render(str(score), True, (255, 255, 255))
        score_x = WIN_WIDTH/2 - score_surface.get_width()/2
        display_surface.blit(score_surface, (score_x, PIPE_PIECE_HEIGHT))

        pygame.display.update()

        # check for collisions
        pipe_collisions = [p.is_bird_collision((BIRD_X, bird_y)) for p in pipes]
        if (0 >= bird_y or bird_y >= WIN_HEIGHT - BIRD_HEIGHT or
                True in pipe_collisions):
            print('You crashed! Score: %i' % score)
            break
    pygame.quit()


if __name__ == '__main__':
    # If this module had been imported, __name__ would be 'flappybird'.
    # It was executed (e.g. by double-clicking the file), so call main.
    main()
