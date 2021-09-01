#include <stdio.h>
#include <math.h>
double factorial(int n)
{
    /* 
    Definicion del factorial
    */
    double result = 1;
    for (int i = 1; i < n + 1; i++)
    {
        result = result * i;
    }
    return result;
}
float round_custom(double number, int decimal)
{
    /* 
    Realiza el redondeo de un numero dado los decimales
     */
    double ten_power = pow(10, decimal);
    return roundf(number * ten_power) / ten_power;
}
float function(double x)
{
    /* 
    Obtiene el valor de la funcion f(x) a seis decimales
     */
    x = round_custom(x, 6);
    return round_custom(expf(x), 6);
}
float obtain_ai(int i)
{
    /* 
    Obtiene el coeficiente i-esimo de la serie
     */
    float ai = 1 / factorial(i);
    return round_custom(ai, 6);
}
float function_approximation(double x, int n)
{
    /* 
    Definicion de la funcion aproximada a seis decimales.
    f(x)=\sum_{i=0}^n (x^i)/i!
     */
    float fx = obtain_ai(n);
    for (int i = n - 1; i >= 0; i--)
    {
        fx = obtain_ai(i) + round_custom(x * fx, 6);
        fx = round_custom(fx, 6);
    }
    return fx;
}

int main()
{
    // Valor de x a calcular
    double x = 1.0;
    // Terminos de la serie inicial
    int n_term = 1;
    //  Valor de la funcion a seis decimales
    float fx = function(x);
    // Primer termino
    float fx_approx = function_approximation(x, n_term);
    // Se detendra cuando la aproximacion sea igual a la funcion
    printf("-----------------------------------\nn\tf(x)\t\tf_approx(x)\n");
    printf("%d\t%f\t%f\n", n_term, fx, fx_approx);
    while (fx != fx_approx)
    {
        n_term++;
        fx_approx = function_approximation(x, n_term);
        printf("%d\t%f\t%f\n", n_term, fx, fx_approx);
    }
    printf("-----------------------------------\n");
    printf("\nSe obtuvo la igualdad usando %d terminos de la serie\n", n_term);
    return 0;
}
