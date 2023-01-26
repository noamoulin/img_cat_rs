from matrix import Matrix
from player import Player
from Ball import Ball
from radar import Radar
from map import Map
from render import render
from begend import begin, end
import os 
import sys
import random
import numpy as np
import copy

class Game :

    def __init__(self) -> None:

        self.map = Map('/home/noa/Desktop/raycaster/map.pam')
        self.scene = self.map
        self.x_size = self.map.getWidth()
        self.y_size= self.map.getLength()
        self.window = Matrix(70,100,' ')
        self.radar = Radar()
        self.nb_balls = 0
        self.i = 0
        self.t = 0
        self.w = False
        self.sr = True
        self.sx = False
        self.camera =  Player('/home/noa/Desktop/raycaster/camera.aremac',int(self.x_size/2),int(self.y_size/2),'z','s','d','q')
        self.sprites = list()
            
    def getSprites(self) : return self.sprites

    def getScene(self) : return self.scene

    def update(self) : 
        
        self.camera.update(self.radar.getKeys())
        self.scene = copy.deepcopy(self.map)
        self.window.clear(' ')
        self.window.encadre(0,0,'#','#')
        self.radar.update(self.sprites,self.scene)

        render(self.scene,self.camera.x_pos,self.camera.y_pos,self.t,self.window,self.sr)

        for sprite in self.sprites : 
            sprite.update(self.radar.getKeys())
            self.scene.phagocyte(sprite.getSprite()['sprite'],sprite.getSprite()['x'],sprite.getSprite()['y'])

        camera = self.camera.getSprite()

        self.scene.phagocyte(camera['sprite'],camera['x'],camera['y'])
    
        if 'r' in self.radar.getKeys() : self.w = True
        if 'i' in self.radar.getKeys() and self.w : self.w = False

        if 'p' in self.radar.getKeys() : end(self.radar,self.scene,self.map)
        if 'y' in self.radar.getKeys() : self.map.edit()
        
        if 'm' in self.radar.getKeys() : self.t -= 0.1
        if 'k' in self.radar.getKeys() : self.t += 0.1

        if 'x' in self.radar.getKeys() :

            if not self.sx :
                if self.sr : 
                    self.sr = False
                else: 
                    self.sr = True
            self.sx = True

        else: self.sx = False

        if self.sr : self.scene.print(self.scene.sizex-25,15,"Cacher les rayons : x",color='green')

        else : self.scene.print(self.scene.sizex-25,15,"Afficher les rayons : x",color='green')

        if self.w : self.window.print(self.window.x_size-25,15,"Vue 2D : i",color='green')
        self.scene.print(self.scene.sizex-25,18,"Vue 3D : r",color='green')

        os.system('clear')

        if self.w : self.window.display()
        else :  self.scene.display()