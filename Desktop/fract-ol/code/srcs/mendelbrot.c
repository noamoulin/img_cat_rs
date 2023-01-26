#include "../mendelbrot.h"

unsigned int    divmendel(t_complex z, unsigned int max_iter)
{
    return (divjulia(z, z, max_iter));
}