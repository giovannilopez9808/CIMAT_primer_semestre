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
void obtain_max_eigenvalue(double *matrix, int dimension_matrix[], double *lambda, double **vector)
{
    /* 
    Metodo de las potencias, recibe una matriz y su dimension y devuelve su eigenvalor dominante con su respectito eigenvector
     */
    // Inicializacion del vector auxiliar
    double *vector_i = (double *)malloc(dimension_matrix[0] * sizeof(double));
    int attempt = 0;
    double lambda_i, up, down;
    int dimension_vector[2] = {dimension_matrix[0], 1};
    // Inicializacion del eigenvector de resultados
    *vector = (double *)malloc(dimension_matrix[0] * sizeof(double));
    initialize_vector(*vector,
                      dimension_matrix);
    while (convergence_eigenvalues(*lambda,
                                   lambda_i,
                                   attempt))
    {
        lambda_i = *lambda;
        // Copia del vector
        copy_vector(*vector,
                    vector_i,
                    dimension_vector);
        // Realiza la multiplicacion de v_i =  A*v_{i-1}
        obtain_multiplication_matrix(matrix,
                                     vector_i,
                                     *vector,
                                     dimension_matrix,
                                     dimension_vector);
        // Producto punto de v_{i-1} y v_i
        up = obtain_cdot_multiplication(*vector, vector_i, dimension_vector);
        // Norma de v_{i-1}
        down = obtain_norm(vector_i, dimension_vector);
        // Normalizacion de v_i
        normalize_vector(*vector, dimension_vector);
        // Calculo de lambda
        *lambda = up / (down * down);
        attempt += 1;
    }
    free(vector_i);
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
void obtain_n_max_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas)
{

    /* 
    Metodo de deflaccion, dada una matriz y su dimension se calcularan los n lambdas dadas maximas
     */
    // Inicializacion del espacio de valores
    *lambda = (double *)malloc(n_lambdas * sizeof(double));
    // Inicializacion de la matriz de eigenvectores
    *vectors = (double *)malloc(n_lambdas * dimension_matrix[0] * sizeof(double));
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    double *vector_i = (double *)malloc(dimension_matrix[0] * sizeof(double));
    int dimension_vector[2] = {dimension_matrix[0], 1};
    double lambda_i, lambda_aux, up, down;
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
        // Inicio del metodod de potencias
        while (convergence_eigenvalues(lambda_i,
                                       lambda_aux,
                                       attempt))
        {
            lambda_aux = lambda_i;
            copy_vector(vector_i,
                        vector_aux,
                        dimension_vector);
            obtain_multiplication_matrix(matrix,
                                         vector_aux,
                                         vector_i,
                                         dimension_matrix,
                                         dimension_vector);
            up = obtain_cdot_multiplication(vector_i,
                                            vector_aux,
                                            dimension_vector);
            down = obtain_norm(vector_aux,
                               dimension_vector);
            lambda_i = up / (down * down);
            normalize_vector(vector_i,
                             dimension_vector);
            //   Eliminacion de las contribuciones anteriores
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
}
void obtain_min_eigenvalue(double *matrix, int dimension_matrix[], double *lambda, double **vector)
{
    /* 
    ada una matrix y su tamaño obtiene el eigenvalor menor absoluto y su respectivo eigenvector
     */
    double lambda_i, down, up;
    int attempt = 0;
    double *vector_i = (double *)malloc(dimension_matrix[0] * sizeof(double));
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    *vector = (double *)malloc(dimension_matrix[0] * sizeof(double));
    int dimension_vector[2] = {dimension_matrix[0], 1};
    // Procespo de factorizacion LU
    double *L, *U;
    obtain_LU_crout(matrix,
                    dimension_matrix,
                    &L,
                    &U);
    // Inicializacion del vector
    initialize_vector(*vector,
                      dimension_matrix);
    while (convergence_eigenvalues(*lambda,
                                   lambda_i,
                                   attempt))
    {
        lambda_i = *lambda;
        copy_vector(*vector,
                    vector_i,
                    dimension_vector);
        // Resuelve el sistema de ecuaciones
        solve_triangular_inferior_matrix(L,
                                         dimension_matrix,
                                         *vector,
                                         &vector_aux);
        solve_triangular_superior_matrix(U,
                                         dimension_matrix,
                                         vector_aux,
                                         vector);
        down = obtain_cdot_multiplication(*vector, vector_i, dimension_vector);
        up = obtain_norm(vector_i, dimension_vector);
        *lambda = (up * up) / down;
        normalize_vector(*vector, dimension_vector);
        attempt += 1;
    }
    normalize_vector(*vector,
                     dimension_vector);
    free(L);
    free(U);
    free(vector_aux);
    free(vector_i);
}
