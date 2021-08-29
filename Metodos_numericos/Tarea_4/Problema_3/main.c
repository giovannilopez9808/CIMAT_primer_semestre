#include "bisection.h"
#include "newton.h"
#include "secant.h"
void print_problem(double x0, double x1)
{
    printf("\n----------------------------------------\n");
    printf("Raices de la funcion en el intervalo\n[%lf,%lf] con el método:\n", x0, x1);
}
double middle(double x0, double x1)
{
    double x = (x0 + x1) / 2.0;
    return x;
}
double function(double x)
{
    return 230 * pow(x, 4) + 18 * pow(x, 3) + 9 * pow(x, 2) - 221 * x - 9;
}
void select_functions()
{
    double x0;
    double x1;
    double x_middle;
    switch (1)
    {
    case 1:
        x0 = -1.0;
        x1 = 0.0;
        x_middle = middle(x0, x1);
        print_problem(x0, x1);
        bisection_method(function, x0, x1);
        newton_method(function, x0);
        secant_method(function, x0, x1);
    case 2:
        x0 = 0.0;
        x1 = 1.0;
        x_middle = middle(x0, x1);
        print_problem(x0, x1);
        bisection_method(function, x0, x1);
        newton_method(function, x_middle);
        secant_method(function, x0, x1);
    default:
        break;
    }
}
int main()
{
    select_functions();
    return 0;
}