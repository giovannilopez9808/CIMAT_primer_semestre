#include "tools.h"
void print_matrix(double *matrix, int *dimension)
{
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            printf("%lf\t", *(matrix + j * dimension[0] + i));
        }
        printf("\n");
    }
    printf("\n");
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
void read_dimension(FILE *file, int *dimension)
{
    /*
    Lectura de las dimensiones de la matriz a partir de un archivo dado
    inputs:
    + file: puntero del archivo
    + dimension: arreglo de dimension 2 de tipo entero
     */
    int a = fscanf(file,
                   "%d %d",
                   &dimension[0],
                   &dimension[1]);
    (void)a;
}
void read_matrix(FILE *file, int *dimension, double **matrix)
{
    /*
    Lectura de los datos de la matriz a partir de un archivo dado
    inputs:
    + file: puntero del archivo
    + dimension: arreglo de dimension 2 de tipo entero
    + matrix: doble puntero de un tipo de dato double donde se alojaran los datos de la matriz
     */
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
void copy_matrix(double *matrix, double *matrix_copy, int *dimension)
{
    double m_ij, *M_ij;
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            M_ij = (matrix_copy + j * dimension[0] + i);
            m_ij = *(matrix + j * dimension[0] + i);
            *M_ij = m_ij;
        }
    }
}
double obtain_cdot_multiplication(double *vector1, double *vector2, int *dimension)
{
    /*
    Realiza el producto punto de dos vectores dados
     */
    double v_i, v_j, cdot = 0;
    for (int i = 0; i < dimension[0]; i++)
    {
        v_i = *(vector1 + i);
        v_j = *(vector2 + i);
        cdot += v_i * v_j;
    }
    return cdot;
}
/*
Copia del vector i de la matriz de eigenvectores
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