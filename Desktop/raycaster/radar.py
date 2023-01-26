import keyboard

class Radar :

    solids = "/-|0\#"

    def getKeys(self) : return keyboard.get_hotkey_name()

    def update(self,sprites,scene) :
        self.collider(sprites,scene,self.solids)

    def collider(self,sprites,scene,solids) : 
        for sprite in sprites :
            sprcoord = sprite.getSprite()['coord']

            sprite.rstCollX()
            for i in range(0,2):
                x = i*(sprcoord.getWidth()-1)
                for y in range(0,sprcoord.getLength()) :

                    if i == 0 :
                        if scene.getCase(sprcoord.getCase(x,y)[0]-1,sprcoord.getCase(x,y)[1]) in solids :
                            sprite.leftColl()
                            break

                    elif scene.getCase(sprcoord.getCase(x,y)[0]+1,sprcoord.getCase(x,y)[1]) in solids :
                        sprite.rightColl()
                        break

            sprite.rstCollY()
            for i in range(0,2):
                y = i*(sprcoord.getLength()-1)
                for x in range(0,sprcoord.getWidth()) :

                    if i == 0 :
                        if scene.getCase(sprcoord.getCase(x,y)[0],sprcoord.getCase(x,y)[1]-1) in solids :
                            sprite.downColl()
                            break

                    elif scene.getCase(sprcoord.getCase(x,y)[0],sprcoord.getCase(x,y)[1]+1) in solids :
                        sprite.upColl()
                        break