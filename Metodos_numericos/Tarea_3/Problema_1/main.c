#include <stdio.h>
#include <math.h>
void print_sign(double number)
{
    /* 
    Realiza la impresion del signo del coeficiente de la ecuacion
     */
    if (number > 0)
    {
        printf("+%lf ", fabs(number));
    }
    else
    {
        printf("-%lf ", fabs(number));
    }
}

void print_equation(double a, double b, double c)
{
    /* 
    Realiza la impresion de la ecuacion que se analizara
     */
    printf("Ecuación a analizar:\n ");
    print_sign(a);
    printf("x2 ");
    print_sign(b);
    printf("x ");
    print_sign(c);
    printf("\n\n");
}
float round_custom(double number, int decimal)
{
    /* 
    Realiza el redondeo de un numero dado los decimales
     */
    double ten_power = pow(10, decimal);
    return roundf(number * ten_power) / ten_power;
}
void obtain_root_with_four_digits(double a, double b, double c, double results[])
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
    results[0] = x1;
    results[1] = x2;
    printf("El resultado usando redondeando a cuatro digitos es:\nx1 = %lf\tx2 = %lf\n",
           x1,
           x2);
}
void obtain_root_with_rationalizing(double a, double b, double c, double results[])
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
    results[0] = x1;
    results[1] = x2;
    printf("El resultado usando la ecuacion racionalizada es:\nx1 = %lf\tx2 = %lf\n",
           x1,
           x2);
}
void obtain_AD_and_RD(double x, double y, double results[])
{
    /* 
    Realiza el calculo de la diferencia absoluta y relativa
     */
    double AD = fabs(y - x);
    double RD = fabs(AD * 100 / y);
    results[0] = AD;
    results[1] = RD;
}
void obtain_roots(double a, double b, double c, double results1[], double results2[])
{
    /* 
    Ejecuta los dos metodos de calculo de raices dados a,b,c
     */
    double results[2];
    printf("\n----------------------------------\n");
    print_equation(a, b, c);
    // Calculo de las raices con la ecuacion racionalizada
    obtain_root_with_rationalizing(a,
                                   b,
                                   c,
                                   results1);
    // Calculo de las raices con el redondeo a cuatro digitos
    obtain_root_with_four_digits(a,
                                 b,
                                 c,
                                 results2);
    printf("\nLa diferencia absoluta y RD es:\n");
    // Calculo de la AD y RD para x1
    obtain_AD_and_RD(results1[0],
                     results2[0],
                     results);
    printf("Para x1\n\t AD = %lf\t RD = %lf \n",
           results[0],
           results[1]);
    // Calculo de la AD y RD para x2
    obtain_AD_and_RD(results1[1],
                     results2[1],
                     results);
    printf("Para x2\n\t AD = %lf\t RD = %lf \n",
           results[0],
           results[1]);
}
void select_case()
{
    /* 
    Conjunto de dataset de prueba
     */
    double a, b, c;
    double results1[2], results2[2];
    switch (1)
    {

    case 1:
        /* 
    1/3 x^2 - 123/4 x + 1/6 = 0
     */
        a = 1.0 / 3.0;
        b = 123.0 / 4.0;
        c = -1.0 / 6.0;
        obtain_roots(a,
                     b,
                     c,
                     results1,
                     results2);
    case 2:
        /* 
    1/3 x^2 + 123/4 x - 1/6 = 0
     */
        a = 1.0 / 3.0;
        b = -123.0 / 4.0;
        c = 1.0 / 6.0;
        obtain_roots(a,
                     b,
                     c,
                     results1,
                     results2);
    default:
        break;
    }
}
int main()
{
    select_case();
    return 0;
}
