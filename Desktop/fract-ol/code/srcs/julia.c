#include "../julia.h"

unsigned int divjulia(t_complex z, t_complex c, unsigned int max_iter)
{
    unsigned int iter;

    iter = 0;
    while (iter < max_iter && z.re * z.re + z.im * z.im <= 4)
    {
        squarec(&z);
        addc(&z, c);
        ++iter;
    }
    return (iter);
}
