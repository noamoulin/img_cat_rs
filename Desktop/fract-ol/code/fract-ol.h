#include "complex.h"
#include "julia.h"
#include "mendelbrot.h"
#include "render.h"
#include "math.h"
#include <pthread.h>

#define MENDELBROT_DEFAULT_REMIN -2
#define MENDELBROT_DEFAULT_REMAX 1
#define MENDELBROT_DEFAULT_IMMIN -1.5
#define MENDELBROT_DEFAULT_IMMAX 1.5
#define JULIA_DEFAULT_REMIN -2
#define JULIA_DEFAULT_REMAX 2
#define JULIA_DEFAULT_IMMIN -2
#define JULIA_DEFAULT_IMMAX 2
#define DEFAULT_ITER_MAX 50
#define DEFAULT_BRIGHTNESS 1
#define ZOOMF 1
#define ZOOMB -1
#define MIN_SIMPLIFYING_SIZE 35

typedef struct s_fractol
{
    pthread_t hl;
    pthread_t ll;
    pthread_t hr;
    pthread_t lr;
    t_render    render;
    int         fractal_id;
    t_complex   c;
    t_complex   left_down_lim;
    t_complex   righ_top_lim;
    int         max_iter;
    double      dp;
    int         brightness;
    int         ndiv;
    int         ds;
    int (*convergence)(struct s_fractol *, t_complex);
}   t_fractol;

void    init_fractol(t_fractol *fractol, int win_size, char *win_title, int fractal_type);
void    set_render_limits(t_fractol *fractol, t_complex left_down, t_complex righ_top);
void    update_dp(t_fractol *fractol);
int    update_render(t_fractol* fractol);
int     iter2color(t_fractol *fractol, int iter);
int     mouse_event(int button, int x, int y, t_fractol *fractol);
int     key_pressed(int key, t_fractol *fractol);
int     render_square_outline(t_fractol *fractol, int i0, int j0, int l);
void    render_square(t_fractol *fractol, int i0, int j0, int l);
void    render_square_force(t_fractol *fractol, int i0, int j0, int l);
int    render_hline(t_fractol *fractol, int i0, int j, int l);
int    render_vline(t_fractol *fractol, int i, int j0, int l);
int    mendelconv(t_fractol *fractol, t_complex);
int    juliaconv(t_fractol *fractol, t_complex);
void   init_mendelbrot(t_fractol *fractol);
void   init_julia(t_fractol *fractol);
void    set_fractal(t_fractol *fractol, int type, t_complex c);
void    *update(t_fractol *fractol);
void    exit_fractol(t_fractol *fractol); //kill les threads proprement
