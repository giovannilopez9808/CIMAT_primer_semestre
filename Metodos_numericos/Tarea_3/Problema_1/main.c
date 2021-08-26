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
void obtain_root_with_four_digits(double a, double b, double c)
{
    /* 
    Realiza el calculo de las raices de una función cuadratica usando la ecuación cuadratica a cuatro digitos
     */
    a = round_custom(a, 4);
    b = round_custom(b, 4);
    c = round_custom(c, 4);
    double power_b = round_custom(b * b, 4);
    double ab4 = round_custom(-4 * a * c, 4);
    double square = round_custom(sqrt(power_b + ab4), 4);
    double x1 = round_custom(-b + square, 4) / round_custom(2 * a, 4);
    double x2 = round_custom(-b - square, 4) / round_custom(2 * a, 4);
    x1 = round_custom(x1, 4);
    x2 = round_custom(x2, 4);
    printf("El resultado usando redondeando a cuatro digitos es:\nx1 = %lf\tx2 = %lf\n", x1, x2);
}
void obtain_root_with_rationalizing(double a, double b, double c)
{
    /* 
    Realiza el calculo de las raices de una función cuadratica usando la ecuación cuadratica racionalizada
     */
    double discriminant = pow(b, 2) - 4 * a * c;
    double down1 = b + sqrt(discriminant);
    double down2 = b - sqrt(discriminant);
    double up = -2 * c;
    double x1 = up / down1;
    double x2 = up / down2;
    printf("El resultado usando la ecuacion racionalizada es:\nx1 = %lf\tx2 = %lf\n", x1, x2);
}
void obtain_roots(double a, double b, double c)
{
    /* 
    Ejecuta los dos metodos de calculo de raices dados a,b,c
     */
    printf("\n----------------------------------\n");
    obtain_root_with_rationalizing(a, b, c);
    obtain_root_with_four_digits(a, b, c);
    printf("\n----------------------------------\n");
}
void select_case()
{
    /* 
    Conjunto de dataset de prueba
     */
    double a;
    double b;
    double c;
    switch (1)
    {

    case 1:
        /* 
    1/3 x^2 - 123/4 x + 1/6 = 0
     */
        a = 1.0 / 3.0;
        b = 123.0 / 4.0;
        c = -1.0 / 6.0;
        obtain_roots(a, b, c);
    case 2:
        /* 
    1/3 x^2 + 123/4 x - 1/6 = 0
     */
        a = 1.0 / 3.0;
        b = -123.0 / 4.0;
        c = 1.0 / 6.0;
        obtain_roots(a, b, c);
    default:
        break;
    }
}
int main()
{
    select_case();
    return 0;
}