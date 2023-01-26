#include "../fract-ol.h"

void    *renderhl(void *fractol)
{
    while (1)
    {
        render_square(fractol, 0, 0, 500);
        pthread_join(((t_fractol *)fractol)->hl, NULL);
    }
    return (NULL);
}

void    *renderll(void *fractol)
{
    while (1)
    {
        render_square(fractol, 0, 500, 500);
        pthread_join(((t_fractol *)fractol)->ll, NULL);
    }
    return (NULL);
}

void    *renderhr(void *fractol)
{
    while (1)
    {
        render_square(fractol, 500, 0, 500);
        pthread_join(((t_fractol *)fractol)->hr, NULL);
    }
    return (NULL);
}

void    *renderlr(void *fractol)
{
    while (1)
    {
        render_square(fractol, 500, 500, 500);
        pthread_join(((t_fractol *)fractol)->lr, NULL);
    }
    return (NULL);
}













void    init_fractol(t_fractol *fractol, int win_size, char *win_title, int fractal_type)
{
    init_render(&(fractol->render), win_size, win_title);
    set_fractal(fractol, fractal_type, complex(0, 0));

    ///////////////////////////////////
    fractol->max_iter = DEFAULT_ITER_MAX;
    fractol->brightness = DEFAULT_BRIGHTNESS;
    ///////////////////////////////////

    ///////////////////////////////////
    define_event(&fractol->render, 17, 1L << 2, kill_render, &fractol->render);
    define_event(&fractol->render, 4, 1L << 2, mouse_event, fractol);
    define_event(&fractol->render, 2, 1L << 0, key_pressed, fractol);
    ///////////////////////////////////

    pthread_create(&fractol->hl,NULL, renderhl, fractol);
    pthread_create(&fractol->ll,NULL, renderll, fractol);
    pthread_create(&fractol->hr,NULL, renderhr, fractol);
    pthread_create(&fractol->lr,NULL, renderlr, fractol);

    set_update(&fractol->render, update_render, fractol);

    update_dp(fractol);
    update_render(fractol);
    start_loop(&fractol->render);
}

void    set_fractal(t_fractol *fractol, int type, t_complex c)
{
    fractol->c = c;
    if (type == 0)
        init_mendelbrot(fractol);
    else if (type == 1)
        init_julia(fractol);
    else
        exit(0);
}

void    init_mendelbrot(t_fractol *fractol)
{
    fractol->convergence = mendelconv;
    set_render_limits(fractol, complex(MENDELBROT_DEFAULT_REMIN, MENDELBROT_DEFAULT_IMMIN), complex(MENDELBROT_DEFAULT_REMAX, MENDELBROT_DEFAULT_IMMAX));
}

void    init_julia(t_fractol *fractol)
{
    fractol->convergence = juliaconv;
    set_render_limits(fractol, complex(JULIA_DEFAULT_REMIN, JULIA_DEFAULT_IMMIN), complex(JULIA_DEFAULT_REMAX, JULIA_DEFAULT_IMMAX));
    fractol->c = complex(-1, 0);
}

void    set_render_limits(t_fractol *fractol, t_complex left_down, t_complex righ_top)
{
    fractol->left_down_lim = left_down;
    fractol->righ_top_lim = righ_top;
}

void    update_dp(t_fractol *fractol)
{
    fractol->dp = fabs(fractol->left_down_lim.re - fractol->righ_top_lim.re) / fractol->render.size;
}

int     iter2color(t_fractol *fractol, int iter)
{
    double e;
    e = (double)iter / (double)(fractol->max_iter);
    e = 255 * (1 - e);
    return (trgb(0, e, e, e));
}

int mouse_event(int button, int x, int y, t_fractol *fractol)
{
    t_complex   tocenter;
    double  zoom;

    x++;
    y++;
    zoom = 1;
    if (button == 4)
    {
        zoom = ZOOMF;
    }
    else if (button == 5)
    {
        zoom = ZOOMB;
    }
    else
    {
        tocenter.re = (x - fractol->render.size / 2) * fractol->dp;
        tocenter.im = (fractol->render.size / 2 - y) * fractol->dp;
        addc(&fractol->left_down_lim, tocenter);
        addc(&fractol->righ_top_lim, tocenter);
    }
    double dz = zoom * 30 * fractol->dp;
    fractol->left_down_lim.re += dz;
    fractol->left_down_lim.im += dz;
    fractol->righ_top_lim.re -= dz;
    fractol->righ_top_lim.im -= dz;
    update_dp(fractol);
    return (0);
}

int key_pressed(int key, t_fractol *fractol)
{
    double  ds = fractol->dp * 50;
    if (key == 122)
    {
        fractol->righ_top_lim.im += ds;
        fractol->left_down_lim.im += ds;
    }
    else if (key == 113)
    {
        fractol->righ_top_lim.re -= ds;
        fractol->left_down_lim.re -= ds;
    }
    else if (key == 115)
    {
        fractol->righ_top_lim.im -= ds;
        fractol->left_down_lim.im -= ds;   
    }
    else if (key == 100)
    {
        fractol->righ_top_lim.re += ds;
        fractol->left_down_lim.re += ds;
    }
    else if (key == 114)
    {
        fractol->left_down_lim = complex(MENDELBROT_DEFAULT_REMIN, MENDELBROT_DEFAULT_IMMIN);
        fractol->righ_top_lim = complex(MENDELBROT_DEFAULT_REMAX, MENDELBROT_DEFAULT_IMMAX);
        fractol->max_iter = DEFAULT_ITER_MAX;
    }
    update_dp(fractol);
    return (0);
}

int render_square_outline(t_fractol *fractol, int i0, int j0, int l)
{
    int iter0;
    int iter1;
    int iter2;
    int iter3;

    iter0 = render_hline(fractol, i0, j0, l);
    iter1 = render_hline(fractol, i0, j0 + l, l);
    iter2 = render_vline(fractol, i0, j0, l);
    iter3 = render_vline(fractol, i0 + l, j0, l);
    if (iter1 == iter0 && iter2 == iter0 && iter3 == iter0 && iter0 != -1)
        return (iter0);
    return (-1);
}

int render_hline(t_fractol *fractol, int i0, int j, int l)
{
    t_complex current_point;
    int iter0;
    int iter;
    int i;
    int ok;

    ok = 1;
    current_point.re = fractol->left_down_lim.re + i0 * fractol->dp;
    current_point.im = fractol->righ_top_lim.im - j * fractol->dp;
    iter0 = fractol->convergence(fractol, current_point);
    set_pixel(&fractol->render, i0, j, iter2color(fractol, iter0));
    i = i0;
    i0 += --l;
    current_point.re += fractol->dp;
    while (++i < i0)
    {
        iter = fractol->convergence(fractol, current_point);
        if (ok && iter != iter0)
            ok = 0;
        set_pixel(&fractol->render, i, j, iter2color(fractol, iter)); //inutile si iter ne change pas... trouver une solution pour gerer ces cas avec la norme (tester deja sans norme)
        current_point.re += fractol->dp;
    }
    if (!ok)
        return (-1);
    return (iter0);
}

int render_vline(t_fractol *fractol, int i, int j0, int l)
{
    t_complex current_point;
    int iter0;
    int iter;
    int j;
    int ok;

    ok = 1;
    current_point.re = fractol->left_down_lim.re + i * fractol->dp;
    current_point.im = fractol->righ_top_lim.im - j0 * fractol->dp;
    iter0 = fractol->convergence(fractol, current_point);
    set_pixel(&fractol->render, i, j0, iter2color(fractol, iter0));
    j = j0;
    j0 += --l;
    current_point.im -= fractol->dp;
    while (++j < j0)
    {
        iter = fractol->convergence(fractol, current_point);
        if (ok && iter != iter0)
            ok = 0;
        set_pixel(&fractol->render, i, j, iter2color(fractol, iter)); //inutile si iter ne change pas... trouver une solution pour gerer ces cas avec la norme (tester deja sans norme)
        current_point.im -= fractol->dp;
    }
    if (!ok)
        return (-1);
    return (iter0);
}


typedef struct s_thread_arg
{
    int i0; 
    int j0;
    int l;
    t_fractol *fractol;
} t_thread_arg;

t_thread_arg *arg(t_thread_arg *arg, t_fractol *fractol, int i0, int j0, int l)
{
    arg->fractol = fractol;
    arg->i0 = i0;
    arg->j0 = j0;
    arg->l = l;
    return (arg);
}

void    *render_square_thread(t_thread_arg *arg)
{
    render_square_force(arg->fractol, arg->i0, arg->j0, arg->l);
    return(NULL);
}

void render_square(t_fractol *fractol, int i0, int j0, int l)
{
    int res;
    int ld;

    res = render_square_outline(fractol, i0, j0, l);
    if (res != -1)
        fill_square(&fractol->render, i0 + 1, j0 + 1, l - 1, /*trgb(0, 200, 0, 0)*/ iter2color(fractol, res));
    else if (l >= MIN_SIMPLIFYING_SIZE)
    {
        ld = l / 2;
        render_square(fractol, i0, j0, ld);
        render_square(fractol, i0 + ld, j0, ld);
        render_square(fractol, i0, j0 + ld, ld);
        render_square(fractol, i0 + ld, j0 + ld, ld);
    }
    else
    {
        render_square_force(fractol, i0 + 1, j0 + 1, l - 1);
    }
}

void render_square_force(t_fractol *fractol, int i0, int j0, int l)
{
        t_complex current_point;
        double im0;
        int i;
        int j;

        i = i0;
        j = j0;
        im0 = fractol->righ_top_lim.im - j0 * fractol->dp;
        current_point.re = i0 * fractol->dp + fractol->left_down_lim.re;
        for (i = i0; i <= i0 + l; i++)
        {
            current_point.im = im0;
            for (j = j0; j <= j0 + l; j++)
            {
                set_pixel(&fractol->render, i, j, iter2color(fractol, fractol->convergence(fractol, current_point)));
                current_point.im -= fractol->dp;
            }
            current_point.re += fractol->dp;
        }
}

int update_render(t_fractol* fractol)
{
    put_image(&fractol->render);
    return (0);
}

int    mendelconv(t_fractol *fractol, t_complex z)
{
    return (divmendel(z, fractol->max_iter));
}

int    juliaconv(t_fractol *fractol, t_complex z)
{
    return (divjulia(z, fractol->c, fractol->max_iter));
}

void *update(t_fractol *fractol)
{
    int x; 
    int y;

    mlx_mouse_get_pos(fractol->render.mlx, fractol->render.win, &x, &y);
    fractol->c.re = -2 + fractol->dp * x;
    fractol->c.im = 2 - fractol->dp * y;
    return(NULL);
}