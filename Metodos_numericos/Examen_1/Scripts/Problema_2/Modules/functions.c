#include "functions.h"
void print_lines()
{
    /*
    Realiza la impresion de las lineas en la terminal
     */
    printf("----------------------");
    printf("----------------------\n");
}
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
void obtain_identity_matrix(double *matrix, int *dimension)
{
    double *a_ij;
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            a_ij = (matrix + j * dimension[0] + i);
            *a_ij = 0.0;
            *a_ij = 5;
            if (i == j)
            {
                *a_ij = 1.0;
            }
        }
    }
}