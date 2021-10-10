#include "solvers.h"
/*
    Copia los valores del vector en el vector i
     */
void copy_vector(double *vector, double *vector_i, int dimension[])
{
    for (int i = 0; i < dimension[0]; i++)
    {
        *(vector_i + i) = *(vector + i);
    }
}
/*
    Inicializa el vector dado con el valor 1/sqrt(n) en todos sus elementos
     */
void initialize_vector(double *vector, int dimension[])
{
    for (int i = 0; i < dimension[0]; i++)
    {
        *(vector + i) = 1 / sqrt(dimension[0]);
    }
}
/*
    Compara los valores de lambda para ver si se llega a una convergencia del metodo
     */
int convergence_eigenvalues(double lambda, double lambda_i, int attempt)
{
    double theta;
    // En el primer inteno no se comprara ya que se supone que son iguales
    if (attempt != 0)
    {
        theta = fabs(lambda - lambda_i);
        if (theta < 1e-6)
        {
            // Si se cumple la convergencia regresa un 0
            return 0;
        }
    }
    // Si no la cumple devuelve un 1
    return 1;
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
/*
    Eliminacion de las contribuciones de los eigenvalores anteriores a el nuevo vector
     */
void obatin_new_vector(double **vector, double *vectors, int dimension[], int n)
{
    double cdot;
    // Inicializacion del vector i
    double *vector_i = (double *)malloc(dimension[0] * sizeof(double));
    // Inicializacion del vector auxiliar
    double *vector_aux = (double *)malloc(dimension[0] * sizeof(double));
    // Copia del vector para ser recalculado
    copy_vector(*vector, vector_aux, dimension);
    for (int i = 0; i < n; i++)
    {
        obtain_vector_i(vectors, vector_i, dimension, i);
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
/*
    Copia del vector en la matriz de vectores unitarios
     */
void copy_vectors(double **vectors, double *vector, int dimension[], int n)
{
    double *V_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        V_i = (*vectors + n * dimension[0] + i);
        v_i = *(vector + i);
        *V_i = v_i;
    }
}
/*
    Metodo potencia inversa con deflaccion, dada una matriz y su dimension se calcularan los n lambdas minimas
     */
void obtain_n_min_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas)
{
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
            down = obtain_cdot_multiplication(vector_j,
                                              vector_i,
                                              dimension_vector);
            up = obtain_norm(vector_j,
                             dimension_vector);
            lambda_i = (up * up) / down;
            normalize_vector(vector_i,
                             dimension_vector);
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
/*
Obtiene los elementos que conformaran la matriz de rotacion
 */
void obtain_jaboci_elements(double *matrix, int dimension[], int pos[], double *jacobi_matrix)
{
    double m_ij, m_ii, m_jj;
    // Elementos de la matriz
    m_ij = *(matrix + pos[1] * dimension[0] + pos[0]);
    m_ii = *(matrix + pos[0] * dimension[0] + pos[0]);
    m_jj = *(matrix + pos[1] * dimension[0] + pos[1]);
    // Calculo del angulo
    double theta = atan2(2 * m_ij, m_ii - m_jj) / 2.0;
    // Cos(theta)
    double cos_theta = cos(theta);
    // SIn(theta)
    double sin_theta = sin(theta);
    // Elemento ii
    *(jacobi_matrix + pos[0] * dimension[0] + pos[0]) = cos_theta;
    // Elemento ij
    *(jacobi_matrix + pos[0] * dimension[0] + pos[1]) = sin_theta;
    // Elemento ji
    *(jacobi_matrix + pos[1] * dimension[0] + pos[0]) = -sin_theta;
    // Elemento jj
    *(jacobi_matrix + pos[1] * dimension[0] + pos[1]) = cos_theta;
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
Obtiene la posicion del elemento con mayor valor absoluto y checa si este es mayor o menor a la tolerancia definida.
 */
int convergence_eigenvaues_jacobi(double *matrix, int dimension[], int pos[])
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
/*
    Guarda la lambda calculada en su variable de resultados
     */
void save_lambda(double *matrix, int dimension[], double *lambda)
{
    double *Lambda_i, m_ii;
    for (int i = 0; i < dimension[0]; i++)
    {
        m_ii = *(matrix + i * dimension[0] + i);
        Lambda_i = (lambda + i);
        *Lambda_i = m_ii;
    }
}
/*
 Realiza la rotacion de las matrices calculando unicamente los elementos que se veran afectados
 */
void rotate_matrix(double *matrix, double *vectors, int dimension[], int pos[], double cos_theta, double sin_theta)
{
    double *M_ij, *M_ji, *V_ij, *V_ji;
    double m_ij, v_ij;
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
Obtiene todos los eigenvalores con sus respectivos eigenvectores usando el metodo de Jacobi
 */
void obtain_eigenvalues_jacobi(double *matrix, int dimension[], double **lambda, double **vectors)
{
    // Inicializacion de la matrices auxiliares
    double *jacobi_matrix = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    // Inicializacion del espacio de los eigenvectores
    *vectors = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    initialize_jacobi_matrix(*vectors, dimension);
    // Inicializacion del espacio de los eigenvalores
    *lambda = (double *)malloc(dimension[0] * sizeof(double));
    double cos_theta, sin_theta;
    int pos[2];
    while (convergence_eigenvaues_jacobi(matrix, dimension, pos))
    {
        // Inicializacion de la matriz de rotacion
        initialize_jacobi_matrix(jacobi_matrix,
                                 dimension);
        // Obtiene los elementos de la rotacion
        obtain_jaboci_elements(matrix,
                               dimension,
                               pos,
                               jacobi_matrix);
        //    Cos y sin del angulo de rotacion
        cos_theta = *(jacobi_matrix + pos[0] * dimension[0] + pos[0]);
        sin_theta = *(jacobi_matrix + pos[0] * dimension[0] + pos[1]);
        // Rotacion de la matriz
        rotate_matrix(matrix,
                      *vectors,
                      dimension,
                      pos,
                      cos_theta,
                      sin_theta);
    }
    // Guardado de los eigenvalores
    save_lambda(matrix,
                dimension,
                *lambda);
    free(jacobi_matrix);
}
