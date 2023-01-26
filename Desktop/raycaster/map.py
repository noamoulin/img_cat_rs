from matrix import Matrix
from radar import Radar
import time
import copy
import os

class Map(Matrix):

    def __init__(self,path) -> None :

        map_brut = list()
        self.path = path
        map_f = open(path)
    
        for elm in map_f : 
            map_brut.append(elm)

        map_f.close()

        map_brut.pop(0)

        self.sizex = len(map_brut[0])-1
        self.sizey = len(map_brut)

        super().__init__(self.sizey,self.sizex,' ')

        for y in range(self.sizey) :
            for x in range(self.sizex) :
                self.setCase(x,y,map_brut[y][x])

        del map_brut

    def getPath(self) : return self.path

    def edit(self):

        tmp = copy.deepcopy(self)

        posx = int(self.sizex/2)
        posy = int(self.sizey/2)

        keyRadar = Radar()
        keys = keyRadar.getKeys()

        def update(tmp0) : 
            
            tmp.display()
            time.sleep(0.015)
            tmp.phagocyte(tmp0)
            os.system('clear')

        def wall(self,posx,posy):

            tmp0 = copy.deepcopy(self)

            keys = keyRadar.getKeys()
            Ay = posx
            Ax = posx

            Bx = posx
            By = posx

            while not 'e' in keys:

                keys = keyRadar.getKeys()

                tmp.print(5,self.sizey-5,'Quitter : e')
                tmp.print(5,self.sizey-8,'Point A : a')
                tmp.print(5,self.sizey-9,'Point B : b')
                tmp.print(5,self.sizey-12,'Valider mur : v')
                tmp.print(5,self.sizey-14,'Gommer : g')
                tmp.print(5,self.sizey-16,'Enregister : h')
                tmp.setCase(posx,posy,'@')
                tmp.line(Ax,Ay,Bx,By,'#')
                
                if 'z' in keys : posy += 1
                if 's' in keys : posy -= 1
                if 'd' in keys : posx += 1
                if 'q' in keys : posx -= 1
                if 'g' in keys : tmp0.setCase(posx,posy,' ')
                if 'v' in keys : tmp0.line(Ax,Ay,Bx,By,'#')
                if 'u' in keys : return None
                if 'h' in keys : self.phagocyte(tmp0)

                if 'a' in keys : 
                    Ax = posx
                    Ay = posy

                if 'b' in keys : 
                    Bx = posx
                    By = posy

                update(tmp0)

            return 0

        wall(self,posx,posy)
        time.sleep(1)