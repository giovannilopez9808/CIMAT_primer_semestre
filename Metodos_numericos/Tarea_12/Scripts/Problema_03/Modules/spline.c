#include "spline.h"
/* 
Realiza el calculo de los parametros usando el algoritmo de spline line dados una serie de puntos
 */
void spline_line(double *x, double *y, double **m, double **b, int n)
{
    // Inicializacion de la matrices de parametros
    *m = (double *)malloc((n - 1) * sizeof(double));
    *b = (double *)malloc((n - 1) * sizeof(double));
    double *Mi, *Bi, xi, xii, yi, yii;
    for (int i = 0; i < n - 1; i++)
    {
        Mi = *m + i;
        Bi = *b + i;
        xi = *(x + i);
        xii = *(x + i + 1);
        yi = *(y + i);
        yii = *(y + i + 1);
        // Calculo de la pendiente
        *Mi = (yii - yi) / (xii - xi);
        // Calculo de la ordenada al origen
        *Bi = yi - *Mi * xi;
    }
}
double *evaluate_spline(double *x, int n, double *x_data, double *m, double *b, int n_data)
{
    double *y = (double *)malloc(n * sizeof(double));
    double *Yi, xij, xiij, xi;
    for (int i = 0; i < n; i++)
    {
        xi = *(x + i);
        Yi = (y + i);
        for (int j = 0; j < n_data - 1; j++)
        {
            xij = *(x_data + j);
            xiij = *(x_data + j + 1);
            if ((xi >= xij) & (xi <= xiij))
            {
                *Yi = m[j] * xi + b[j];
            }
        }
    }
    return y;
}