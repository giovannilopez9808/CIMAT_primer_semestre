#include <stdio.h>
#include <math.h>
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
    double fx1 = f(*x1);
    double fx = f(*x);
    if (fx1 * fx < 0)
    {
        *x0 = *x;
    }
    else
    {
        *x1 = *x;
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
    double tau = 10e-6;
    // inicio de la busqueda
    while (fabs(x1 - x0) > tau && fabs(f(x)) > tau)
    {
        // Calculo de la posible raiz
        obtain_new_interval(f, &x0, &x1, &x);
    }
    printf("\t\tx = %lf\n", x);
}