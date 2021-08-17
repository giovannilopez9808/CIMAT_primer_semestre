#include <stdio.h>
#include <math.h>
int factorial(int n)
{
    /* 
    Definicion del factorial
    */
    int result = 1;
    for (int i = 1; i < n + 1; i++)
    {
        result = result * i;
    }
    return result;
}
double function(double x)
{
    /* 
    Definicion de la funcion
     */
    return x * exp(x * x);
}
double obtain_ri_term(double x, int i)
{
    return pow(x, 2 * i + 1) / factorial(i);
}
double function_approximation(double x, int n)
{
    /* 
    Definicion de la funcion aproximada.
    f(x)=\sum_{i=0}^n (x^{2i+1})/i!
     */
    double fx = x;
    for (int i = 1; i < n + 1; i++)
    {
        fx += obtain_ri_term(x, i);
    }
    return fx;
}
void obtain_upper_bounds(double xi, double xf, double dx)
{
    double res, r4;
    double max_f_and_approx = 0.0;
    double max_R4 = 0.0;
    for (double x = xi; x < xf + dx; x += dx)
    {
        r4 = obtain_ri_term(x, 4);
        res = fabs(function(x) - function_approximation(x, 4));
        if (res > max_f_and_approx)
        {
            max_f_and_approx = res;
        }
        if (r4 > max_R4)
        {
            max_R4 = r4;
        }
    }
    printf("El limite superior de |f(x)-P4(x)| es:\t%lf\n", max_f_and_approx);
    printf("El limite superior de |R4(x)| es:\t%lf\n", max_R4);
}
void calculate_integral(double xi, double xf, double dx)
{
    /* 
    Calculo de la integral usando la aproximacion de la funcion
     */
    double result = 0.0;
    for (double x = xi; x < xf + dx; x += dx)
    {
        result += function_approximation(x, 4) * dx;
    }
    printf("El resultado de la integral es:\t%lf\n", result);
}
int main()
{
    int n = 10000;
    double xi = 0.0, xf = 0.4;
    double dx = (xf - xi) / n;
    obtain_upper_bounds(xi,
                        xf,
                        dx);
    calculate_integral(xi,
                       xf,
                       dx);
    return 0;
}