#include "newton.h"
#include "legendre_polynome.h"
double obtain_derivate(double x, int i)
{
    double h = 1e-4;
    double pxi = legende_polynome(x, i);
    double pxj = legende_polynome(x + h, i);
    return (pxj - pxi) / h;
}
int convergence(double x, int i)
{
    double px = legende_polynome(x, i);
    if (px < 1e-6)
    {
        return 0;
    }
    return 1;
}
double newton_method(double x, int i)
{
    while (convergence(x, i))
    {
        x = x - legende_polynome(x, i) / obtain_derivate(x, i);
    }
    return x;
}