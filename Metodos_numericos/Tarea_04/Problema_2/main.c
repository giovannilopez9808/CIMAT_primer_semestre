#include "bisection.h"
#include "newton.h"
#include "secant.h"
void print_problem(int function, double x0, double x1)
{
    /* 
    Header del problema
     */
    printf("\n----------------------------------------\n");
    printf("Raices de la funcion %d en el intervalo\n[%lf,%lf] con el método:\n", function, x0, x1);
}
double middle(double x0, double x1)
{
    /* 
    Calculo del punto medio
     */
    double x = (x0 + x1) / 2.0;
    return x;
}
double function_1(double x)
{
    /* 
    Definicion de la funcion 1
     */
    return exp(x) + pow(2, -x) + 2 * cos(x) - 6;
}
double function_2(double x)
{
    /* 
    Definicion de la funcion 2
     */
    return log(x - 1) + cos(x - 1);
}
void select_functions(int choice)
{
    double x0;
    double x1;
    double x_middle;
    int case_function;
    switch (choice)
    {
    case 1:
        // Parametros para obtener las respuestas del problema con la funcion 1
        x0 = 1.0;
        x1 = 2.0;
        x_middle = middle(x0, x1);
        case_function = 1;
        print_problem(case_function, x0, x1);
        // Aplicacion del metodo de biseccion
        bisection_method(function_1, x0, x1);
        // Aplicacion del metodo de newton
        newton_method(function_1, x_middle);
        // Aplicacion del metodo de secante
        secant_method(function_1, x0, x1);
        break;
    case 2:
        // Parametros para obtener las respuestas del problema con la funcion 2
        x0 = 1.3;
        x1 = 2.0;
        x_middle = middle(x0, x1);
        case_function = 2;
        print_problem(case_function, x0, x1);
        // Aplicacion del metodo de biseccion
        bisection_method(function_2, x0, x1);
        // Aplicacion del metodo de newton
        newton_method(function_2, x_middle);
        // Aplicacion del metodo de secante
        secant_method(function_2, x0, x1);
        break;
    default:
        break;
    }
}
int main()
{
    for (int choice = 1; choice <= 2; choice++)
    {
        select_functions(choice);
    }

    return 0;
}