#include "Modules/tools.h"
#include "Modules/spline.h"
#include <math.h>
double f(double x)
{
    return x * x - 4 * x + 10 + 2 * sin(10 * x) - 5 * cos(4 * x);
}
int main()
{
    char file_output[50] = "Output/output.txt";
    FILE *output = open_file(file_output, "w");
    double xi = 0.0, xf = 5.0, n_data = 18, n = 100, *m, *b;
    double *x_data = linspace(xi,
                              xf,
                              n_data);
    double *x = linspace(xi,
                         xf,
                         n);
    double *y_data = evaluate_f(f,
                                x_data,
                                n_data);
    spline_line(x_data,
                y_data,
                &m, &b,
                n_data);
    double *y = evaluate_spline(x,
                                n,
                                x_data,
                                m,
                                b,
                                n_data);
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
