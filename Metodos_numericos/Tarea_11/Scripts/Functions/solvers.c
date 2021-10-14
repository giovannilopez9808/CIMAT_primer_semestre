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
void copy_vector(double *vector, double *vector_copy, int dimension)
{
    double v_ci, *V_i;
    for (int i = 0; i < dimension; i++)
    {
        v_ci = *(vector_copy + i);
        V_i = (vector + i);
        *V_i = v_ci;
    }
}
double Rayleigh_quotient(double *matrix, double *vector, int *dimension_matrix, int *dimension_vector)
{
    double quotient;
    double *vector_aux = (double *)malloc(dimension_vector[0] * sizeof(double));
    obtain_multiplication_matrix(matrix,
                                 vector,
                                 vector_aux,
                                 dimension_matrix,
                                 dimension_vector);
    double cdot_up = obtain_cdot_multiplication(vector,
                                                vector_aux,
                                                dimension_vector);
    double cdot_down = obtain_cdot_multiplication(vector,
                                                  vector,
                                                  dimension_vector);
    quotient = cdot_up / cdot_down;
    free(vector_aux);
    return quotient;
}
int convergence_rayleigh(double lambda, double lambda_aux, int attempt)
{
    double convergence;
    if (attempt != 0)
    {
        convergence = fabs(lambda - lambda_aux);
        if (convergence < 1e-7)
        {
            return 0;
        }
    }
    return 1;
}
void Rayleigh_method(double *matrix, int dimension_matrix[], double *lambda, double **vector)
{
    int dimension_vector[2] = {dimension_matrix[0], 1};
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    *vector = (double *)malloc(dimension_matrix[0] * sizeof(double));
    double lambda_aux = 0;
    int attempt = 0;
    initialize_eigenvector(*vector, dimension_matrix[0]);
    while (convergence_rayleigh(*lambda, lambda_aux, attempt))
    {
        *lambda = lambda_aux;
        copy_vector(vector_aux, *vector, dimension_vector[0]);
        obtain_multiplication_matrix(matrix,
                                     vector_aux,
                                     *vector,
                                     dimension_matrix,
                                     dimension_vector);
        lambda_aux = Rayleigh_quotient(matrix,
                                       *vector,
                                       dimension_matrix,
                                       dimension_vector);
        normalize_vector(*vector,
                         dimension_vector);
        attempt++;
    }
    free(vector_aux);
}