#include "gauss_quadrature.h"
#include "legendre_polynome.h"
/*
Mapeo del valor de x para que este contenido en un intervalo de [-1,1]
 */
double change_x(double x, double b, double a)
{
    return (b - a) * x / 2 + (a + b) / 2;
}
/*
Realiza la integral de una funcion usando el algoritmo de cuadratura de Gauss-Legendre.
 */
double integrate_with_gauss(double (*f)(double), double b, double a, int n)
{
    double root_i, weight_i, x, sum = 0;
    // Obtiene las raices de los polinomios de legendre
    double *roots = obtain_roots(n);
    // Obtiene los pesos de los polinomios de legendre
    double *weights = obtain_weight(n);
    for (int i = 0; i < n; i++)
    {
        root_i = *(roots + i);
        weight_i = *(weights + i);
        x = change_x(root_i, b, a);
        sum += weight_i * f(x);
    }
    sum = (b - a) * sum / 2;
    free(roots);
    free(weights);
    return sum;
}