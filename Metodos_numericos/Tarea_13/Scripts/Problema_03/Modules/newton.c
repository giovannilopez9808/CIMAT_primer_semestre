#include "newton.h"
#include "legendre_polynome.h"
/*
Checa la convergencia del metodo de newton
 */
int convergence(double x, int i)
{
    double px = legende_polynome(x, i);
    if (px < 1e-6)
    {
        return 0;
    }
    return 1;
}
/*
Aplica el metodo de newton para el polinomio de legendre dado su n
 */
double newton_method(double x, int n)
{
    while (convergence(x, n))
    {
        x = x - legende_polynome(x, n) / obtain_derivate(x, n);
    }
    return x;
}