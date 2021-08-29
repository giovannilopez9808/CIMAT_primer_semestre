#include "bisection.h"
#include "newton.h"
#include "secant.h"
double function_1(double x)
{
    return exp(x) + pow(2, -x) + 2 * cos(x) - 6;
}
double function_2(double x)
{
    return log(x - 1) + cos(x - 1);
}
void select_functions()
{
    double x0;
    double x1;
    switch (1)
    {
    case 1:
        x0 = 1.0;
        x1 = 2.0;
        printf("\n----------------------------------------\n");
        printf("Raices de la funcion 1 con el método:\n");
        bisection_method(function_1, x0, x1);
        newton_method(function_1, x0);
        secant_method(function_1, x0, x1);
    case 2:
        x0 = 1.3;
        x1 = 2.0;
        printf("\n----------------------------------------\n");
        printf("Raices de la funcion 2 con el método:\n");
        bisection_method(function_2, x0, x1);
        newton_method(function_2, x0);
        secant_method(function_2, x0, x1);
    default:
        break;
    }
}
int main()
{
    select_functions();
    return 0;
}