#include <stdio.h>
double obtain_new_x_bisection(double x0, double x1)
{
    /* 
    Calculo de la nueva x siguiendo el algoritmo de biseccion
    x0 -> limite inferior
    x1 -> limite superior
     */
    double x = x0;
    x += (x1 - x0) / 2;
    return x;
}
void obtain_new_interval(double (*f)(double), double *x0, double *x1, double *x)
{
    /* 
    Calculo del nuevo intervalo de busqueda siguiendo el algoritmo de biseccion
    (*f) -> funcion que recibe un dato double y devuelve un double
    x0 -> limite inferior del intervalo
    x1 -> limite superior del intervalo
    x -> posible raiz de la funcion
     */
    double df = derivate(f, *x);
    if (df < 0)
    {
        *x1 = *x;
    }
    else
    {
        *x0 = *x;
    }
    *x = obtain_new_x_bisection(*x0, *x1);
}
void bisection_method(double (*f)(double), double x0, double x1)
{
    /* 
    Algoritmo de biseccion. 
    (*f) -> funcion que recibe un dato double y devuelve un double
    x0 -> limite inferior del intervalo
    x1 -> limite superior del intervalo
     */
    printf("\tBiseccion:\n");
    double x = obtain_new_x_bisection(x0, x1);
    // Tolerancia de la busqueda
    double tau = 1e-12;
    // Inicializacion del numero de intentos
    int attempt = 0;
    printf("\t\tIteraciones\tAproximación\tTolerancia\n");
    // inicio de la busqueda
    while (stopping_criteria(x0, x1) > tau)
    {
        // Calculo de la posible raiz
        obtain_new_interval(f, &x0, &x1, &x);
        attempt++;
        printf("\t\t\t%d\t%.12lf\t%.12lf\n", attempt, x, stopping_criteria(x0, x1));
    }
    printf("\t\tSolucion: x = %.12lf\n", x);
    printf("\t\tPunto de interes: (%.12f , %.12f)\n", x, f(x));
}