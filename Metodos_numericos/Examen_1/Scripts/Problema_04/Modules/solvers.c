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
        if (theta < 1e-3)
        {
            // Si se cumple la convergencia regresa un 0
            return 0;
        }
    }
    // Si no la cumple devuelve un 1
    return 1;
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
        cdot = obtain_cdot_multiplication(vector_i,
                                          *vector,
                                          dimension);
        for (int j = 0; j < dimension[0]; j++)
        {
            // Eliminacion de las contribuciones
            *(vector_aux + j) -= cdot * *(vector_i + j);
        }
    }
    // Copia del vector para obtener el resultado
    copy_vector(vector_aux,
                *vector,
                dimension);
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
    double lambda_i = 0, lambda_aux, up, down;
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
        printf("Calculando eigenvalor menor numero: %d\n", i + 1);
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
        copy_vectors(vectors,
                     vector_i,
                     dimension_vector,
                     i);
    }
    free(vector_aux);
    free(vector_i);
    free(vector_j);
    free(L);
    free(U);
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
/*
Metodo de deflaccion, dada una matriz y su dimension se calcularan los n lambdas dadas maximas
*/
void obtain_n_max_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas)
{
    // Inicializacion del espacio de valores
    *lambda = (double *)malloc(n_lambdas * sizeof(double));
    // Inicializacion de la matriz de eigenvectores
    *vectors = (double *)malloc(n_lambdas * dimension_matrix[0] * sizeof(double));
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    double *vector_i = (double *)malloc(dimension_matrix[0] * sizeof(double));
    int dimension_vector[2] = {dimension_matrix[0], 1};
    double lambda_i = 0, lambda_aux, up, down;
    for (int i = 0; i < n_lambdas; i++)
    {
        printf("Calculando eigenvalor mayor numero: %d\n", i + 1);
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
