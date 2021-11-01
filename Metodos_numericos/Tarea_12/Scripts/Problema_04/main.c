#include "Modules/tools.h"
#include "Modules/spline_cubic.h"
// #include <stdlib.h>
int main()
{
    int n_data = 17, n = 50;
    FILE *output;
    output = fopen("output.txt", "w");
    double *x, *y, *x_data, *y_data, *b, *c, *d;
    obtain_points(&x_data, &y_data, n_data);
    obtain_parameters(x_data, y_data, &b, &c, &d, n_data);
    create_points(x_data[0], x_data[n_data - 1], &x, n);
    spline_cubic_f(x, &y, x_data, y_data, b, c, d, n_data, n);
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
