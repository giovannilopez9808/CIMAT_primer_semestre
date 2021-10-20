#include "functions.h"
/*
Calculo de la funcion h(x)
 */
double h_function(double (*f)(double), double x)
{
    double fx = f(x);
    double dfx = obtain_derivative(f, x);
    return fx / dfx;
}
/*
Calculo de la derivada de una funcion de la funcion h
(*f) -> funcion que recibe un dato double y devuelve un double
x -> posible raiz de la funcion
 */
double obtain_h_derivative(double (*f)(double), double x)
{
    double dx = 1e-6;
    double df = h_function(f, (x + dx)) - h_function(f, x);
    df = df / dx;
    return df;
}
/*
Calculo de la derivada de una funcion de la funcion
(*f) -> funcion que recibe un dato double y devuelve un double
x -> posible raiz de la funcion
 */
double obtain_derivative(double (*f)(double), double x)
{
    double dx = 1e-6;
    double df = f(x + dx) - f(x);
    df = df / dx;
    return df;
}