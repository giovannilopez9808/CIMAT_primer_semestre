#include "eigen.h"
/*
Inicializa el vector dado con el valor 1/sqrt(n) en todos sus elementos
 */
void initialize_vector(double *vector, int *dimension)
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
        if (theta < 1e-7)
        {
            // Si se cumple la convergencia regresa un 0
            return 0;
        }
    }
    // Si no la cumple devuelve un 1
    return 1;
}
/*
Realiza la normalizacion del vector dado
 */
void normalize_vector(double *vector, int dimension[])
{
    double norm = obtain_cdot_multiplication(vector,
                                             vector,
                                             dimension);
    double *V_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        V_i = (vector + i);
        *V_i = *V_i / norm;
    }
}
/*
Metodo de las potencias, recibe una matriz y su dimension y devuelve su eigenvalor dominante con su respectito eigenvector
 */
void obtain_max_eigenvalue(double *matrix, int *dimension_matrix, double *lambda, double **vector)
{
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
        up = obtain_cdot_multiplication(*vector,
                                        vector_i,
                                        dimension_vector);
        // Norma de v_{i-1}
        down = obtain_cdot_multiplication(vector_i,
                                          vector_i,
                                          dimension_vector);
        down = sqrt(down);
        // Normalizacion de v_i
        normalize_vector(*vector,
                         dimension_vector);
        // Calculo de lambda
        *lambda = up / (down * down);
        attempt += 1;
    }
    free(vector_i);
}