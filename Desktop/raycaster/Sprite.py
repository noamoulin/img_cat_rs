from matrix import Matrix
import copy

def adapt(x,in_min,in_max,out_min,out_max): return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

class Sprite:

    def __init__(self,mesh_path,x_pos,y_pos) -> None:

        f_mesh  = open(mesh_path)
        raw_mesh = list()

        for line in f_mesh : raw_mesh.append(line)

        f_mesh.close()

        for i in range(len(raw_mesh)) : 
            raw_mesh[i] = raw_mesh[i].split()
        self.x_size = len(raw_mesh[0])
        self.y_size = len(raw_mesh)
        sqrmatsize = max(self.x_size,self.y_size)
        self.mesh = Matrix(self.y_size,self.x_size,' ')

        for y in range(self.y_size) :
            for x in range(self.x_size) :
                self.mesh.setCase(x,y,raw_mesh[self.y_size-y-1][x])
        self.center = self.mesh.center()

        del raw_mesh

        self.coll_r = False
        self.coll_l = False
        self.coll_u = False
        self.coll_d = False

        self.x_pos = x_pos
        self.y_pos = y_pos

    def move(self,dx,dy) :
        self.x_pos += dx
        self.y_pos += dy

    def up(self) : self.move(0,1)
    def down(self) : self.move(0,-1)
    def right(self) : self.move(1,0)
    def left(self) : self.move(-1,0)

    def show(self) :
        self.sprite.display()

    def getSprite(self) : 

        #matrice de coordonnées :

        coord = Matrix(self.mesh.getLength(),self.mesh.getWidth())
        x0 = self.x_pos-self.center['x']
        y0 = self.y_pos-self.center['y']

        for x in range(self.mesh.getWidth()):
            for y in range(self.mesh.getLength()):
                if self.mesh.getCase(x,y) != '.' :
                    coord.setCase(x,y,(x0+x,y0+y))

        return {'sprite' : copy.deepcopy(self.mesh), 'x' : self.x_pos, 'y' : self.y_pos, 'coord' : coord}

    def upColl(self) : 
        self.coll_u = True

    def downColl(self) : 
        self.coll_d = True

    def rightColl(self) : self.coll_r = True

    def leftColl(self) : self.coll_l = True

    def rstCollY(self) :
        self.coll_u = False
        self.coll_d = False
    
    def rstCollX(self) :
        self.coll_r = False
        self.coll_l = False