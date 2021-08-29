#include "bisection.h"
#include "newton.h"
#include "secant.h"
void print_problem(int function, double x0, double x1)
{
    printf("\n----------------------------------------\n");
    printf("Raices de la funcion %d en el intervalo\n[%lf,%lf] con el método:\n", function, x0, x1);
}
double middle(double x0, double x1)
{
    double x = (x0 + x1) / 2.0;
    return x;
}
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
    double x_middle;
    int case_function;
    switch (1)
    {
    case 1:
        x0 = 1.0;
        x1 = 2.0;
        x_middle = middle(x0, x1);
        case_function = 1;
        print_problem(case_function, x0, x1);
        bisection_method(function_1, x0, x1);
        newton_method(function_1, x_middle);
        secant_method(function_1, x0, x1);
    case 2:
        x0 = 1.3;
        x1 = 2.0;
        x_middle = middle(x0, x1);
        case_function = 2;
        print_problem(case_function, x0, x1);
        bisection_method(function_2, x0, x1);
        newton_method(function_2, x_middle);
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