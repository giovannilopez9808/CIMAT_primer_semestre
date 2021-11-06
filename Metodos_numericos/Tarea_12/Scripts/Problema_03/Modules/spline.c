#include "spline.h"
double *evaluate_f(double (*f)(double), double *x, int n)
{
    double *y = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        *(y + i) = f(*(x + i));
    }
    return y;
}
void spline_line(double *x, double *y, double **m, double **b, int n)
{
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
        *Mi = (yii - yi) / (xii - xi);
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