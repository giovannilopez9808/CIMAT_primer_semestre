#include "qr.h"
double *obtain_sub_matrix(double *matrix, int *dimension_matrix, int n)
{
    double *sub_matrix = (double *)malloc((dimension_matrix[0] - n) * (dimension_matrix[0] - n) * sizeof(double));
    double *Sub_m_ij, m_ij;
    for (int i = n; i < dimension_matrix[0]; i++)
    {
        for (int j = n; j < dimension_matrix[0]; j++)
        {
            m_ij = *(matrix + j * dimension_matrix[0] + i);
            Sub_m_ij = (sub_matrix + j * dimension_matrix[0] + i);
            *Sub_m_ij = m_ij;
        }
    }
    return sub_matrix;
}
/*
Factorizacion QR
 */
void QR_decomposition(double *matrix, double *q_matrix, double *r_matrix, int *dimension)
{
    double *sub_matrix, *vector_i;
    int sub_dimension[2];
    double norm;
    for (int i = 0; i < dimension[0]; i++)
    {
        sub_dimension[0] = dimension[0] - i;
        sub_dimension[1] = dimension[1] - i;
        vector_i = (double *)malloc(sub_dimension[0] * sizeof(double));
        sub_matrix = obtain_sub_matrix(matrix,
                                       dimension,
                                       i);
        obtain_vector_i(sub_matrix,
                        vector_i,
                        sub_dimension,
                        0);
        norm = obtain_cdot_multiplication(vector_i,
                                          vector_i,
                                          sub_dimension);
        norm = sqrt(norm);
        free(sub_matrix);
    }
}