from os import system
from sys import exit
from matrix import colors

def begin():pass

def end(radar,scene,map) : 

    scene.clear(' ')

    margex = int(scene.getWidth()/3)
    margey = int(scene.getLength()/3)

    centrex = scene.center()['x']
    centrey = scene.center()['y']
    
    scene.encadre(margex,margey,colors['default']+'#',colors['default']+'#')

    scene.print(centrex-15,centrey+3,'Annuler : c')
    scene.print(centrex-15,centrey,'Quitter : k')
    scene.print(centrex-15,centrey-3,'Enregister les modifications : s')

    system('clear')
    scene.display()

    keys = radar.getKeys()

    while not 'c' in keys :

        keys = radar.getKeys()

        if 'k' in keys : 
            system('clear')
            exit()

        if 's' in keys : 
            system('clear')
            map.display(style=True)
            map_f = open(map.getPath(),'w')

            map_str = ""

            for y in range(map.getLength(),-1,-1):
                for x in range(map.getWidth()):
                    map_str += str(map.getCase(x,y))
                map_str += '\n'

            map_f.write(map_str)
            map_f.close()

            return

    return 0