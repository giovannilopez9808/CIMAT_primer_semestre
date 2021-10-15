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
        copy_matrix(*vector, vector_aux, dimension_vector);
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
    print_lines();
    printf("El numero de iteraciones fue %d\n", attempt);
    print_lines();
    free(vector_aux);
}
void obtain_B_matrix(double *matrix, double *vectors, int *dimension_matrix, int *dimension_vector, double *matrix_B)
{
    double sum;
    double a_ik, b_kj, *AB_ij;
    int dimension[2] = {dimension_matrix[1], dimension_vector[1]};
    double *matrix_aux = (double *)malloc(dimension_matrix[1] * dimension_vector[1] * sizeof(double));
    obtain_multiplication_matrix(matrix,
                                 vectors,
                                 matrix_aux,
                                 dimension_matrix,
                                 dimension_vector);
    for (int i = 0; i < dimension_vector[1]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            sum = 0;
            AB_ij = (matrix_B + j * dimension[1] + i);
            // printf("%d,%d -> ", i, j);
            for (int k = 0; k < dimension[0]; k++)
            {
                a_ik = *(vectors + k * dimension_vector[0] + j);
                b_kj = *(matrix_aux + i * dimension[0] + k);
                sum += a_ik * b_kj;
                // printf("(%lf)(%lf)+", a_ik, b_kj);
            }
            *AB_ij = sum;
            // printf(" = %lf\n", sum);
        }
    }
    free(matrix_aux);
}
/*
    Inicializacion de la matrices de rotacion
     */
void initialize_jacobi_matrix(double *matrix, int dimension[])
{
    double *M_ii, *M_ij;
    for (int i = 0; i < dimension[0]; i++)
    {
        M_ii = (matrix + i * dimension[0] + i);
        *M_ii = 1;
        for (int j = i + 1; j < dimension[1]; j++)
        {
            M_ij = (matrix + i * dimension[0] + j);
            *M_ij = 0;
            M_ij = (matrix + j * dimension[0] + i);
            *M_ij = 0;
        }
    }
}
/* 
     Copia del vector i en la matriz de eigenvectores
      */
void copy_vector_i(double *vectors, double *vector, int dimension[], int n)
{
    double *Vi_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        v_i = *(vectors + n * dimension[0] + i);
        Vi_i = vector + i;
        *Vi_i = v_i;
    }
}

void Gram_Schmidt_normalize(double *vectors, int *dimension)
{
    double *vector_aux = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    double *vector_i = (double *)malloc(dimension[0] * sizeof(double));
    double *vector_j = (double *)malloc(dimension[0] * sizeof(double));
    int dimension_vector[2] = {dimension[0], 1};
    copy_matrix(vectors, vector_aux, dimension);
    double cdot, vaux_jk, *V_ik;
    // Desplazamiento de los vectores
    print_matrix(vectors, dimension);
    for (int i = 1; i < dimension[1]; i++)
    {
        // Desplazamiento con los demas vectores
        copy_vector_i(vectors,
                      vector_i,
                      dimension,
                      i);
        print_matrix(vector_i, dimension_vector);
        for (int j = 0; j < i; j++)
        {
            copy_vector_i(vectors,
                          vector_j,
                          dimension,
                          j);
            print_matrix(vector_j, dimension_vector);
            cdot = obtain_cdot_multiplication(vector_i,
                                              vector_j,
                                              dimension);
            for (int k = 0; k < dimension[0]; k++)
            {
                V_ik = (vector_aux + k * dimension[0] + i);
                vaux_jk = *(vector_j + k);
                *V_ik = *V_ik - cdot * vaux_jk;
            }
        }
    }
    copy_matrix(vector_aux, vectors, dimension);
    print_matrix(vectors, dimension);
}
void Sub_space_method(double *matrix, int *dimension_matrix, double *lambda, double **vector, int n)
{
    (void)lambda;
    (void)matrix;
    // Inicializacion de la matrices auxiliares
    int dimension_vector[2] = {dimension_matrix[1], n};
    *vector = (double *)malloc(dimension_vector[0] * dimension_vector[1] * sizeof(double));
    // int dimension_matrix_B[2] = {n, n};
    obtain_identity_matrix(*vector,
                           dimension_vector);
    Gram_Schmidt_normalize(*vector,
                           dimension_vector);
}