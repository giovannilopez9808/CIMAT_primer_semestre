#include "solvers.h"
void copy_vector(double *vector, double *vector_i, int dimension[])
{
    /*
    Copia los valores del vector en el vector i
     */
    for (int i = 0; i < dimension[0]; i++)
    {
        *(vector_i + i) = *(vector + i);
    }
}
void initialize_vector(double *vector, int dimension[])
{
    /*
    Inicializa el vector dado con el valor 1/sqrt(n) en todos sus elementos
     */
    for (int i = 0; i < dimension[0]; i++)
    {
        *(vector + i) = 1 / sqrt(dimension[0]);
    }
}
int convergence_eigenvalues(double lambda, double lambda_i, int attempt)
{
    /*
    Compara los valores de lambda para ver si se llega a una convergencia del metodo
     */
    double theta;
    // En el primer inteno no se comprara ya que se supone que son iguales
    if (attempt != 0)
    {
        theta = fabs(lambda - lambda_i);
        if (theta < 1e-7)
        {
            // Si se cumple la convergencia regresa un 0
            return 0;
        }
    }
    // Si no la cumple devuelve un 1
    return 1;
}
void copy_vector_i(double *vectors, double *vector, int dimension[], int n)
{
    /*
    Copia del vector i en la matriz de eigenvectores
     */
    double *Vi_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        v_i = *(vectors + n * dimension[0] + i);
        Vi_i = vector + i;
        *Vi_i = v_i;
    }
}
void obatin_new_vector(double **vector, double *vectors, int dimension[], int n)
{
    /*
    Eliminacion de las contribuciones de los eigenvalores anteriores a el nuevo vector
     */
    double cdot;
    // Inicializacion del vector i
    double *vector_i = (double *)malloc(dimension[0] * sizeof(double));
    // Inicializacion del vector auxiliar
    double *vector_aux = (double *)malloc(dimension[0] * sizeof(double));
    // Copia de los vectores
    copy_vector(*vector, vector_aux, dimension);
    for (int i = 0; i < n; i++)
    {
        copy_vector_i(vectors, vector_i, dimension, i);
        // Producto punto de v_{i} y v
        cdot = obtain_cdot_multiplication(vector_i, *vector, dimension);
        for (int j = 0; j < dimension[0]; j++)
        {
            // Eliminacion de las contribuciones
            *(vector_aux + j) -= cdot * *(vector_i + j);
        }
    }
    // Copia del vector para obtener el resultado
    copy_vector(vector_aux, *vector, dimension);
    free(vector_aux);
    free(vector_i);
}
void copy_vectors(double **vectors, double *vector, int dimension[], int n)
{
    /*
    Copia del vector en la matriz de vectores unitarios
     */
    double *V_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        V_i = (*vectors + n * dimension[0] + i);
        v_i = *(vector + i);
        *V_i = v_i;
    }
}
void obtain_n_min_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas)
{

    /*
    Metodo de deflaccion, dada una matriz y su dimension se calcularan los n lambdas dadas maximas
     */
    // Inicializacion del espacio de valores
    *lambda = (double *)malloc(n_lambdas * sizeof(double));
    // Inicializacion de la matriz de eigenvectores
    *vectors = (double *)malloc(n_lambdas * dimension_matrix[0] * sizeof(double));
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    double *vector_j = (double *)malloc(dimension_matrix[0] * sizeof(double));
    double *vector_i = (double *)malloc(dimension_matrix[0] * sizeof(double));
    int dimension_vector[2] = {dimension_matrix[0], 1};
    double lambda_i, lambda_aux, up, down;
    // Procespo de factorizacion LU
    double *L, *U;
    obtain_LU_crout(matrix,
                    dimension_matrix,
                    &L,
                    &U);
    for (int i = 0; i < n_lambdas; i++)
    {
        // Inicializacion del vector i
        initialize_vector(vector_i,
                          dimension_matrix);
        //   Eliminacion de las contribuciones anteriores
        obatin_new_vector(&vector_i,
                          *vectors,
                          dimension_vector,
                          i);
        int attempt = 0;
        printf("Calculando eigenvalor numero: %d\n", i + 1);
        // Inicio del metodod de potencias
        while (convergence_eigenvalues(lambda_i,
                                       lambda_aux,
                                       attempt))
        {
            lambda_aux = lambda_i;
            copy_vector(vector_i,
                        vector_j,
                        dimension_vector);
            // Resuelve el sistema de ecuaciones
            solve_triangular_inferior_matrix(L,
                                             dimension_matrix,
                                             vector_i,
                                             &vector_aux);
            solve_triangular_superior_matrix(U,
                                             dimension_matrix,
                                             vector_aux,
                                             &vector_i);
            down = obtain_cdot_multiplication(vector_j, vector_i, dimension_vector);
            up = obtain_norm(vector_j, dimension_vector);
            lambda_i = (up * up) / down;
            normalize_vector(vector_i, dimension_vector);
            // Eliminacion de las contribuciones anteriores
            obatin_new_vector(&vector_i,
                              *vectors,
                              dimension_vector,
                              i);
            attempt += 1;
        }
        *(*lambda + i) = lambda_i;
        copy_vectors(vectors, vector_i, dimension_vector, i);
    }
    free(vector_aux);
    free(vector_i);
    free(vector_j);
    free(L);
    free(U);
}

void obtain_jaboci_elements(double *matrix, int dimension[], int pos[], double *jacobi_matrix)
{
    double m_ij, m_ii, m_jj, tau, c = 1, s = 0;
    m_ij = *(matrix + pos[1] * dimension[0] + pos[0]);
    m_ii = *(matrix + pos[0] * dimension[0] + pos[0]);
    m_jj = *(matrix + pos[1] * dimension[0] + pos[1]);
    if (m_ij != 0)
    {
        tau = (m_ii - m_jj) / (2 * m_ij);
        if (tau >= 0)
        {
            tau = 1 / (tau + sqrt(1 + tau * tau));
        }
        else
        {
            tau = -1 / (-tau + sqrt(1 + tau * tau));
        }
        c = 1 / sqrt(1 + tau * tau);
        s = c * tau;
    }
    *(jacobi_matrix + pos[0] * dimension[0] + pos[0]) = c;
    *(jacobi_matrix + pos[0] * dimension[0] + pos[1]) = s;
    *(jacobi_matrix + pos[1] * dimension[0] + pos[0]) = -s;
    *(jacobi_matrix + pos[1] * dimension[0] + pos[1]) = c;
}
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
void obtain_jacobi_matrix_T(double *matrix, double *matrix_T, int dimension[])
{
    double m_ii, m_ij;
    double *M_ii, *M_ij;
    for (int i = 0; i < dimension[0]; i++)
    {
        M_ii = (matrix_T + i * dimension[0] + i);
        m_ii = *(matrix + i * dimension[0] + i);
        *M_ii = m_ii;
        for (int j = i + 1; j < dimension[1]; j++)
        {
            M_ij = (matrix_T + i * dimension[0] + j);
            m_ij = *(matrix + j * dimension[0] + i);
            *M_ij = m_ij;
            M_ij = (matrix_T + j * dimension[0] + i);
            m_ij = *(matrix + i * dimension[0] + j);
            *M_ij = m_ij;
        }
    }
}
int convergence_eigenvaues_jacobi(double *matrix, int dimension[], int pos[])
{
    double m_ij;
    pos[0]=0;
    pos[1]=1;
    double max = fabs(*(matrix + pos[1]*dimension[0]+pos[0]));
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = i + 1; j < dimension[0]; j++)
        {
            m_ij = fabs(*(matrix + j * dimension[0] + i));
            if(m_ij>max) {
                max=m_ij;
                pos[0]=i;
                pos[1]=j;
            }
            m_ij = fabs(*(matrix + i * dimension[0] + j));
            if(m_ij>max) {
                max=m_ij;
                pos[0]=i;
                pos[1]=j;
            }
        }
    }
    if (max > 1e-6)
    {
        return 1;
    }
    return 0;
}
void find_max_jacobi(double *matrix, int dimension[], int pos[])
{
    pos[0] = 0;
    pos[1] = 1;
    double m_ij, max = fabs(*(matrix + pos[1] * dimension[0] + pos[0]));
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = i + 1; j < dimension[0]; j++)
        {
            m_ij = fabs(*(matrix + j * dimension[0] + i));
            if (m_ij > max)
            {
                max = m_ij;
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
}
void obtain_lambdas_from_matrix(double *matrix, int dimension[], double *lambda)
{
    double *Lambda_i, m_ii;
    for (int i = 0; i < dimension[0]; i++)
    {
        m_ii = *(matrix + i * dimension[0] + i);
        Lambda_i = (lambda + i);
        *Lambda_i = m_ii;
    }
}
void duplicate_vectors(double *vectors, double *vectors_aux,int dimension[])
{
    double *V_ij,v_ij;
    for(int i=0; i<dimension[0]; i++)
    {
        for(int j=0; j<dimension[1]; j++)
        {
            V_ij = (vectors+j*dimension[0]+i);
            v_ij = *(vectors_aux+j*dimension[0]+i);
            *V_ij =v_ij;
        }
    }
}
void obtain_eigenvalues_jacobi(double *matrix, int dimension[], double **lambda, double **vectors)
{
    double *jacobi_matrix = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    double *jacobi_matrix_T = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    double *matrix_aux = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    double *vectors_aux = (double*)malloc(dimension[0]*dimension[1]*sizeof(double));
    *vectors = (double*)malloc(dimension[0]*dimension[1]*sizeof(double));
    initialize_jacobi_matrix(*vectors,dimension);
    *lambda = (double *)malloc(dimension[0] * sizeof(double));
    int pos[2];
    while (convergence_eigenvaues_jacobi(matrix, dimension,pos))
    {
        initialize_jacobi_matrix(jacobi_matrix,
                                 dimension);
        obtain_jaboci_elements(matrix,
                               dimension,
                               pos,
                               jacobi_matrix);
        obtain_jacobi_matrix_T(jacobi_matrix,
                               jacobi_matrix_T,
                               dimension);
        obtain_multiplication_matrix(matrix,
                                     jacobi_matrix,
                                     matrix_aux,
                                     dimension,
                                     dimension);
        obtain_multiplication_matrix(jacobi_matrix_T,
                                     matrix_aux,
                                     matrix,
                                     dimension,
                                     dimension);
        obtain_multiplication_matrix(*vectors,
                                     jacobi_matrix,
                                     vectors_aux,
                                     dimension,
                                     dimension);
        duplicate_vectors(*vectors,
                          vectors_aux,
                          dimension);
    }
    obtain_lambdas_from_matrix(matrix,
                               dimension,
                               *lambda);
    free(jacobi_matrix);
    free(jacobi_matrix_T);
    free(matrix_aux);
    free(vectors_aux);
}
