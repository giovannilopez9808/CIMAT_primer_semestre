#include "bisection.h"
#include "newton.h"
#include "secant.h"
void print_problem(double x0, double x1)
{
    /* 
    Header del problema
     */
    printf("\n----------------------------------------\n");
    printf("Raices de la funcion en el intervalo\n[%lf,%lf] con el método:\n", x0, x1);
}
double middle(double x0, double x1)
{
    /* 
    Definicion del punto medio
     */
    double x = (x0 + x1) / 2.0;
    return x;
}
double function(double x)
{
    /* 
    Defincion de la funcion
     */
    return 230 * pow(x, 4) + 18 * pow(x, 3) + 9 * pow(x, 2) - 221 * x - 9;
}
void select_functions(int choice)
{
    double x0;
    double x1;
    double x_middle;
    switch (choice)
    {
    case 1:
        // Parametros para obtener la solucion en el intervalo [-1,0]
        x0 = -1.0;
        x1 = 0.0;
        x_middle = middle(x0, x1);
        print_problem(x0, x1);
        // Aplicacion del metodo de biseccion
        bisection_method(function, x0, x1);
        // Aplicacion del metodo de newton
        newton_method(function, x_middle);
        // Aplicacion del metodo de secante
        secant_method(function, x0, x1);
        break;
    case 2:
        // Parametros para obtener la solucion en el intervalo [0,1]
        x0 = 0.0;
        x1 = 1.0;
        x_middle = middle(x0, x1);
        print_problem(x0, x1);
        // Aplicacion del metodo de biseccion
        bisection_method(function, x0, x1);
        // Aplicacion del metodo de newton
        newton_method(function, x_middle);
        // Aplicacion del metodo de secante
        secant_method(function, x0, x1);
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