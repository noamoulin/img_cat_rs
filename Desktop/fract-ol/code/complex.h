#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>

typedef struct s_complex
{
    double  re;
    double  im;
}   t_complex;

t_complex   complex(double re, double im);
double  modc(t_complex z);
t_complex   sum(t_complex z0, t_complex z1);
t_complex   product(t_complex z0, t_complex z1);
void    squarec(t_complex *z);
void    addc(t_complex *z0, t_complex z1);
void    multcr(t_complex *z, double x);

#endif