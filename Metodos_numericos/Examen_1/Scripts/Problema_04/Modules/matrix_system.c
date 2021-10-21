#include "matrix_system.h"
double *create_matrix_system(int dimension)
{
    int values[5] = {-4, -8, 40, -8, -4}, n = -2, m;
    double *matrix = (double *)malloc(dimension * dimension * sizeof(double));
    double *M_ij;
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            M_ij = (matrix + j * dimension + i);
            *M_ij = 0;
        }
        for (int k = 0; k < 5; k++)
        {
            m = n + k + i;
            if (m >= 0 && m < dimension)
            {
                M_ij = (matrix + m * dimension + i);
                *M_ij = values[k];
            }
        }
    }
    return matrix;
}
