#!/usr/bin/env python3
# encoding: utf-8

"""
 游戏主逻辑 & 入口类
 Created by plough on 2023/4/30.
"""
import sys
import pygame
from pygame.locals import *
from cons import *

# from core.game_board import GameBoard
from coreCode.game_state import GameState
# from core.snake import Snake
# from libs.direction_manager import DirectionManager
# from libs.lock import SimpleLock
# from libs.sound_manager import sound_manager

############sound_manager
# 管理声音的类
import os

import pygame

class SoundManager:
    music_path = os.path.join('res', 'background.mp3')

    def __init__(self):
        self._init_music()
        self.sound_eat = self._load_sound('eat.ogg')
        self.sound_fail = self._load_sound('gameover.ogg')
        self.sound_cheer = self._load_sound('cheer.ogg')

    # 背景音乐
    @classmethod
    def _init_music(cls):
        pygame.mixer.init()
        pygame.mixer.music.load(cls.music_path)
        pygame.mixer.music.set_volume(0.2)
        pygame.mixer.music.play(-1)

    @staticmethod
    def _load_sound(file_name):
        return pygame.mixer.Sound(os.path.join('res', file_name))

    @staticmethod
    def replay_music():
        pygame.mixer.music.rewind()
        pygame.mixer.music.unpause()

    @staticmethod
    def pause_music():
        pygame.mixer.music.pause()

    @staticmethod
    def resume_music():
        pygame.mixer.music.unpause()

    def play_eat_sound(self):
        self.sound_eat.play()

    def play_fail_sound(self):
        self.sound_fail.play()

    def play_cheer_sound(self):
        self.sound_cheer.play()

# 单例模式
sound_manager = SoundManager()
############lock
"""

 Created by plough on 2023/4/30.
"""

class SimpleLock:

    def __init__(self):
        self.locked = False


    def unlock(self):
        if self.locked:
            self.locked = False

    def is_locked(self):
        return self.locked

    def lock(self):
        self.locked = True




#############direction_manager

from pygame.constants import *

from cons import *


class DirectionManager:
    directions = {
        'left': [-1, 0],
        'right': [1, 0],
        'up': [0, -1],
        'down': [0, 1]
    }

    @staticmethod
    def flip_direction(direction):
        if direction == 'left':
            return 'right'
        if direction == 'right':
            return 'left'
        if direction == 'up':
            return 'down'
        if direction == 'down':
            return 'up'


    @staticmethod
    def back_one_step(direction, x, y, min_x = 0, max_x = COLUMNS - 1, min_y = 0, max_y = ROWS - 1):
        direction = DirectionManager.flip_direction(direction)
        return DirectionManager.move_one_step(direction, x, y, min_x, max_x, min_y, max_y)


    @classmethod
    def move_one_step(cls, direction, x, y, min_x = 0, max_x = COLUMNS - 1, min_y = 0, max_y = ROWS - 1):
        step = DirectionManager.directions[direction]
        x += step[0]
        y += step[1]

        # 边界检查
        if x < min_x:
            x = max_x
        elif x > max_x:
            x = min_x
        if y < min_y:
            y = max_y
        elif y > max_y:
            y = min_y

        return x, y

    @staticmethod
    def get_direction_by_key(key):
        direction = ''
        if key in (K_DOWN, K_s):
            direction = 'down'
        elif key in (K_UP, K_w):
            direction = 'up'
        elif key in (K_LEFT, K_a):
            direction = 'left'
        elif key in (K_RIGHT, K_d):
            direction = 'right'
        return direction


    @staticmethod
    def is_valid_direction(current_direction, new_direction):
        if current_direction in ['up', 'down'] and new_direction in ['left', 'right']:
            return True
        elif current_direction in ['right', 'left'] and new_direction in ['up', 'down']:
            return True
        else:
            return False


#!/usr/bin/env python3
# encoding: utf-8
import pygame

from cons import *
from libs.direction_manager import DirectionManager
from libs.food_manager import food_manager
from libs.sound_manager import sound_manager
from libs.sprite import BaseSprite


class Snake(BaseSprite):

    INIT_LENGTH = 3
    INIT_HEAD_POS = (5, 3)
    INIT_DIRECTION = 'right'


    def __init__(self):
        # 监听者模式
        self.eat_food_listeners = []

        self.direction = self.INIT_DIRECTION
        self.body_list = self.init_body_list()  # 存储蛇身所在坐标


    def reset(self):
        self.direction = self.INIT_DIRECTION
        self.body_list = self.init_body_list()


    # def init_body_list(self):
    #     # 获取蛇头的初始位置
    #     x, y = self.INIT_HEAD_POS
    #     # 创建一个空列表，用于存储蛇的身体坐标
    #     body_list = []
    #     # 循环添加蛇身体的每一节
    #     for i in range(self.INIT_LENGTH):
    #         # 将当前位置添加到身体列表中
    #         body_list.append((x, y))
    #         # 计算下一节身体的位置
    #         x, y = DirectionManager.back_one_step(self.direction, x, y)
    #     # 返回身体列表
    #     return body_list
    
    def init_body_list(self):
        x, y = self.INIT_HEAD_POS
        return [(x, y)] + [DirectionManager.back_one_step(self.direction, x, y) for i in range(1, self.INIT_LENGTH)]



    @property
    def head_pos(self):
        return self.body_list[0]


    def register_eat_food_listener(self, listener):
        self.eat_food_listeners.append(listener)


    # 传入表示方向的字符串
    def set_direction(self, new_direction):
        if self.is_valid_direction(new_direction):
            self.direction = new_direction
        else:
            raise Exception('传入了错误的方向值')


    def is_valid_direction(self, new_direction):
        return DirectionManager.is_valid_direction(self.direction, new_direction)


    # 前进一步
    def move_forward(self):
        if self.meet_food():
            self.eat_food()
        else:
            self.body_list.pop()

        x, y = self.head_pos
        x, y = DirectionManager.move_one_step(self.direction, x, y)

        self.body_list.insert(0, (x, y))


    def meet_food(self):
        return self.head_pos == food_manager.fruit_pos


    def eat_food(self):
        food_manager.hide_fruit()
        sound_manager.play_eat_sound()
        for listener in self.eat_food_listeners:
            listener()


    def is_dead(self):
        return self.head_pos in self.body_list[1:]


    def draw_self(self, screen):
        for pos in self.body_list:
            pygame.draw.rect(screen, WHITE,
                    (pos[0]*USIZE, pos[1]*USIZE, USIZE, USIZE))


    def pos_list(self):
        return self.body_list


#game_board
"""

"""
import pygame

from cons import *
from libs.food_manager import food_manager


class GameBoard:

    def __init__(self, game_state):
        self.fontObj = pygame.font.Font('res/Kaiti_GB2312.ttf', 20)
        self.scoreFont = pygame.font.Font('res/Kaiti_GB2312.ttf', 32)
        self.full_screen = False  # 是否全屏
        self.screen = self._new_screen(SCREEN_SIZE)
        self.sprites = []  # 精灵列表
        self.game_state = game_state


    def add_sprite(self, sprite):
        self.sprites.append(sprite)


    def draw(self):
        self._draw_board()
        # if self.game_state.score > 5:
        if   self.game_state.is_1() or self.game_state.is_3() :
            self._draw_tip()
        if  self.game_state.is_over() :
            self._draw_over_tip()
        if  self.game_state.is_5():
            self._draw()
        pygame.display.update()


    def toggle_screen(self):
        self.screen = self._new_screen(SCREEN_SIZE, full=not self.full_screen)


    def _draw_board(self):
        self.screen.fill(GREEN)
        # 分割线
        pygame.draw.line(self.screen, RED, (502, 0), (502, 500), 3)
        #  \n操作 wasd或者方向键进行移动。\n f可在全屏和窗口模式之间进行切换。\n ESC退出游戏。\n
        prompt_text = self.fontObj.render('按空格键 暂停/继续', True, WHITE)
        # prompt_text = self.fontObj.render('按 "空格键" 开始/暂停', True, WHITE)
        # prompt_text = self.fontObj.render('按 "空格键" 开始/暂停', True, WHITE)
        # prompt_text = self.fontObj.render('按 "空格键" 开始/暂停', True, WHITE)
        score_text = self.scoreFont.render('累计得分: {}'.format(self._get_score()), True, WHITE)
        self.screen.blit(prompt_text, (550, 100))
        self.screen.blit(score_text, (570, 220))

        invalid_pos_list = []
        for sprite in self.sprites:
            sprite.draw_self(self.screen)
            invalid_pos_list.extend(sprite.pos_list())

        food_manager.draw_fruit(self.screen, invalid_pos_list)


    def _new_screen(self, size, full=False):
        if full:
            self.full_screen = True
            return pygame.display.set_mode(size, pygame.FULLSCREEN)

        self.full_screen = False
        return pygame.display.set_mode(size)


    def _draw_over_tip(self):
        pygame.draw.rect(self.screen, RED,
                         (200, 120, 400, 300))
        pygame.draw.rect(self.screen, BLACK,
                         (210, 130, 380, 280))
        over_text = self.scoreFont.render('GAME OVER!',
                                          True, WHITE)
        score_text = self.scoreFont.render('最终得分: {}'.format(self._get_score()),
                                           True, WHITE)
        prompt_text = self.fontObj.render('按 "回车键" 重新开始',
                                          True, WHITE)
        self.screen.blit(over_text, (300, 200))
        self.screen.blit(score_text, (300, 240))
        self.screen.blit(prompt_text, (300, 290))

    def _draw_tip(self):
        pygame.draw.rect(self.screen, RED,
                         (200, 120, 400, 300))
        pygame.draw.rect(self.screen, BLACK,
                         (210, 130, 380, 280))
        over_text = self.scoreFont.render('恭喜通关，奖励1分!',
                                          True, WHITE)
        score_text = self.scoreFont.render('通过关数: {}'.format(self._get()),
                                           True, WHITE)
        prompt_text = self.fontObj.render('按 "回车键" 继续下一关',
                                          True, WHITE)
        self.screen.blit(over_text, (300, 200))
        self.screen.blit(score_text, (300, 240))
        self.screen.blit(prompt_text, (300, 290))

    
    def _draw(self):
        pygame.draw.rect(self.screen, RED,
                         (200, 120, 400, 300))
        pygame.draw.rect(self.screen, BLACK,
                         (210, 130, 380, 280))
        over_text = self.scoreFont.render('恭喜通过全部关卡!',
                                          True, WHITE)
        score_text = self.scoreFont.render('通过关数: {}'.format(self._get()),
                                           True, WHITE)
        prompt_text = self.fontObj.render('按 "回车键" 继续游戏',
                                          True, WHITE)
        self.screen.blit(over_text, (300, 200))
        self.screen.blit(score_text, (300, 240))
        self.screen.blit(prompt_text, (300, 290))
    def _get_score(self):
        return self.game_state.score
    def _get(self):
        return self.game_state.guan
    

    def _draw_tip1(self):
        pygame.draw.rect(self.screen, RED,
                         (200, 120, 400, 300))
        pygame.draw.rect(self.screen, BLACK,
                         (210, 130, 380, 280))
        over_text = self.scoreFont.render('进入关卡3',
                                          True, WHITE)
        score_text = self.scoreFont.render(': {}'.format(self._get()),
                                           True, WHITE)
        prompt_text = self.fontObj.render('按 "回车键" 继续下一关',
                                          True, WHITE)
        self.screen.blit(over_text, (300, 200))
        self.screen.blit(score_text, (300, 240))
        self.screen.blit(prompt_text, (300, 290))

    def _draw_tip2(self):
        pygame.draw.rect(self.screen, RED,
                         (200, 120, 400, 300))
        pygame.draw.rect(self.screen, BLACK,
                         (210, 130, 380, 280))
        over_text = self.scoreFont.render('进入关卡2',
                                          True, WHITE)
        score_text = self.scoreFont.render('通过关数: {}'.format(self._get()),
                                           True, WHITE)
        prompt_text = self.fontObj.render('按 "回车键" 继续下一关',
                                          True, WHITE)
        self.screen.blit(over_text, (300, 200))
        self.screen.blit(score_text, (300, 240))
        self.screen.blit(prompt_text, (300, 290))
#game_state

from cons import *
# 游戏状态
from libs.sound_manager import sound_manager



class GameState:
    # 三种状态：playing, pausing, over

    def __init__(self):
        self.state = 'playing'
        self.score = 0 
        self.guan = 1
        self.speed = INITSPEED  

    def reset(self):
        self.set_play()
        self.guan += 1
        self.score = self.score+1  
        self.speed = INITSPEED  

    def rescle_1(self):
        self.set_play()
        self.score = self.score
        self.speed = INITSPEED  

    def res(self):
        self.set_play()
        self.score = 0 
        self.guan = 1
        self.speed = INITSPEED  
        
    def add_score(self):
        
        self.score += 1
        if self.speed < 15:
            self.speed *= 1.1
        if self.score in (15, 30, 60, 75) or\
            (self.score > 75 and (self.score - 80) % 5 == 0):
            sound_manager.play_cheer_sound()



    def set_play(self):
        self.state = 'playing'

    def set_pause(self):
        self.state = 'pausing'

    def set_over(self):
        self.state = 'over'
        sound_manager.play_fail_sound()
        sound_manager.pause_music()


    def is_1(self):
        return self.score == 15
    def is_3(self):
        return self.score == 30
    def is_5(self):
        return self.score == 50
    def is_play(self):
        return self.state == 'playing'

    def is_pause(self):
        return self.state == 'pausing'

    def is_over(self):
        return self.state == 'over'

    def toggle_state(self):
        if self.is_play():
            self.set_pause()
            sound_manager.pause_music()
        elif self.is_pause():
            self.set_play()
            sound_manager.resume_music()

    def add_sco(self):
        # 增加得分
        self.score += 1
        # 如果速度还未达到上限，将速度增加 10%
        if self.speed < 15:
            self.speed *= 1.1
        # 如果当前得分达到了特定的值，或者超过了 75 分并且当前得分减去 80 的余数为 0
        if self.score in (15, 30, 60, 75) or \
                (self.score > 75 and (self.score - 80) % 5 == 0):
            # 播放欢呼声音
            sound_manager.play_cheer_sound()

    def toggle(self):
        if self.is_play():
            self.set_pause()
            sound_manager.pause_music()
        elif self.is_pause():
            self.set_play()
            sound_manager.resume_music()
class SnakeGame:

    def __init__(self):
        pygame.init()
         # 当前游戏状态
        self.game_state = GameState() 
        self.snake = self._create_snake()  # 蛇

        self.board = GameBoard(self.game_state)  # 画板
        self.board.add_sprite(self.snake)

        self.fps_clock = pygame.time.Clock()  # 控制帧率
        self.direction_lock = SimpleLock() 

        pygame.display.set_caption(TITLE)


    def start(self):
        # 绘制游戏初始画面
        self.board.draw()

        # 游戏主循环
        while True:
            # 解除方向锁定，允许玩家在下一次迭代中改变蛇的方向
            self.direction_lock.unlock()

            # 处理键盘事件，例如玩家按下方向键或者退出游戏
            for event in pygame.event.get():
                self.handle_key_event(event)

            # 如果游戏正在进行中，检查蛇的状态并更新游戏状态
            if self.game_state.is_play():
                if self.snake.is_dead():  # 如果蛇死亡，游戏结束
                    self.game_state.set_over()
                else:
                    self.snake.move_forward()  # 如果蛇还活着，让它向前移动一格

            # 绘制游戏画面
            self.board.draw()

            # 控制游戏帧率，以确保游戏不会运行得太快或太慢
            self.fps_clock.tick(self.game_state.speed)


    def handle_key_event(self, event):
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                sys.exit()

            if event.key == K_f:
                self.board.toggle_screen()


            elif ( self.game_state.is_1() or self.game_state.is_3()) and event.key == K_RETURN:
                self.restart()
            elif (self.game_state.is_over() and event.key == K_RETURN):
                self.rest()
            elif (self.game_state.is_5() and event.key == K_RETURN):
                self.rest()
            elif event.key == K_SPACE:
                self.game_state.toggle_state()

            elif self.game_state.is_play() and not self.direction_lock.is_locked():
                direction = DirectionManager.get_direction_by_key(event.key)
                if self.snake.is_valid_direction(direction):
                    self.snake.set_direction(direction)
                    self.direction_lock.lock()

        if event.type == QUIT:
            sys.exit()


    def restart(self):
        
        self.game_state.reset()
        self.direction_lock.unlock()
        # self.snake.reset()
        sound_manager.replay_music()

    def rest(self):
       
        self.game_state.res()
        self.direction_lock.unlock()
        self.snake.reset()
        sound_manager.replay_music()

    def _create_snake(self):
        snake = Snake()
        def on_eat_food():
            self.game_state.add_score()
        snake.register_eat_food_listener(on_eat_food)
        return snake
    

    def _create_snake(self):
        # 创建一个蛇对象
        snake = Snake()
        # 定义一个回调函数，在蛇吃到食物时被调用，用于增加玩家得分
        def on_eat_food():
            self.game_state.add_score()
        # 在蛇对象中注册上面定义的回调函数，当蛇吃到食物时，它会自动调用该回调函数
        snake.register_eat_food_listener(on_eat_food)
        # 返回创建的蛇对象
        return snake


if __name__ == '__main__':
    game = SnakeGame()
    game.start()