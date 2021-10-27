#include "solver.h"
void obtain_eigen_with_QR(double *matrix, double **lambda, double **vectors, int *dimension)
{
    double *q_matrix = NULL, *r_matrix = NULL;
    *lambda = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    *vectors = create_identity_matrix(dimension);
    double *vectors_aux = create_identity_matrix(dimension);
    copy_matrix(matrix,
                *lambda,
                dimension);
    for (int i = 0; i < 30; i++)
    {
        QR_decomposition(*lambda,
                         &r_matrix,
                         &q_matrix,
                         dimension);
        obtain_multiplication_matrix(r_matrix,
                                     q_matrix,
                                     *lambda,
                                     dimension,
                                     dimension);
        obtain_multiplication_matrix(*vectors,
                                     q_matrix,
                                     vectors_aux,
                                     dimension,
                                     dimension);
        copy_matrix(vectors_aux,
                    *vectors,
                    dimension);
        free(q_matrix);
        free(r_matrix);
    }
    print_matrix(*lambda,
                 dimension);
    print_matrix(*vectors,
                 dimension);
    free(vectors_aux);
}