#include "spline_cubic.h"
#include "tools.h"
// Obtiene los valores de distancia entre los puntos
void obtain_hi(double *x, double **h, int n)
{
    *h = (double *)malloc((n - 1) * sizeof(double));
    double *H_i, x_i, x_ii;
    for (int i = 0; i < n - 1; i++)
    {
        H_i = *h + i;
        x_i = *(x + i);
        x_ii = *(x + i + 1);
        // Diferencia entre los valores de x
        *H_i = x_ii - x_i;
    }
}
// Obtiene los valores de f_i necesarios para calcular el parametro c
void obtain_fi(double *a, double *h, double **f, int n)
{
    *f = (double *)malloc((n - 1) * sizeof(double));
    double *F_i, a_i, a_ii, a_iii, h_i, h_ii;
    for (int i = 1; i < n - 1; i++)
    {
        F_i = *f + i;
        a_i = *(a + i - 1);
        a_ii = *(a + i);
        a_iii = *(a + i + 1);
        h_i = *(h + i - 1);
        h_ii = *(h + i);
        *F_i = 3 * (a_iii - a_ii) / h_ii - 3 * (a_ii - a_i) / h_i;
    }
}
// Obtiene la matriz H y el vector G para calcular el vector de parametros c dada la ecuacion matricial Hc=G
void obtain_matrix_h(double *h, double *f, double **H_matrix, double **g, int n)
{
    int dimension[2] = {n + 1, n + 1};
    double *H_ij, h_i, h_ii;
    *H_matrix = create_identity_matrix(dimension);
    *g = (double *)malloc((n + 1) * sizeof(double));
    *(*g) = 0;
    *(*g + n) = 0;
    for (int i = 1; i < n - 1; i++)
    {
        *(*g + i) = *(f + i);
        h_i = *(h + (i - 1));
        h_ii = *(h + i);
        H_ij = (*H_matrix + i * dimension[0] + (i - 1));
        *H_ij = h_i;
        H_ij = (*H_matrix + i * dimension[0] + (i));
        *H_ij = 2 * (h_i + h_ii);
        H_ij = (*H_matrix + i * dimension[0] + (i + 1));
        *H_ij = h_ii;
    }
}
// Calcula el vector de parametros C usando la ecuacion diferencial Hc=G usando la factorizacion LU
void obtain_ci(double *h, double *f, double **c, int n)
{
    double *H_matrix, *g, *L, *U;
    int dimension[2] = {n + 1, n + 1};
    obtain_matrix_h(h, f, &H_matrix, &g, n);
    obtain_LU_crout(H_matrix, dimension, &L, &U);
    solve_with_LU(L, U, dimension, g, c);
    free(H_matrix);
    free(g);
    free(L);
    free(U);
}
// Calculo del vector de parametros d dado c y h
void obtain_di(double *c, double *h, double **d, int n)
{
    *d = (double *)malloc((n - 1) * sizeof(double));
    double *D_i, c_i, c_ii, h_i;
    for (int i = 0; i < n - 1; i++)
    {
        D_i = *d + i;
        c_i = *(c + i);
        c_ii = *(c + i + 1);
        h_i = *(h + i);
        *D_i = (c_ii - c_i) / (2 * h_i);
    }
}
// Calculo del vector de parametro b dado a,c y h
void obtain_bi(double *a, double *c, double *h, double **b, int n)
{
    *b = (double *)malloc((n - 1) * sizeof(double));
    double *B_i, a_i, a_ii, c_i, c_ii, h_i;
    for (int i = 0; i < n - 1; i++)
    {
        B_i = *b + i;
        a_i = *(a + i);
        a_ii = *(a + i + 1);
        c_i = *(c + i);
        c_ii = *(c + i + 1);
        h_i = *(h + i);
        *B_i = (a_ii - a_i) / h_i - (c_ii + 2 * c_i) * h_i / 3;
    }
}
// Obtiene todos los parametros usando el algoritmo de splice cubic
void obtain_parameters(double *x, double *y, double **b, double **c, double **d, int n)
{
    double *h, *f;
    obtain_hi(x, &h, n);
    obtain_fi(y, h, &f, n);
    obtain_ci(h, f, c, n);
    obtain_di(*c, h, d, n);
    obtain_bi(y, *c, h, b, n);
    free(h);
    free(f);
}
// Evalua x dados los parametros de la interpolacion en el intervalo x>=xi y x<=x_i+1
double evaluate(double x, double xi, double a, double b, double c, double d)
{
    double f = x - xi;
    return d * pow(f, 3) + c * pow(f, 2) + b * f + a;
}
// Evaluacion de la interpolacion dado un conjunto de valores de x
void spline_cubic_f(double *x, double **y, double *x_data, double *a, double *b, double *c, double *d, int n_data, int n)
{
    *y = (double *)malloc(n * sizeof(double));
    double *Y_i, x_i, x_ij, x_iij, a_i, b_i, c_i, d_i;
    // Recorrido para todos los valores de x
    for (int i = 0; i < n; i++)
    {
        x_i = *(x + i);
        Y_i = (*y + i);
        // Recorrido para la busqueda del intervalo
        for (int j = 0; j < n_data - 1; j++)
        {
            // x_i
            x_ij = *(x_data + j);
            // x_i+1
            x_iij = *(x_data + j + 1);
            // Veficiacion que x_i <= x <= x_i+1
            if ((x_i >= x_ij) && (x_i <= x_iij))
            {
                a_i = *(a + j);
                b_i = *(b + j);
                c_i = *(c + j);
                d_i = *(d + j);
                *Y_i = evaluate(x_i, x_ij, a_i, b_i, c_i, d_i);
                break;
            }
        }
    }
}
