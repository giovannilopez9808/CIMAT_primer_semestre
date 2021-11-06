#include "Modules/tools.h"
#include "Modules/spline.h"
#include <math.h>
/* 
Funcion a interpolar
 */
double f(double x)
{
    return x * x - 4 * x + 10 + 2 * sin(10 * x) - 5 * cos(4 * x);
}
int main()
{
    // Direccion del output
    char file_output[50] = "Output/output.txt";
    FILE *output = open_file(file_output, "w");
    // Punto inicial, final, numero de particiones del input y  numero de puntos para el output.
    double xi = 0.0, xf = 5.0, n_data = 100, n = 200, *m, *b;
    // Creacion de los puntos para calular los parametros
    double *x_data = linspace(xi,
                              xf,
                              n_data);
    //   Creacion de los puntos para calcular la interpolacion
    double *x = linspace(xi,
                         xf,
                         n);
    //  Evaluacion de la funcion con los puntos del input
    double *y_data = evaluate_f(f,
                                x_data,
                                n_data);
    // Calcula los parametros de input
    spline_line(x_data,
                y_data,
                &m, &b,
                n_data);
    // Evalua una serie de puntos usando la interpolacion
    double *y = evaluate_spline(x,
                                n,
                                x_data,
                                m,
                                b,
                                n_data);
    // Impresion de los resultados
    print_results(output,
                  x,
                  y,
                  n);
    free(m);
    free(b);
    free(x);
    free(y);
    free(x_data);
    free(y_data);
    fclose(output);
    return 0;
}
