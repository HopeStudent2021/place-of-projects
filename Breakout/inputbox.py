

import pygame, pygame.font, pygame.event, pygame.draw
from pygame.locals import *
import sys


def get_key(game=None):
    while 1:
        for event in game.continue_pygame_loop():
            if event.type == KEYDOWN:
                return event.key
            elif event.type == pygame.QUIT:
                game.game_over = True
                pygame.quit()
                sys.exit()
            else:
                pass


def display_box(screen, message, error=None):
    """
    Функция display_box() нужна для печати сообщения в окне в середине экрана

    """
    fontobject2 = pygame.font.Font(None, 60)
    pygame.draw.rect(screen, (0, 0, 0),
                     ((screen.get_width() / 2) + 50,
                      (screen.get_height() / 2) - 20,
                      200, 60), 0)
    pygame.draw.rect(screen, (255, 255, 255),
                     ((screen.get_width() / 2) + 50,
                      (screen.get_height() / 2) - 22,
                      202, 64), 1)
    if len(message) != 0:
        screen.blit(fontobject2.render(message, 1, (255, 255, 255)),
                    ((screen.get_width() / 2) - 200, (screen.get_height() / 2) - 10))

    screen.blit(fontobject2.render('<ENTER> для продолжения', 1, (0, 0, 0)),
                ((screen.get_width() / 2) - 230, (screen.get_height() / 2) + 70))


    screen.blit(fontobject2.render('Напишите сложность игры', 1, (0, 0, 0)),
                ((screen.get_width() / 2) - 200, (int(screen.get_height() / 3))))
    screen.blit(fontobject2.render('(0 - новичок, 10 - профи)', 1, (0, 0, 0)),
                ((screen.get_width() / 2) - 200, (int(screen.get_height() / 3) + 45)))

    if error:
        screen.blit(fontobject2.render(error, 1, (255, 0, 0)),
                    ((screen.get_width() / 2) - 120, 50))

    pygame.display.flip()


def ask(screen, error=None, game=None):
    "ask(screen, question) -> answer"
    question = 'Сложность'
    pygame.font.init()
    current_string = []
    display_box(screen, question + ": " + ''.join(current_string), error=error)
    while 1:
        inkey = get_key(game=game)
        if inkey == K_BACKSPACE:
            current_string = current_string[0:-1]
        elif inkey in (pygame.K_RETURN, 271, K_RETURN):
            break
        elif inkey == K_MINUS:
            current_string.append("_")
        elif inkey <= 127:
            if chr(inkey).isdigit():
                current_string.append(chr(inkey))
        display_box(screen, question + ": " + ''.join(current_string))
    return ''.join(current_string)



