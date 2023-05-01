import pygame
import os

class SoundManager:
    # 背景音乐文件路径
    music_path = os.path.join('res', 'background.mp3')

    def __init__(self):
        # 初始化音乐和加载音效
        self._init_music()
        self.sound_eat = self._load_sound('eat.ogg')
        self.sound_fail = self._load_sound('gameover.ogg')
        self.sound_cheer = self._load_sound('cheer.ogg')

    # 初始化背景音乐
    @classmethod
    def _init_music(cls):
        pygame.mixer.init()
        pygame.mixer.music.load(cls.music_path)
        pygame.mixer.music.set_volume(0.2)
        pygame.mixer.music.play(-1)

    # 加载音效
    @staticmethod
    def _load_sound(file_name):
        return pygame.mixer.Sound(os.path.join('res', file_name))

    # 播放背景音乐
    @staticmethod
    def replay_music():
        pygame.mixer.music.rewind()
        pygame.mixer.music.unpause()

    # 暂停背景音乐
    @staticmethod
    def pause_music():
        pygame.mixer.music.pause()

    # 恢复背景音乐
    @staticmethod
    def resume_music():
        pygame.mixer.music.unpause()

    # 播放吃到食物的音效
    def play_eat_sound(self):
        self.sound_eat.play()

    # 播放失败的音效
    def play_fail_sound(self):
        self.sound_fail.play()

    # 播放欢呼的音效
    def play_cheer_sound(self):
        self.sound_cheer.play()

# 单例模式，创建 SoundManager 的实例
sound_manager = SoundManager()