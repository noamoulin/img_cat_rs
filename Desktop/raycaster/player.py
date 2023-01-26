from Sprite import Sprite

class Player(Sprite) :

    def __init__(self,path,x_pos,y_pos,up,down,right,left) -> None:
        Sprite.__init__(self,path,x_pos,y_pos)
        self.up_key = up
        self.down_key = down
        self.left_key = left
        self.right_key = right

    def update(self,keys) : 
        if self.up_key in keys : self.up()
        if self.down_key in keys : self.down()
        if self.left_key in keys : self.left()
        if self.right_key in keys : self.right()