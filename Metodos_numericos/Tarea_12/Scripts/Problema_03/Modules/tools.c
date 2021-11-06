#include "tools.h"
void print_results(FILE *file, double *x, double *y, int n)
{
    double xi, yi;
    for (int i = 0; i < n; i++)
    {
        xi = *(x + i);
        yi = *(y + i);
        fprintf(file, "%lf %lf\n", xi, yi);
    }
}
FILE *open_file(char *filename, char *mode)
{
    /*
    Validacion del archivo
     */
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("File error\n");
        exit(1);
    }
    return file;
}
double *linspace(double xi, double xf, int n)
{
    double *x = (double *)malloc(n * sizeof(double));
    double x_i;
    for (int i = 0; i < n; i++)
    {
        x_i = xi + (xf - xi) * (double)i / (double)(n - 1);
        *(x + i) = x_i;
    }
    return x;
}