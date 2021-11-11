#include "legendre_polynome.h"
#include "newton.h"
/*
Calcula la derivada del polinimio de legendre dada una x
 */
double obtain_derivate(double x, int i)
{
    double h = 1e-7;
    double pxi = legende_polynome(x, i);
    double pxj = legende_polynome(x + h, i);
    return (pxj - pxi) / h;
}
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
/*
Obtiene las raices de un polinomio de legendre dado su grado
 */
double *obtain_roots(int n)
{
    double x;
    double *roots = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        x = obtain_ai(i, n);
        *(roots + i) = newton_method(x, n);
    }
    return roots;
}
/*
Obtiene los pesos del polinomio de legendre
 */
double *obtain_weight(int n)
{
    double *weights = (double *)malloc(n * sizeof(double));
    double *roots = obtain_roots(n);
    double dpx, root_i, a_i;
    for (int i = 0; i < n; i++)
    {
        root_i = *(roots + i);
        dpx = obtain_derivate(root_i, n);
        a_i = 2 / ((1 - root_i * root_i) * dpx * dpx);
        *(weights + i) = a_i;
    }
    free(roots);
    return weights;
}