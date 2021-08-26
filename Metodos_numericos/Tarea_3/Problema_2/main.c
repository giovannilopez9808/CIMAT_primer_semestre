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
    printf("El valor de f(x) es: %0.4f\n", fx);
    return fx;
}
double function_four_digits(double x)
{
    /* 
    Evalua la funcion redondeando cada termino a cuatro digitos
     */
    float sin_x = round_custom(sin(x), 4);
    float cos_x = round_custom(cos(x), 4);
    float x_4 = round_custom(x, 4);
    float up = round_custom(x_4 * sin_x * cos_x, 4);
    float down = round_custom(x_4 - sin_x, 4);
    double fx_4 = round_custom(up / down, 4);
    printf("El valor de f(x) redondeado a 4 decimales es: %0.4f\n", fx_4);
    return fx_4;
}
double function_with_series(double x)
{
    /* 
    Evalua la funcion usando sin y cos como serie de potencias
     */
    double fx;
    double cosx = cos_with_series(x, 3);
    double sinx = sin_with_series(x, 3);
    fx = x * cosx * sinx / (x - sinx);
    printf("El valor de f(x) con series es: %0.4f\n", fx);
    return fx;
}
double obtain_RD(double x, double y)
{
    double RD;
    RD = fabs(x - y) * 100 / y;
    return RD;
}
int main()
{
    double x = 0.1;
    double fx_approx = function_with_series(x);
    float fx_4 = function_four_digits(x);
    double fx = function(x);
    double RD_fx_4 = obtain_RD(fx_4, fx);
    double RD_fx_approx = obtain_RD(fx_approx, fx);
    printf("La RD con fx con redondeo a 4 decimales es: %.3lf\n", RD_fx_4);
    printf("La RD con fx con series es: %.3lf\n", RD_fx_approx);
    return 0;
}