#include "../render.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void    init_render(t_render *render, int size, char *title)
{
    render->size = size;
    render->title = title;
    render->mlx = mlx_init();
    render->win = mlx_new_window(render->mlx, size, size, title);
    render->image.addr = mlx_new_image(render->mlx, size, size);
    render->image.buffer = mlx_get_data_addr(render->image.addr, &(render->image.pixels_bits), &(render->image.line_bytes), &(render->image.endian));
}

void	set_pixel(t_render *render, int i, int j, int color)
{
	char	*dst;
    t_image *image;
    
    image = &(render->image);
	dst = image->buffer + (j * image->line_bytes + i * (image->pixels_bits / 8));
	*(unsigned int *)dst = color;
}

void    clear_render(t_render *render, int color)
{
    int i;
    int j;

    i = 0;
    while (i < render->size)
    {
        j = 0;
        while (j < render->size)
        {
            set_pixel(render, i, j, color);
            j++;
        }
        i++;
    }
}

int    kill_render(t_render *render)
{
    mlx_destroy_window(render->mlx, render->win);
    exit(0);
    return (0);
}

void    set_update(t_render *render, int (*funct_ptr)(), void *context)
{
    mlx_loop_hook(render->mlx, funct_ptr, context);
}

void    start_loop(t_render *render)
{
    mlx_loop(render->mlx);
}

void    put_image(t_render *render)
{
    mlx_put_image_to_window(render->mlx, render->win, render->image.addr, 0, 0);
}

void    define_event(t_render *render, int event, int mask, int (*funct)(), void *param)
{
    mlx_hook(render->win, event, mask, funct, param);
}

void    fill_square(t_render *render, int i0, int j0, int l, int color) // p0 : gauche bas // p1 : droite haut
{
    int j;
    int i;

    i = i0;
    while (i <= i0 + l)
    {
        j = j0;
        while (j <= j0 + l)
        {
            set_pixel(render, i, j, color);
            j++;
        }
        i++;
    }
}