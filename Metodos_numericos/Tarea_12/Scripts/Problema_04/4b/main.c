#include "../Modules/tools.h"
#include "../Modules/spline_cubic.h"
int main()
{
    // Numero de puntos a generar para la interpolacion y la grafica
    int n_data = 10, n = 200;
    FILE *output;
    // Archivo de salida
    output = fopen("Output/output.txt", "w");
    double *t, *x, *y, *t_data, *t_dummy, *x_data, *y_data, *b_x, *c_x, *d_x, *b_y, *c_y, *d_y;
    // Creacion de los puntos para la interpolacion
    obtain_t_points(xt, &t_data, &x_data, n_data);
    obtain_t_points(yt, &t_dummy, &y_data, n_data);
    // Obtiene los parametros necesarios para la interpolacion
    obtain_parameters(t_data, x_data, &b_x, &c_x, &d_x, n_data);
    obtain_parameters(t_data, y_data, &b_y, &c_y, &d_y, n_data);
    // Crea los puntos para evaluar en la interpolacion
    create_points(t_data[0], t_data[n_data - 1], &t, n);
    // Evalua los puntos en la interpolacion
    spline_cubic_f(t, &x, t_data, x_data, b_x, c_x, d_x, n_data, n);
    spline_cubic_f(t, &y, t_data, y_data, b_y, c_y, d_y, n_data, n);
    // Escribe los puntos en un archivo
    print_results(output, x, y, n);
    free(x);
    free(y);
    free(t);
    free(x_data);
    free(y_data);
    free(t_data);
    free(t_dummy);
    free(b_x);
    free(c_x);
    free(d_x);
    free(b_y);
    free(c_y);
    free(d_y);
    fclose(output);
    return 0;
}
