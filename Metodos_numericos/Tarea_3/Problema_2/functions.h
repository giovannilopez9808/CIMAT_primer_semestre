#include <math.h>
float round_custom(double number, int decimal)
{
    /* 
    Realiza el redondeo de un numero dado los decimales
     */
    double ten_power = pow(10, decimal);
    return roundf(number * ten_power) / ten_power;
}
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
double obtain_sign(int i)
{
    /* 
    Devuelve un numero positivo si i es par, si no devuelve un signo negativo
     */
    double sign = 1;
    if (i % 2)
    {
        sign = -1;
    }
    return sign;
}
double obtain_ai_sin_term(int i)
{
    /* 
    Obtiene el coeficiente ai para la serie del seno
     */
    double ai;
    double sign = obtain_sign(i);
    double fac = factorial(2 * i + 1);
    ai = sign / fac;
    return ai;
}
double obtain_ai_cos_term(int i)
{
    /* 
    Obtiene el coeficiente ai para la serie del coseno
     */
    double ai;
    double sign = obtain_sign(i);
    double fac = factorial(2 * i);
    ai = sign / fac;
    return ai;
}
double sin_with_series(double x, int n)
{
    /* 
    Evalua sin(x) usando serie de potencias
     */
    double sinx = obtain_ai_sin_term(n);
    for (int i = n - 1; i >= 0; i--)
    {
        sinx = round_custom(obtain_ai_sin_term(i), 4) + round_custom(x * x * sinx, 4);
    }
    sinx = x * sinx;
    return sinx;
}
double cos_with_series(double x, int n)
{
    /* 
    Evalua cos(x) usando serie de potencias
     */
    double cosx = obtain_ai_cos_term(n);
    for (int i = n - 1; i >= 0; i--)
    {
        cosx = round_custom(obtain_ai_cos_term(i), 4) + round_custom(x * x * cosx, 4);
    }
    return cosx;
}