#include <math.h>
double derivate(double (*f)(double), double x)
{
    double df;
    double h = 1e-6;
    df = f(x + h) - f(x);
    df = df / h;
    return df;
}
double double_derivate(double (*f)(double), double x)
{
    double h = 1e-6;
    double df0 = derivate(f, x);
    double df1 = derivate(f, x + h);
    double ddf;
    ddf = df1 - df0;
    ddf = ddf / h;
    return ddf;
}
double stopping_criteria(double x0, double x1)
{
    /* 
    Criterio para pararel algoritmo por diferencia relativa o diferencia absoluta
     */
    double diff = fabs(x1 - x0);
    return diff;
}