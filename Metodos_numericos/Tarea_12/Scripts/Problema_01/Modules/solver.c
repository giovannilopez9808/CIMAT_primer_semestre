#include "solver.h"
double *obtain_lambda_from_matrix(double *matrix, int *dimension)
{
    double *lambda = (double *)malloc(dimension[0] * sizeof(double));
    double *L_i, m_ii;
    for (int i = 0; i < dimension[0]; i++)
    {
        L_i = (lambda + i);
        m_ii = *(matrix + i * dimension[0] + i);
        *L_i = m_ii;
    }
    return lambda;
}
int convergence_eigen_QR(double *matrix, int *dimension, int attempt)
{
    double sum = 0, tau = 1e-6, m_ij;
    if (attempt != 0)
    {
        for (int i = 0; i < dimension[0] - 1; i++)
        {
            for (int j = i + 1; j < dimension[0]; j++)
            {
                m_ij = *(matrix + j * dimension[0] + i);
                sum += fabs(m_ij);
            }
        }
        if (sum < tau)
        {
            return 0;
        }
    }
    return 1;
}
void obtain_eigen_with_QR(double *matrix, double **lambda, double **vectors, int *dimension)
{
    double *q_matrix = NULL, *r_matrix = NULL;
    *vectors = create_identity_matrix(dimension);
    double *lambda_aux = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    double *vectors_aux = create_identity_matrix(dimension);
    int attemp = 0;
    copy_matrix(matrix,
                lambda_aux,
                dimension);
    while (convergence_eigen_QR(lambda_aux, dimension, attemp))
    {
        QR_decomposition(lambda_aux,
                         &r_matrix,
                         &q_matrix,
                         dimension);
        obtain_multiplication_matrix(r_matrix,
                                     q_matrix,
                                     lambda_aux,
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
        attemp++;
        free(q_matrix);
        free(r_matrix);
    }
    printf("Numero de iteraciones: %d\n", attemp);
    *lambda = obtain_lambda_from_matrix(lambda_aux,
                                        dimension);
    free(vectors_aux);
    free(lambda_aux);
}