#include "solvers.h"
void initialize_eigenvector(double *vector, int dimension)
{
    double *V_i;
    for (int i = 0; i < dimension; i++)
    {
        V_i = (vector + i);
        *V_i = 1 / sqrt(dimension);
    }
}
void Rayleigh_method(double *matrix, int dimension_matrix[], double *lambda, double **vector)
{
    (void)matrix;
    (void)lambda;
    int dimension_vector[2] = {dimension_matrix[0], 1};
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    *vector = (double *)malloc(dimension_matrix[0] * sizeof(double));
    initialize_eigenvector(*vector, dimension_matrix[0]);
    initialize_eigenvector(vector_aux, dimension_matrix[0]);
    obtain_multiplication_matrix(matrix,
                                 *vector,
                                 vector_aux,
                                 dimension_matrix,
                                 dimension_vector);
    for (int i = 0; i < dimension_vector[0]; i++)
    {
        printf("%lf\n", *(vector_aux + i));
    }
    print_matrix(vector_aux, dimension_vector);
}