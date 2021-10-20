#include "newton.h"
/*
Criterio para pararel algoritmo por diferencia relativa o diferencia absoluta
 */
double stopping_criteria(double x0, double x1)
{
    double diff = fabs(x1 - x0);
    double max_value = fmax(1.0, fabs(x1));
    return diff / max_value;
}
/*
Calculo del nuevo posible valor de la raiz siguiendo el algoritmo de newton
 */
double obtain_new_x_newton(double (*f)(double), double x)
{
    double df = obtain_h_derivative(f, x);
    // Variable auxiliar
    double aux = h_function(f, x) / df;
    x = x - aux;
    return x;
}
/*
Metodo de Newton para obtener la raiz de una funcion.
(*f) -> funcion que recibe un dato double y devuelve un double
x0 -> Valor aproximado de la raiz
 */
void newton_method(double (*f)(double), double tol_x, double tol_f, double x0)
{
    printf("Iteracion\tx\t\t|f(x)|\n");
    double df = 1;
    // Inicializacion de la variable de busqueda
    double x = x0 + 1;
    // Conteo de iteraciones
    int attempt = 0;
    while (stopping_criteria(x0, x) > tol_x && fabs(f(x)) > tol_f)
    {
        x0 = x;
        // Calculo de la derivada en x
        df = obtain_h_derivative(f, x);
        // Si la derivada es cercana a 0 el algoritmo se detiene
        if (fabs(df) < 1e-6)
        {
            break;
        }
        x = obtain_new_x_newton(f, x);
        attempt++;
        printf("   %d\t\t%lf\t%lf\n", attempt, x, f(x));
    }
    // Impresion de salida si la derivada es cercana a 0
    if (fabs(df) < 1e-6)
    {
        printf("\t\tAlgoritmo terminado por\n\t\tobtener una derivada cercana a 0 (%lf)\n", df);
        return;
    }
    // Impresion del resultado, si es que lo hubo
    printf("\nRaiz aproximada de la funcion:\nx = %lf\n", x);
}