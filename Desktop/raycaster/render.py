from math import sin,pi
from numpy import arange
from matrix import adapt,colors

def render(scene,posx,posy,t,window,show_rays) :
    
    angles = arange(pi/4+t,3*pi/4+t,0.005)
    angles_vue = arange(pi/4,3*pi/4,0.005)
    i = 0
    d0 = 0
    ti = int(len(angles_vue)/2)


    
    for alpha in angles :
        d = scene.ray(posx,posy,alpha,ray=show_rays)
        dy = (d*sin(angles_vue[i]))/8
        if i == ti : d0 = d
        xwin = adapt(angles_vue[i],pi/4,3*pi/4,2,98)
        window.line(xwin,int(35+34/(dy+0.1)),xwin,int(35-34/(dy+0.1)),colors['green'] + '|')
        i += 1

    scene.print(scene.sizex-20,scene.sizey-10,"RAYCASTER V1.0",color='green')
    window.print(window.x_size-20,window.y_size-10,"RAYCASTER V1.0",color='green')
    scene.print(scene.sizex-20,scene.sizey-12,'D = '+str(round(d0,3)),color='green')
    window.print(window.x_size-20,window.y_size-12,'D = '+str(round(d0,3)),color='green')

    scene.print(scene.sizex-25,12,"Editeur de carte : y",color='green')
    window.print(window.x_size-25,12,"Editeur de carte : y",color='green')
    scene.print(scene.sizex-25,9,"Quitter/sauvegarder : p",color='green')
    window.print(window.x_size-25,9,"Quitter/sauvegarder : p",color='green')