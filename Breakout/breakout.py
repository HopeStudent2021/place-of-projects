# Подключение всех библиотек
import random
from datetime import datetime, timedelta

import sys
import time
import pygame
import threading
from pygame.rect import Rect
import config as c
from objects import Ball, Brick, Button, Paddle, TextObject
import colors
from collections import defaultdict
from inputbox import ask


class Game:
    """
    class Game - ядро игры
    """

    def __init__(self, caption, width, height, back_image_filename, frame_rate):
        """
        Фунцкия __init__() инициализирует сам Pygame, систему шрифтов
         и звуковой микшер и создаёт фоновое изображение,
         основную поверхность (на которой всё отрисовывается) и игровой таймер с правильной частотой кадров.
        """
        self.background_image = pygame.image.load(back_image_filename)
        self.frame_rate = frame_rate
        self.game_over = False
        self.objects = []
        pygame.mixer.pre_init(44100, 16, 2, 4096)
        pygame.init()
        pygame.font.init()
        self.surface = pygame.display.set_mode((width, height))
        pygame.display.set_caption(caption)
        self.clock = pygame.time.Clock()
        self.keydown_handlers = defaultdict(list)
        self.keyup_handlers = defaultdict(list)
        self.mouse_handlers = []

    def update(self):
        """
        Функция update() нужна для обновления всех объектов
        """
        for o in self.objects:
            o.update()

    def draw(self):
        """
        Функция draw() нужна для отрисовки всех объектов
        """
        for o in self.objects:
            o.draw(self.surface)

    def handle_events(self):
        """
        Функция handle_events() обрабатывает события, генерируемые Pygame, такие как события клавиш и мыши
        """
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.game_over = True
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                for handler in self.keydown_handlers[event.key]:
                    handler(event.key)
            elif event.type == pygame.KEYUP:
                for handler in self.keydown_handlers[event.key]:
                    handler(event.key)
            elif event.type in (pygame.MOUSEBUTTONDOWN, pygame.MOUSEBUTTONUP, pygame.MOUSEMOTION):
                for handler in self.mouse_handlers:
                    handler(event.type, event.pos)

    def run(self):
        """
        Функция run() выполняет основной цикл.
        Он выполняется до тех пор, пока элемент game_over не принимает значение True.

        """
        while not self.game_over:
            self.surface.blit(self.background_image, (0, 0))

            self.handle_events()
            self.update()
            self.draw()

            pygame.display.update()
            self.clock.tick(self.frame_rate)

# Эффекты для объектов
special_effects = dict(
    # Увеличение ракетки(paddle) на 50% при ударе мяча об оранжеывый кирпич
    long_paddle=(colors.ORANGE,
                 lambda g: g.paddle.bounds.inflate_ip(c.paddle_width // 2, 0),
                 lambda g: g.paddle.bounds.inflate_ip(-c.paddle_width // 2, 0)),
    # Замедление мяча на 1 при ударе о кирпич цвета AQUAMARINE2
    slow_ball=(colors.AQUAMARINE2,
               lambda g: g.change_ball_speed(-1),
               lambda g: g.change_ball_speed(1)),
    # Добавление 5 очков при попадании мяча по кирпичу цвета DARKSEAGREEN4
    tripple_points=(colors.DARKSEAGREEN4,
                    lambda g: g.set_points_per_brick(5),
                    lambda g: g.set_points_per_brick(1)),
    # Добавление одной жизни при ударе мяча о золотой кирпич
    extra_life=(colors.GOLD1,
                lambda g: g.add_life(),
                lambda g: None))



class Breakout(Game):
    def __init__(self):
        Game.__init__(self, 'Breakout', c.screen_width, c.screen_height, c.background_image, c.frame_rate)
        self.reset_effect = None
        self.effect_start_time = None
        self.score = 0
        self.lives = c.initial_lives
        self.start_level = False
        self.paddle = None
        self.bricks = None
        self.ball = None
        self.menu_buttons = []
        self.is_game_running = False
        self.create_objects()
        self.points_per_brick = 1
        self.pause = None
        self.env = None

    def add_life(self):
        self.lives += 1

    def set_points_per_brick(self, points):
        self.points_per_brick = points

    def change_ball_speed(self, dy):
        self.ball.speed = (self.ball.speed[0], self.ball.speed[1] + dy)

    def change_paddle_speed(self, dy):
        self.paddle.offset = dy

    def create_menu(self):
        """
        Функция create_menu() создаёт меню с двумя кнопками с текстом 'Играть' и 'Выход'.
        """
        def on_play(button):
            for b in self.menu_buttons:
                self.objects.remove(b)

            try:
                complexity = int(ask(self.surface, game=self))
            except ValueError:
                complexity = -1

            while not 0 <= complexity <= 10:
                try:
                    complexity = int(ask(self.surface, game=self, error='Write number in range [0; 10]'))
                except ValueError:
                    complexity = -1
            k_comp = complexity*0.1 + 1
            self.ball.speed = self.ball.speed[0], k_comp * c.ball_speed
            c.ball_speed = self.ball.speed[1]

            self.paddle.speed = (2-k_comp) * c.paddle_speed

            self.is_game_running = True
            self.start_level = True

        def on_quit(button):
            self.game_over = True
            self.is_game_running = False
            self.game_over = True


        for i, (text, click_handler) in enumerate((('Играть', on_play), ('Выход', on_quit))):
            b = Button(c.menu_offset_x,
                       c.menu_offset_y + (c.menu_button_h + 5) * i,
                       c.menu_button_w,
                       c.menu_button_h,
                       text,
                       click_handler,
                       padding=5)
            self.objects.append(b)
            self.menu_buttons.append(b)
            self.mouse_handlers.append(b.handle_mouse_event)

    def create_objects(self):
        self.create_bricks()
        self.create_paddle()
        self.create_ball()
        self.create_labels()
        self.create_menu()

    def continue_pygame_loop(self):
        if self.env is None:
            return pygame.event.get()
        return self.env.events

    def create_labels(self):
        self.score_label = TextObject(c.score_offset,
                                      c.status_offset_y,
                                      lambda: f'Счёт: {self.score}',
                                      c.text_color,
                                      c.font_name,
                                      c.font_size)
        self.objects.append(self.score_label)
        self.lives_label = TextObject(c.lives_offset,
                                      c.status_offset_y,
                                      lambda: f'Жизни: {self.lives}',
                                      c.text_color,
                                      c.font_name,
                                      c.font_size)
        self.objects.append(self.lives_label)

    def create_ball(self):
        speed = (random.randint(-2, 2), c.ball_speed)
        self.ball = Ball(c.screen_width // 2,
                         c.screen_height // 2,
                         c.ball_radius,
                         c.ball_color,
                         speed)
        self.objects.append(self.ball)
        self.pause = c.pause_ball * c.frame_rate

    def create_paddle(self):
        """
        Функция create_paddle() нужна для регистрации метода handle() ракетки для обработки событий клавиш
        """
        paddle = Paddle((c.screen_width - c.paddle_width) // 2,
                        c.screen_height - c.paddle_height * 2,
                        c.paddle_width,
                        c.paddle_height,
                        c.paddle_color,
                        c.paddle_speed)
        self.keydown_handlers[pygame.K_LEFT].append(paddle.handle)
        self.keydown_handlers[pygame.K_RIGHT].append(paddle.handle)
        self.keyup_handlers[pygame.K_LEFT].append(paddle.handle)
        self.keyup_handlers[pygame.K_RIGHT].append(paddle.handle)
        self.paddle = paddle
        self.objects.append(self.paddle)

    def create_bricks(self):
        w = c.brick_width
        h = c.brick_height
        brick_count = c.screen_width // (w + 1)
        offset_x = (c.screen_width - brick_count * (w + 1)) // 2

        bricks = []
        for row in range(c.row_count):
            for col in range(brick_count):
                effect = None
                brick_color = c.brick_color
                index = random.randint(0, 10)
                if index < len(special_effects):
                    brick_color, start_effect_func, reset_effect_func = list(special_effects.values())[index]
                    effect = start_effect_func, reset_effect_func

                brick = Brick(offset_x + col * (w + 1),
                              c.offset_y + row * (h + 1),
                              w,
                              h,
                              brick_color,
                              effect)
                bricks.append(brick)
                self.objects.append(brick)
        self.bricks = bricks

    def handle_ball_collisions(self):
        def intersect(obj, ball):
            """
            Функция intersect() используется для проверки того,
             ударился ли мяч об объект, и того, где он столкнулся с объектом.
            """
            edges = dict(left=Rect(obj.left, obj.top, 1, obj.height),
                         right=Rect(obj.right, obj.top, 1, obj.height),
                         top=Rect(obj.left, obj.top, obj.width, 1),
                         bottom=Rect(obj.left, obj.bottom, obj.width, 1))
            collisions = set(edge for edge, rect in edges.items() if ball.bounds.colliderect(rect))
            if not collisions:
                return None

            if len(collisions) == 1:
                return list(collisions)[0]

            if 'top' in collisions:
                if ball.centery >= obj.top:
                    return 'top'
                if ball.centerx < obj.left:
                    return 'left'
                else:
                    return 'right'

            if 'bottom' in collisions:
                if ball.centery >= obj.bottom:
                    return 'bottom'
                if ball.centerx < obj.left:
                    return 'left'
                else:
                    return 'right'

        self.ball.color = colors.GOLD1

        flag = False

        # Столкновение мяча с ракеткой
        s = self.ball.speed
        edge = intersect(self.paddle, self.ball)
        if edge is not None:
            self.ball.color = colors.ORANGERED3
        if edge == 'top':
            speed_x = s[0]
            speed_y = -s[1]
            if self.paddle.moving_left:
                speed_x -= 1
            elif self.paddle.moving_right:
                speed_x += 1
            self.ball.speed = speed_x, speed_y
        elif edge in ('left', 'right'):
            self.ball.speed = (-s[0], s[1])

        # Столкновение с потолком
        if self.ball.top <= 0:
            self.ball.color = colors.RED2
            flag = True
            self.ball.speed = (s[0], -s[1])

        # Столкновение с полом
        if self.ball.top >= c.screen_height:
            flag = True
            self.lives -= 1
            if self.lives == 0:
                self.game_over = True
            else:
                self.create_ball()

        # Столкновение со стенами
        if (self.ball.left <= 0 or self.ball.right >= c.screen_width) and not flag:
            self.ball.color = colors.RED1
            self.ball.speed = (-s[0], s[1])

        # Столкновение с кирпичами
        for brick in self.bricks:
            edge = intersect(brick, self.ball)
            if not edge:
                continue

            self.bricks.remove(brick)
            self.ball.color = colors.RED1
            self.objects.remove(brick)
            self.score += self.points_per_brick

            if edge in ('top', 'bottom'):
                self.ball.speed = (s[0], -s[1])
            else:
                self.ball.speed = (-s[0], s[1])

            if brick.special_effect is not None:
                # Сброс предыдущего эффекта, если таковой имеется
                if self.reset_effect is not None:
                    self.reset_effect(self)

                # Запуск специального эффекта
                self.effect_start_time = datetime.now()
                brick.special_effect[0](self)
                # Сброс специального эффекта
                self.reset_effect = brick.special_effect[1]

    def update(self):
        if not self.is_game_running:
            return

        if self.start_level:
            self.start_level = False
            self.show_message('Приготовьтесь!', centralized=True)

        if not self.bricks:
            self.show_message('Победа!!!', centralized=True)
            self.is_game_running = False
            self.game_over = True
            return

        if self.pause:
            self.pause -= 1
            self.paddle.update()
            self.paddle.draw(self.surface)
            return

        # Сброс спец. эффекта по необходимости
        if self.reset_effect:
            if datetime.now() - self.effect_start_time >= timedelta(seconds=c.effect_duration):
                self.reset_effect(self)
                self.reset_effect = None

        self.handle_ball_collisions()
        super().update()

        if self.game_over:
            self.show_message('Игра окончена!', centralized=True)

    def show_message(self, text, color=colors.GRAY7, font_name='Arial', font_size=70, centralized=False):
        """
        Функция show_message() нужна для обработки событий таймера

        """
        message = TextObject(c.screen_width // 2, c.screen_height // 2 + 100, lambda: text, color, font_name, font_size)
        self.draw()
        message.draw(self.surface, centralized)
        pygame.display.update()
        time.sleep(c.message_duration)

    def game(self, env):
        self.env = env
        for b in self.menu_buttons:
            self.objects.remove(b)

        try:
            complexity = int(ask(self.surface, game=self))
        except ValueError:
            complexity = -1

        while not 0 <= complexity <= 10:
            try:
                complexity = int(ask(self.surface, game=self, error='Write number in range [0; 10]'))
            except ValueError:
                complexity = -1
        k_comp = complexity * 0.1 + 1
        self.ball.speed = self.ball.speed[0], k_comp * c.ball_speed
        c.ball_speed = self.ball.speed[1]

        self.paddle.speed = (2 - k_comp) * c.paddle_speed

        self.is_game_running = True
        self.start_level = True

        while not self.is_game_running:
            self.surface.blit(self.background_image, (0, 0))

            self.handle_events()
            self.update()
            self.draw()

            pygame.display.update()
            self.clock.tick(self.frame_rate)

        while not self.game_over:
            for event in self.continue_pygame_loop():
                if event.type == pygame.QUIT:
                    self.game_over = True
                    self.is_game_running = False
                    pygame.quit()
                    sys.exit()
            if env.new_step:
                self.surface.blit(self.background_image, (0, 0))

                if env.action == 0:
                    self.paddle.moving_left = True
                    self.paddle.moving_right = False
                elif env.action == 1:
                    self.paddle.moving_right = True
                    self.paddle.moving_left = False
                else:
                    self.paddle.moving_right = False
                    self.paddle.moving_left = False

                self.update()
                self.draw()

                pygame.display.update()
                self.clock.tick(self.frame_rate)

                env.new_step = False
        pygame.quit()
        sys.exit()


class BreakoutEnv:
    def __init__(self):
        self.episodes = 0
        self.steps = 0
        self.new_step = False
        self.action = None
        self.state = None

        self.breakout = None
        self.breakout_game = None
        
        self.events = []

    def step(self, action):
        if self.breakout is None:
            raise EnvironmentError('You must run reset() before running step()')
        self.steps += 1
        self.new_step = True
        self.action = action

    def reset(self):
        self.episodes += 1
        self.steps = 0
        self.breakout = Breakout()

        self.breakout_game = threading.Thread(target=self.breakout.game, args=(self, ))
        self.breakout_game.start()

def main():
    Breakout().run()


if __name__ == '__main__':
    main()
