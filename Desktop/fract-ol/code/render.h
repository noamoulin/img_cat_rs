#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct s_image
{
    void    *addr;
    int     pixels_bits;
    int     line_bytes;
    int     endian;
    char    *buffer;
}   t_image;

typedef struct s_render
{
    void    *mlx;
    void    *win;
    t_image image;
    int     size;
    char    *title;
}   t_render;

void    init_render(t_render *render, int size, char *title);
void    set_update(t_render *render, int (*funct_ptr)(), void *context);
void    set_pixel(t_render *render, int i, int j, int color);
void    clear_render(t_render *render, int color);
int     kill_render(t_render *render);
void    start_loop(t_render *render);
void    put_image(t_render *render);
void    define_event(t_render *render, int event, int mask, int (*funct)(), void *param);
void    fill_square(t_render *render, int i0, int j0, int l, int color); // p0 : gauche bas // p1 : droite haut
int     trgb(int t, int r, int g, int b);