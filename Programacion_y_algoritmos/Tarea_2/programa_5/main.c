#include <stdio.h>
#include <math.h>
long double factorial(int n)
{
    /* 
    Definicion del factorial
    */
    long double result = 1;
    for (int i = 1; i < n + 1; i++)
    {
        result = result * i;
    }
    return result;
}

long double obtain_ri_term(double x, int i)
{
    /* 
    Calculo de los termimos de cada suma en la expansion de polinomios
     */
    int sign = 1;
    long double ri;
    // Si es par el termino es positivo, si no es negativo
    if (i % 2)
    {
        sign = -1;
    }
    ri = sign * powl(x, 2 * i) / factorial(i);
    return ri;
}
long double function(double x, int n)
{
    /* 
    Suma de la expansion de los polinomios
     */
    long double fx = 0.0;
    for (int i = 0; i < n + 1; i++)
    {
        fx += obtain_ri_term(x, i);
    }
    return fx;
}
int main()
{
    double x;
    int n;
    printf("Introduce el valor que quieres evaluar en la funcion: ");
    scanf("%lf", &x);
    printf("Introduce el numero de terminos que quieres calcular: ");
    scanf("%d", &n);
    long double fx = function(x, n);
    printf("f(%lf) = %Lf\n", x, fx);
}