#include "tools.h"
// Funcion a interpolar
double f(double x)
{
    return x / (x * x + 1);
}
// Obtiene los puntos dada una funcion para realizar la interpolacion
void obtain_points(double **x, double **y, int n)
{
    double *X_i, *Y_i;
    // Creacion de la memoria
    *x = (double *)malloc(n * sizeof(double));
    *y = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        X_i = *x + i;
        Y_i = *y + i;
        // Puntos en x
        *X_i = ((double)i - 8) / 2;
        // Puntos en y
        *Y_i = f(*X_i);
    }
}
// Crea los puntos en x para evaluar en la interpolacion
void create_points(double xi, double xf, double **x, int n)
{
    *x = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        *(*x + i) = xi + (xf - xi) * (double)i / n;
    }
}
// Imprime los puntos evaluados en la interpolacion en un archivo
void print_results(FILE *file, double *x, double *y, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%lf %lf\n", x[i], y[i]);
    }
}
// Creacion de una matriz identidad
double *create_identity_matrix(int *dimension)
{
    double *matrix = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    double *M_ij;
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            M_ij = (matrix + j * dimension[0] + i);
            *M_ij = 0;
            if (i == j)
            {
                *M_ij = 1;
            }
        }
    }
    return matrix;
}
/*
Inicializa la matrix U con unos en la diagonal
inputs:
+ U: puntero del arreglo de la matriz U
+ dimension_matrix: arreglo de dos dimensiones que contiene el tamaño de la matriz
 */
void Fill_initial_values_U_matrix(double *U, int dimension_matrix[])
{
    double *U_ii;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {

        U_ii = (U + i * dimension_matrix[0] + i);
        *U_ii = 1;
    }
}
/*
Realiza la validacion del sistema de ecuaciones lineales
 */
void valid_solution(double number)
{
    if (number == 0)
    {
        printf("Sistema sin solución\n");
        exit(1);
    }
}
/*
Valida que la diagonal de la matriz L es diferente de cero
 */
void validate_l_ii(double l_ii)
{
    if (l_ii == 0)
    {
        printf("Matriz no apta para el método. l_ii = 0\n");
        exit(1);
    }
}
/*
Aplica la factorizacion LU aplicando la version de Crout
inputs:
+ matrix: puntero del arreglo que contiene lo datos de la matriz
+ dimension_matrix: puntero del arreglo de dos dimensiones que contiene el tamaño de la matriz
+ L: doble puntero que contendra la matriz L
+ U: doble puntero que contendra la matriz U
 */
void obtain_LU_crout(double *matrix, int dimension_matrix[], double **L, double **U)
{
    *L = (double *)malloc((dimension_matrix[0]) * dimension_matrix[1] * sizeof(double));
    *U = (double *)malloc((dimension_matrix[0]) * dimension_matrix[1] * sizeof(double));
    // Apunteadores para guardar cada valor
    double *L_ij, *U_ij;
    double sum_ij, l_ii, l_ik, u_kj, matrix_ij;
    // Inicializacion de la matriz U
    Fill_initial_values_U_matrix(*U,
                                 dimension_matrix);
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Procedimiento para obtener los elementos de la matriz L
        for (int j = i; j < dimension_matrix[1]; j++)
        {
            // Inicializacion de la suma
            sum_ij = 0;
            // Localizacion de la matriz L donde se calculara el elemento
            L_ij = (*L + j * dimension_matrix[0] + i);
            // Valor ij de la matriz
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            for (int k = 0; k <= i - 1; k++)
            {
                l_ik = *(*L + j * dimension_matrix[0] + k);
                u_kj = *(*U + k * dimension_matrix[0] + i);
                sum_ij += l_ik * u_kj;
            }
            // Guardado del valor de L_ij
            *L_ij = matrix_ij - sum_ij;
        }
        // Procedimiento para obtener el elemento ij de la matriz U
        l_ii = *(*L + i * dimension_matrix[0] + i);
        validate_l_ii(l_ii);
        for (int j = i + 1; j < dimension_matrix[0]; j++)
        {
            // Inicializacion de la suma
            sum_ij = 0;
            // Localizacion de la matriz U donde se calculara el elemento
            U_ij = (*U + i * dimension_matrix[0] + j);
            matrix_ij = *(matrix + j * dimension_matrix[0] + i);
            for (int k = 0; k < j - 1; k++)
            {
                l_ik = *(*L + i * dimension_matrix[0] + k);
                u_kj = *(*U + k * dimension_matrix[0] + j);
                sum_ij += l_ik * u_kj;
            }
            // Guardado del valor de L_ij
            *U_ij = (matrix_ij - sum_ij) / l_ii;
        }
    }
}
/*
Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular superior
inputs:
+ matrix: puntero de un arreglo de datos bidimensional
+ dimension_matrix: arreglo de enteros de dimension 2
+ results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
+ solutions: doble puntero de tipo double que alojara las soluciones del sistema
 */
void solve_triangular_superior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    double result_i, matrix_ii, matrix_ij, sum_ij;
    *solutions = (double *)malloc(dimension_matrix[0] * sizeof(double));
    for (int i = dimension_matrix[0] - 1; i >= 0; i--)
    {
        // Inicializacion del contador
        sum_ij = 0;
        // Obtiene el termino b_i
        result_i = *(results + i);
        // Obtiene el termino a_i
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Valida la solucion del sistema
        valid_solution(matrix_ii);
        for (int j = dimension_matrix[0] - 1; j > i; j--)
        {
            // Obtiene el termino a_ij
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            // Realiza la suma del producto de x_j*a_ij
            sum_ij += *(*solutions + j) * matrix_ij;
        }
        // Obtiene el termino x_i
        *(*solutions + i) = (result_i - sum_ij) / matrix_ii;
    }
}
/*
Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular inferior
inputs:
+ matrix: puntero de un arreglo de datos bidimensional
+ dimension_matrix: arreglo de enteros de dimension 2
+ results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
+ solutions: doble puntero de tipo double que alojara las soluciones del sistema
 */
void solve_triangular_inferior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    double result_i, matrix_ii, matrix_ij, sum_ij;
    *solutions = (double *)malloc(dimension_matrix[0] * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Inicializacion del contador
        sum_ij = 0;
        // Obtiene el termino b_i
        result_i = *(results + i);
        // Obtiene el termino a_ii
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Validacion de la existencia de la solucion
        valid_solution(matrix_ii);
        for (int j = 0; j < i; j++)
        {
            // Obtiene el termino a_ij
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            // Realiza la suma de los productos x_j*a_ij

            sum_ij += *(*solutions + j) * matrix_ij;
        }
        // Obtiene el termino x_i
        *(*solutions + i) = (result_i - sum_ij) / matrix_ii;
    }
}
/*
Realiza la solucion de un sistema de ecuaciones usando la factorizacion LU
 */
void solve_with_LU(double *L, double *U, int *dimension, double *results, double **solutions)
{
    double *vector_aux;
    // Resuelve la matrizm triangular inferior
    solve_triangular_inferior_matrix(L,
                                     dimension,
                                     results,
                                     &vector_aux);
    // Resuelve la triz triangular superior
    solve_triangular_superior_matrix(U,
                                     dimension,
                                     vector_aux,
                                     solutions);
    free(vector_aux);
}
