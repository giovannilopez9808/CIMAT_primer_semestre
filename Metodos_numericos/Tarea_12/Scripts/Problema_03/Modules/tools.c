#include "tools.h"
/* 
Realiza la impresion de los resultados en un archivo
 */
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
/* 
Realiza la apertura y verificacion de un archivo
 */
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
/* 
Evalua la funcion dado una serie de puntos
 */
double *evaluate_f(double (*f)(double), double *x, int n)
{
    // Inicializacion de  los valores de f(x)
    double *y = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        *(y + i) = f(*(x + i));
    }
    return y;
}
/* 
Creacion de una serie de puntos dado un punto inicial, final y el numero de particiones en el intervalo
 */
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