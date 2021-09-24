#include "functions.h"
#include <stdio.h>
void print_lines()
{
    printf("\n----------------------------------\n");
}
double function(double x)
{
    /* 
    Evalua la funcion en x
     */
    double down = x - sin(x);
    double up = x * cos(x) - sin(x);
    // Descomentar para obtener un límite que no existe y comentar la linea de  arriba
    // double up = x * cos(x) * sin(x);
    double fx = up / down;
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
    float up = round_custom(x_4 * cos_x - sin_x, 4);
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
    fx = round_custom(x * cosx - sinx, 4) / round_custom(x - sinx, 4);
    fx = round_custom(fx, 4);
    printf("\tCon series es: %0.4lf\n", fx);
    return fx;
}
double obtain_RD(double x, double y)
{
    /* 
    Obtiene la diferencia relativa de dos datos, se da por verdadera la y
     */
    double RD;
    RD = fabs(x - y) * 100 / fabs(y);
    return RD;
}
double calculate_limit(double x, double *diff)
{
    /* 
    Evalua la funcion dada un valor de x. Se tomara su valor de signo contrario para evaluarlo por la izquieda o derecha. 
     */
    // Limite por la derecha
    double fi = function(x);
    // Limite por la izquierda
    double fs = function(-x);
    // Impresion de los valores en terminal
    printf("%lf\t%lf\t%lf\t%lf\n", -x, fs, x, fi);
    double limit;
    *diff = fabs(fs - fi);
    // Calculo del limite si la diferencia es mayor a 10^-6
    if (*diff < 1e-6)
    {
        limit = (fs + fi) / 2;
    }
    // Si no, se da un valor arbitrario
    else
    {
        limit = 1;
    }
    return limit;
}
void find_limit()
{
    // Inicializacion de la diferencia y el limite
    double diff = 1;
    double limit = 1;
    // Inicio del intervalo [-x,x]
    double x = 1;
    // Impresion de los headers
    printf("x\t\tLi\t\tx\t\tLs\n");
    for (int i = 0; i < 12; i++)
    {
        limit = calculate_limit(x, &diff);
        // Reduccion del intervalo
        x = x / 2;
    }
    printf("\nEl limite cuando f(x) tiende a cero ");
    // Si el limite no existe se imprimira que no existe
    if (diff > 1e-6)
    {
        printf("no existe\n");
    }
    // Si existe entonces se imprimesu valor
    else
    {
        printf("es %lf\n", limit);
    }
}
void print_RD(double fx, double fx_rounded, double fx_series)
{
    // Calculo de las diferencias relativas
    double RD_fx_rounded = obtain_RD(fx_rounded, fx);
    double RD_fx_series = obtain_RD(fx_series, fx);
    print_lines();
    // Impresion de
    printf("La diferencia relativa de f(x)\n");
    printf("\tCon redondeo a 4 decimales es: %.4lf\n", RD_fx_rounded);
    printf("\tCon series es: %.4lf\n", RD_fx_series);
}
int main()
{
    print_lines();
    // Busqueda del limite
    find_limit();
    double x = 0.1;
    print_lines();
    printf("El valor de f(x)\n");
    // Evaluacion de las funciones redondeando a cuatro digitos y por serie
    double fx_series = function_with_series(x);
    double fx_rounded = function_four_digits(x);
    // Valor exacto de la funcion
    double fx = function(x);
    // Calculo de las diferencias relativas
    print_RD(fx, fx_rounded, fx_series);
    return 0;
}
