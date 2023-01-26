#include "../complex.h"

t_complex   complex(double re, double im)
{
    t_complex   z;

    z.im = im;
    z.re = re;
    return (z);
}

double  modc(t_complex z)
{
    return (sqrt(z.re * z.re + z.im * z.im));
}

t_complex   sum(t_complex z0, t_complex z1)
{
    return (complex(z0.re + z1.re, z0.im + z1.im));
}

t_complex   product(t_complex z0, t_complex z1)
{
    double a = z0.re;
    double b = z0.im;
    double a1 = z1.re;
    double b1 = z1.im;
    
    return (complex(a * a1 - b * b1, (a + b) * (a1 + b1) - a * a1 - b * b1));
}

void    squarec(t_complex *z)
{
    double  a;
    double  b;

    a = z->re;
    b = z->im;
    z->re = a * a - b * b;
    z->im = 2 * a * b;
}

void    addc(t_complex *z0, t_complex z1)
{
    z0->re += z1.re;
    z0->im += z1.im;
}

void    multcr(t_complex *z, double x)
{
    z->re *= x;
    z->im *= x;
}