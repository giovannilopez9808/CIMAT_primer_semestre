#include "functions.h"
/*
Realiza la impresion de las lineas en la terminal
 */
void print_lines()
{
    printf("----------------------");
    printf("----------------------\n");
}
/*
Realiza la impresion de las matrices en terminal
 */
void print_matrix(double *matrix, int *dimension_matrix)
{
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = 0; j < dimension_matrix[1]; j++)
        {
            printf("%lf\t", *(matrix + j * dimension_matrix[0] + i));
        }
        printf("\n");
    }
    printf("\n");
}
/*
Realiza la impresion de las matrices en un archivo
 */
void write_results(FILE *output, double *matrix, int *dimension)
{
    fprintf(output, "%d %d\n", dimension[0], dimension[1]);
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            fprintf(output, "%lf\t", *(matrix + j * dimension[0] + i));
        }
        fprintf(output, "\n");
    }
}/*
Realiza la impresion de las matrices en un archivo
 */
void write_matrix_results(FILE *output, double *matrix, int *dimension)
{
    fprintf(output, "%d %d\n", dimension[0], dimension[1]);
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            fprintf(output, "%d %d %lf\n",i,j,*(matrix + j * dimension[0] + i));
        }
    }
}
/*
Apertura y validacion del archivo
 */
FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("File error\n");
        exit(1);
    }
    return file;
}
/*
Lectura de las dimensiones de la matriz a partir de un archivo dado
inputs:
+ file: puntero del archivo
+ dimension: arreglo de dimension 2 de tipo entero
 */
void read_dimension(FILE *file, int dimension[])
{
    int a = fscanf(file,
                   "%d %d",
                   &dimension[0],
                   &dimension[1]);
    (void)a;
}
/*
Lectura de los datos de la matriz a partir de un archivo dado
inputs:
+ file: puntero del archivo
+ dimension: arreglo de dimension 2 de tipo entero
+ matrix: doble puntero de un tipo de dato double donde se alojaran los datos de la matriz
 */
void read_matrix(FILE *file, int dimension[], double **matrix)
{
    *matrix = (double *)malloc((dimension[0]) * (dimension[1]) * sizeof(double));
    int a;
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            a = fscanf(file, "%lf",
                       (*matrix + j * dimension[0] + i));
        }
    }
    (void)a;
}
/*
Realiza la multiplicacion de matrices
 */
void obtain_multiplication_matrix(double *A, double *B, double *AB, int dimension_matrix_A[], int dimension_matrix_B[])
{
    double a_ik, b_kj, *AB_ij;
    double sum;
    for (int i = 0; i < dimension_matrix_A[0]; i++)
    {
        for (int j = 0; j < dimension_matrix_B[1]; j++)
        {
            sum = 0;
            AB_ij = (AB + j * dimension_matrix_B[0] + i);
            for (int k = 0; k < dimension_matrix_B[0]; k++)
            {
                a_ik = *(A + k * dimension_matrix_A[0] + i);
                b_kj = *(B + j * dimension_matrix_B[0] + k);
                sum += a_ik * b_kj;
            }
            *AB_ij = sum;
        }
    }
}
/*
Creacion de la matriz identidad dada su dimension
 */
void identity_matrix(double *matrix, int *dimension)
{
    double *a_ij;
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            a_ij = (matrix + j * dimension[0] + i);
            *a_ij = 0.0;
            if (i == j)
            {
                *a_ij = 1.0;
            }
        }
    }
}
/*
Copia del vector i en la matriz de eigenvectores
*/
void obtain_vector_i(double *vectors, double *vector, int *dimension, int n)
{
    double *Vi_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        v_i = *(vectors + n * dimension[0] + i);
        Vi_i = vector + i;
        *Vi_i = v_i;
    }
}
/*
Copia del vector en la matriz de vectores unitarios
*/
void save_vector(double **vectors, double *vector, int *dimension, int n)
{
    double *V_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        V_i = (*vectors + n * dimension[0] + i);
        v_i = *(vector + i);
        *V_i = v_i;
    }
}
