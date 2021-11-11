#include "legendre_polynome.h"
/* 
Definicion del polinomio de legendre
 */
double legende_polynome(double x, int n)
{

    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    return ((double)(2 * n - 1) * x * legende_polynome(x, n - 1) - (n - 1) * legende_polynome(x, n - 2)) / n;
}
/* 
Obtiene las aproximaciones a las raices del polinomio de legendre
 */
double obtain_ai(int i, int n)
{
    double up = pi * (i + 0.75);
    double down = n + .5;
    return cos(up / down);
}
