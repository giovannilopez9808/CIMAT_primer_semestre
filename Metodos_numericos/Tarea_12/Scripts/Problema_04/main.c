#include "Modules/tools.h"
#include "Modules/spline_cubic.h"
// #include <stdlib.h>
int main()
{
    // Numero de puntos a generar para la interpolacion y la grafica
    int n_data = 17, n = 50;
    FILE *output;
    // Archivo de salida
    output = fopen("output.txt", "w");
    double *x, *y, *x_data, *y_data, *b, *c, *d;
    // Creacion de los puntos para la interpolacion
    obtain_points(&x_data, &y_data, n_data);
    // Obtiene los parametros necesarios para la interpolacion
    obtain_parameters(x_data, y_data, &b, &c, &d, n_data);
    // Crea los puntos para evaluar en la interpolacion
    create_points(x_data[0], x_data[n_data - 1], &x, n);
    // Evalua los puntos en la interpolacion
    spline_cubic_f(x, &y, x_data, y_data, b, c, d, n_data, n);
    // Escribe los puntos en un archivo
    print_results(output, x, y, n);
    free(x);
    free(y);
    free(x_data);
    free(y_data);
    free(b);
    free(c);
    free(d);
    fclose(output);
    return 0;
}
