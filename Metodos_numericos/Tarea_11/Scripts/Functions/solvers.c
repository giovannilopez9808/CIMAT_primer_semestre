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
                a_ik = *(vectors + i * dimension_vector[0] + k);
                b_kj = *(matrix_aux + j * dimension[0] + k);
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
void obtain_vector_i(double *vectors, double *vector, int dimension[], int n)
{
    double *Vi_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        v_i = *(vectors + n * dimension[0] + i);
        Vi_i = vector + i;
        *Vi_i = v_i;
    }
}
void fill_vectors_solution(double *vectors, double *vector, int *dimension, int n)
{
    double *Vi_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        Vi_i = (vectors + n * dimension[0] + i);
        v_i = *(vector + i);
        *Vi_i = v_i;
    }
}
void Gram_Schmidt_normalize(double *vectors, int *dimension)
{
    double *vector_aux = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    double *vector_i = (double *)malloc(dimension[0] * sizeof(double));
    double *vector_j = (double *)malloc(dimension[0] * sizeof(double));
    // int dimension_vector[2] = {dimension[0], 1};
    copy_matrix(vectors, vector_aux, dimension);
    double cdot, vaux_jk, *V_ik;
    // Desplazamiento de los vectores
    for (int i = 1; i < dimension[1]; i++)
    {
        // Desplazamiento con los demas vectores
        obtain_vector_i(vectors,
                        vector_i,
                        dimension,
                        i);
        for (int j = 0; j < i; j++)
        {
            obtain_vector_i(vectors,
                            vector_j,
                            dimension,
                            j);
            cdot = obtain_cdot_multiplication(vector_i,
                                              vector_j,
                                              dimension);
            for (int k = 0; k < dimension[0]; k++)
            {

                V_ik = (vector_aux + i * dimension[0] + k);
                vaux_jk = *(vector_j + k);
                *V_ik = *V_ik - cdot * vaux_jk;
            }
        }
    }
    copy_matrix(vector_aux, vectors, dimension);
    for (int i = 0; i < dimension[1]; i++)
    {
        // Desplazamiento con los demas vectores
        obtain_vector_i(vectors,
                        vector_i,
                        dimension,
                        i);
        cdot = obtain_norm(vector_i,
                           dimension);
        for (int j = 0; j < dimension[0]; j++)
        {
            V_ik = (vectors + i * dimension[0] + j);
            *V_ik /= cdot;
        }
    }
    free(vector_i);
    free(vector_j);
    free(vector_aux);
}
void solve_system(double *L, double *U, double *vectors, int *dimension_matrix, int *dimension_vector)
{
    double *vector_aux = (double *)malloc(dimension_vector[0] * dimension_vector[1] * sizeof(double));
    double *vector_i = (double *)malloc(dimension_vector[0] * sizeof(double));
    double *vector_sol = (double *)malloc(dimension_vector[0] * sizeof(double));
    for (int i = 0; i < dimension_vector[1]; i++)
    {
        obtain_vector_i(vectors,
                        vector_i,
                        dimension_vector,
                        i);
        // Resuelve el sistema de ecuaciones
        solve_triangular_inferior_matrix(L,
                                         dimension_matrix,
                                         vector_i,
                                         &vector_sol);
        solve_triangular_superior_matrix(U,
                                         dimension_matrix,
                                         vector_sol,
                                         &vector_i);
        fill_vectors_solution(vector_aux,
                              vector_i,
                              dimension_matrix,
                              i);
    }
    copy_matrix(vector_aux, vectors, dimension_vector);
    free(vector_i);
    free(vector_aux);
    free(vector_sol);
}
/*
 Realiza la rotacion de las matrices calculando unicamente los elementos que se veran afectados
 */
void rotate_matrix(double *matrix, double *vectors, int dimension[], int pos[], double theta)
{
    double *M_ij, *M_ji, *V_ij, *V_ji;
    double m_ij, v_ij, sin_theta, cos_theta;
    sin_theta = sin(theta);
    cos_theta = cos(theta);
    for (int i = 0; i < dimension[0]; i++)
    {
        m_ij = *(matrix + pos[0] * dimension[0] + i);
        M_ij = (matrix + pos[0] * dimension[0] + i);
        M_ji = (matrix + pos[1] * dimension[0] + i);
        v_ij = *(vectors + pos[0] * dimension[0] + i);
        V_ij = (vectors + pos[0] * dimension[0] + i);
        V_ji = (vectors + pos[1] * dimension[0] + i);
        *M_ij = m_ij * cos_theta + *M_ji * sin_theta;
        *M_ji = -m_ij * sin_theta + *M_ji * cos_theta;
        *V_ij = v_ij * cos_theta + *V_ji * sin_theta;
        *V_ji = -v_ij * sin_theta + *V_ji * cos_theta;
    }
    for (int i = 0; i < dimension[0]; i++)
    {
        m_ij = *(matrix + i * dimension[0] + pos[0]);
        M_ij = (matrix + i * dimension[0] + pos[0]);
        M_ji = (matrix + i * dimension[0] + pos[1]);
        *M_ij = m_ij * cos_theta + *M_ji * sin_theta;
        *M_ji = -m_ij * sin_theta + *M_ji * cos_theta;
    }
}
/*
Obtiene los elementos que conformaran la matriz de rotacion
 */
double obtain_jacobi_angle(double *matrix, int *dimension, int *pos)
{
    double m_ij, m_ii, m_jj;
    // Elementos de la matriz
    m_ij = *(matrix + pos[1] * dimension[0] + pos[0]);
    m_ii = *(matrix + pos[0] * dimension[0] + pos[0]);
    m_jj = *(matrix + pos[1] * dimension[0] + pos[1]);
    // Calculo del angulo
    double theta = atan2(2 * m_ij, m_ii - m_jj) / 2.0;
    return theta;
}
/*
Obtiene la posicion del elemento con mayor valor absoluto y checa si este es mayor o menor a la tolerancia definida.
 */
int obtain_max_position(double *matrix, int *dimension, int *pos)
{
    double m_ij;
    // Se supone que el elemento mayor se encuentra en la posicon i=1 j=2
    pos[0] = 0;
    pos[1] = 1;
    double max = fabs(*(matrix + pos[1] * dimension[0] + pos[0]));
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = i + 1; j < dimension[0]; j++)
        {
            // Elemento ij
            m_ij = fabs(*(matrix + j * dimension[0] + i));
            // Si es mayor se actualiza la informacion
            if (m_ij > max)
            {
                max = m_ij;
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
    // Si es mayor a la tolerancia el metodo sigue
    if (max > 1e-6)
    {
        return 1;
    }
    // Si no, el metodo de detiene
    return 0;
}
void Sub_space_method(double *matrix, int *dimension_matrix, double *lambda, double **vector, int n)
{
    (void)lambda;
    // Inicializacion de la matrices auxiliares
    int dimension_vector[2] = {dimension_matrix[1], n};
    int pos[2], dimension_matrix_B[2] = {n, n};
    *vector = (double *)malloc(dimension_vector[0] * dimension_vector[1] * sizeof(double));
    double *matrix_B = (double *)malloc(n * n * sizeof(double));
    // Procespo de factorizacion LU
    double *L, *U, theta;
    obtain_LU_crout(matrix,
                    dimension_matrix,
                    &L,
                    &U);
    obtain_identity_matrix(*vector,
                           dimension_vector);
    for (int i = 0; i < 1000; i++)
    {

        Gram_Schmidt_normalize(*vector,
                               dimension_vector);
        solve_system(L,
                     U,
                     *vector,
                     dimension_matrix,
                     dimension_vector);
        Gram_Schmidt_normalize(*vector,
                               dimension_vector);
        obtain_B_matrix(matrix,
                        *vector,
                        dimension_matrix,
                        dimension_vector,
                        matrix_B);
        obtain_max_position(matrix_B,
                            dimension_matrix_B,
                            pos);
        theta = obtain_jacobi_angle(matrix_B,
                                    dimension_matrix_B,
                                    pos);
        rotate_matrix(matrix_B,
                      *vector,
                      dimension_matrix_B,
                      pos, theta);
        Gram_Schmidt_normalize(*vector,
                               dimension_vector);
        Gram_Schmidt_normalize(*vector,
                               dimension_vector);
    }
    print_matrix(matrix_B, dimension_matrix_B);
    print_matrix(*vector, dimension_vector);
    free(L);
    free(U);
    free(matrix_B);
}