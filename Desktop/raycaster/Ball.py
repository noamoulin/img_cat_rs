from Sprite import Sprite

class Ball(Sprite) :

    Vx = 1
    Vy = 1

    def __init__(self,path,x_pos,y_pos,Vx,Vy) -> None:
        Sprite.__init__(self,path,x_pos,y_pos)
        self.Vx = Vx
        self.Vy = Vy

    def update(self,*args) : 

        if self.coll_r or self.coll_l : 
            self.Vx *= -1

            
        if self.coll_u or self.coll_d : 
            self.Vy *= -1

        if self.Vx > 0 :
            if not self.coll_r : self.move(self.Vx,0)
        elif not self.coll_l : self.move(self.Vx,0)
        
        if self.Vy > 0 :
            if not self.coll_u : self.move(0,self.Vy)
        elif not self.coll_d : self.move(0,self.Vy)
