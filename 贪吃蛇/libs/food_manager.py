"""
 Created by plough on 2023/4/29.
"""

# 处理与食物有关的事情
import random
import pygame

from cons import *


class FoodManager:
    def __init__(self):
        self.fruit_showing = False  # 当前是否有食物
        self.fruit_pos = None  # 食物位置

    def draw_fruit(self, screen, invalid_positions):
        """生成并绘制食物"""
        if not self.fruit_showing:
            self.fruit_pos = self.random_pos(invalid_positions)

        pygame.draw.rect(screen, RED,
                (self.fruit_pos[0]*USIZE, self.fruit_pos[1]*USIZE, USIZE, USIZE))

        self.fruit_showing = True
        
class FoodManager:
    def __init__(self):
        self.fruit_showing = False  # 当前是否有食物
        self.fruit_pos = None  # 食物位置

    def draw_fruit(self, screen, invalid_positions):
        """
        生成并绘制食物。
        如果当前没有食物，则生成一个新的食物位置，否则使用之前生成的食物位置。
        在屏幕上绘制红色的矩形来表示食物。
        """
        if not self.fruit_showing:
            self.fruit_pos = self.random_pos(invalid_positions)

        pygame.draw.rect(screen, RED,
                (self.fruit_pos[0]*USIZE, self.fruit_pos[1]*USIZE, USIZE, USIZE))

        self.fruit_showing = True

    @staticmethod
    def random_pos(invalid_positions):
        pos = None
        while not pos or pos in invalid_positions:
            x = random.randint(0, ROWS - 1)
            y = random.randint(0, ROWS - 1)
            pos = (x, y)
        return pos
    
    @staticmethod
    def random(invalid_positions):
        all_positions = [(x, y) for x in range(ROWS) for y in range(ROWS)]
        valid_positions = list(set(all_positions) - set(invalid_positions))
        return random.choice(valid_positions)
    
    def hide_fruit(self):
        self.fruit_showing = False

# 单例模式
food_manager = FoodManager()