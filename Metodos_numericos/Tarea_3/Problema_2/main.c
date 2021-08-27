#include "functions.h"
#include <stdio.h>
#include <math.h>
float round_custom(double number, int decimal)
{
    /* 
    Realiza el redondeo de un numero dado los decimales
     */
    double ten_power = pow(10, decimal);
    return roundf(number * ten_power) / ten_power;
}
double function(double x)
{
    /* 
    Evalua la funcion en x
     */
    double fx;
    fx = x * cos(x) * sin(x) / (x - sin(x));
    return fx;
}
double function_four_digits(double x)
{
    /* 
    Evalua la funcion redondeando cada termino a cuatro digitos
     */
    x = round_custom(x, 4);
    float sin_x = round_custom(sin(x), 4);
    float cos_x = round_custom(cos(x), 4);
    float x_4 = round_custom(x, 4);
    float up = round_custom(x_4 * sin_x * cos_x, 4);
    float down = round_custom(x_4 - sin_x, 4);
    double fx_4 = round_custom(up / down, 4);
    printf("\tCon redondeo a 4 decimales es: %0.4f\n", fx_4);
    return fx_4;
}
double function_with_series(double x)
{
    /* 
    Evalua la funcion usando sin y cos como serie de potencias
     */
    double fx;
    x = round_custom(x, 4);
    double cosx = round_custom(cos_with_series(x, 2), 4);
    double sinx = round_custom(sin_with_series(x, 2), 4);
    fx = round_custom(x * cosx * sinx, 4) / round_custom(x - sinx, 4);
    fx = round_custom(fx, 4);
    printf("\tCon series es: %0.4lf\n", fx);
    return fx;
}
double obtain_RD(double x, double y)
{
    double RD;
    RD = fabs(x - y) * 100 / y;
    return RD;
}
double calculate_limit(double x, double limit)
{
    double fi = function(x);
    double fs = function(-x);
    double diff = fabs(fs - fi);
    if (diff < 10e-6)
    {
        limit = (fi + fs) / 2;
        printf("es %lf\n", limit);
    }
    return limit;
}
void find_limit()
{
    double limit = -999;
    double x = 1;
    int i = 1;
    printf("El limite cuando f(x) tiende a cero ");
    while (limit == -999 && i < 16)
    {
        limit = calculate_limit(x, limit);
        x = x / 2;
        i++;
    }
    if (limit == -999)
    {
        printf("no existe\n");
    }
}
int main()
{
    find_limit();
    double x = 0.1;
    printf("El valor de f(x)\n");
    double fx_approx = function_with_series(x);
    double fx_4 = function_four_digits(x);
    double fx = function(x);
    double RD_fx_4 = obtain_RD(fx_4, fx);
    double RD_fx_approx = obtain_RD(fx_approx, fx);
    printf("La diferencia relativa de f(x)\n");
    printf("\tCon redondeo a 4 decimales es: %.4lf\n", RD_fx_4);
    printf("\tCon series es: %.4lf\n", RD_fx_approx);
    return 0;
}
