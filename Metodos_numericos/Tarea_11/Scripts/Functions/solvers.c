#include "solvers.h"
/*
Inicializa el eigenvector de con tosos sus elementos con valor a 1/sqrt(n)
 */
void initialize_eigenvector(double *vector, int dimension)
{
    double *V_i;
    for (int i = 0; i < dimension; i++)
    {
        V_i = (vector + i);
        *V_i = 1 / sqrt(dimension);
    }
}
/*
Realiza la copia de los valores del vector_copy en vector
 */
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
/*
Realiza el calculo del cociente de Rayleight
 */
double Rayleigh_quotient(double *matrix, double *vector, int *dimension_matrix, int *dimension_vector)
{
    double quotient;
    // Inicializacion de un vector auxiliar
    double *vector_aux = (double *)malloc(dimension_vector[0] * sizeof(double));
    // Realiza la multiplicacion de  Ax y la guarda en el vector auxiliar
    obtain_multiplication_matrix(matrix,
                                 vector,
                                 vector_aux,
                                 dimension_matrix,
                                 dimension_vector);
    //  Producto punto de x y Ax
    double cdot_up = obtain_cdot_multiplication(vector,
                                                vector_aux,
                                                dimension_vector);
    // Producto de x por si mismo
    double cdot_down = obtain_cdot_multiplication(vector,
                                                  vector,
                                                  dimension_vector);
    //   Cociente
    quotient = cdot_up / cdot_down;
    free(vector_aux);
    return quotient;
}
/*
Comprueba si el método de Rayleigh convergio, en la primer llamada de la funcion en el metodo no realiza la verifciacion
 */
int convergence_rayleigh(double lambda, double lambda_aux, int attempt)
{
    double convergence;
    if (attempt != 0)
    {
        // Diferencia de lambdas
        convergence = fabs(lambda - lambda_aux);
        // Si la diferencia es menor a 10e-6 entonces convergio
        if (convergence < 1e-4)
        {
            return 0;
        }
    }
    return 1;
}
/*
Metodo de Rayleigh para obtener un eigenpar usando el metodo de potencias
 */
void Rayleigh_method(double *matrix, int dimension_matrix[], double *lambda, double **vector)
{
    // Dimension del eigenvector
    int dimension_vector[2] = {dimension_matrix[0], 1};
    // Vector auxiliar
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    // Inicializacion del eigenvector
    *vector = (double *)malloc(dimension_matrix[0] * sizeof(double));
    // Inicializacion de lambda auxiliar
    double lambda_aux = 0;
    // Inicializacion de las iteraciones
    int attempt = 0;
    // Inicializacion del eigenvector con sus elementos
    initialize_eigenvector(*vector, dimension_matrix[0]);
    while (convergence_rayleigh(*lambda, lambda_aux, attempt))
    {
        // Guardado del eigenvalor
        *lambda = lambda_aux;
        // Guardado del eigenvector
        copy_matrix(*vector, vector_aux, dimension_vector);
        // Multiplicacion del metodo de potencias
        obtain_multiplication_matrix(matrix,
                                     vector_aux,
                                     *vector,
                                     dimension_matrix,
                                     dimension_vector);
        //  Calculo de lambda
        lambda_aux = Rayleigh_quotient(matrix,
                                       *vector,
                                       dimension_matrix,
                                       dimension_vector);
        //    Normalizacion del vector
        normalize_vector(*vector,
                         dimension_vector);
        attempt++;
    }
    print_lines();
    printf("El numero de iteraciones fue %d\n", attempt);
    print_lines();
    free(vector_aux);
}
/*
Realiza la multiplicacion de vT A v para obtener la matriz del subespacio
 */
void obtain_sub_matrix(double *matrix, double *vectors, int *dimension_matrix, int *dimension_vector, double *sub_matrix)
{
    double sum;
    double a_ik, b_kj, *AB_ij;
    // Dimension de la matriz resultante
    int dimension[2] = {dimension_matrix[1], dimension_vector[1]};
    // Inicializacion de la matriz auxiliar
    double *matrix_aux = (double *)malloc(dimension_matrix[1] * dimension_vector[1] * sizeof(double));
    // Multiplicacion Av
    obtain_multiplication_matrix(matrix,
                                 vectors,
                                 matrix_aux,
                                 dimension_matrix,
                                 dimension_vector);
    // Multiplicacion de vT por Av
    for (int i = 0; i < dimension_vector[1]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            sum = 0;
            AB_ij = (sub_matrix + j * dimension[1] + i);
            for (int k = 0; k < dimension[0]; k++)
            {
                a_ik = *(vectors + i * dimension_vector[0] + k);
                b_kj = *(matrix_aux + j * dimension[0] + k);
                sum += a_ik * b_kj;
            }
            *AB_ij = sum;
        }
    }
    free(matrix_aux);
}
/*
     Copia del vector i de la matriz de eigenvectores
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
Escribe el vector n en la matriz de eigenvectores
 */
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
copd
    /*
    Obtiene la posicion del elemento con mayor valor absoluto y checa si este es mayor o menor a la tolerancia definida.
     */
    int
    convergence_eigenvaues_jacobi(double *matrix, int dimension[], int pos[])
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
Aplicacion del metodo de potencias y ortonormalizacion de Grim-Schmidt a todos los eigenvectores
 */
void power_method_per_vector(double *matrix, double *vectors, int *dimension_matrix, int *dimension_vectors)
{
    // Vectores auxiliares
    double *vector_i = (double *)malloc(dimension_vectors[0] * sizeof(double));
    double *vector_sol = (double *)malloc(dimension_vectors[0] * sizeof(double));
    // Dimension de los vectores
    int dimension_vector[2] = {dimension_vectors[0], 1};
    for (int i = 0; i < dimension_vectors[1]; i++)
    {
        // Copia del vector i
        obtain_vector_i(vectors,
                        vector_i,
                        dimension_vector, i);
        // Multiplicacion del vector i y la matriz
        obtain_multiplication_matrix(matrix,
                                     vector_i,
                                     vector_sol,
                                     dimension_matrix,
                                     dimension_vector);
        //  Guardado en la matriz de eigenvectores
        fill_vectors_solution(vectors,
                              vector_sol,
                              dimension_vectors,
                              i);
        //   Ortonormalizacion de Gram-Schmidt
        Gram_Schmidt_orthonormalization(vectors,
                                        dimension_vectors,
                                        i);
    }
    free(vector_i);
    free(vector_sol);
}
/*
Validacion de la convergencia del metodo de subespacio, si la diferencia de las sumas al duadrado de los valores en la diagonal son menores a 10e-6 entonces el metodo de detiene. En la primer iteracion no realiza la validacion
 */
int convergence_sub_space(double *matrix, double *matrix_aux, int *dimension, int attempt)
{
    double a_ii, b_ii, sum = 0;
    if (attempt != 0)
    {
        // Recorrido por la diagonal
        for (int i = 0; i < dimension[0]; i++)
        {
            a_ii = *(matrix + i * dimension[0] + i);
            b_ii = *(matrix_aux + i * dimension[0] + i);
            // Suma del valor absoluto de las diferencias
            sum += fabs(a_ii - b_ii);
        }
        printf("Convergencia %lf -> %lf\n", sum / dimension[0], 1e-4);
        // Si es menor a 10e-4 se detiene
        if (sum / dimension[0] < 1e-4)
        {
            return 0;
        }
    }
    return 1;
}
/*
    Guarda la lambda calculada en su variable de resultados
     */
void save_lambda(double *matrix, int *dimension, double *lambda)
{
    double *Lambda_i, m_ii;
    for (int i = 0; i < dimension[0]; i++)
    {
        m_ii = *(matrix + i * dimension[0] + i);
        Lambda_i = (lambda + i);
        *Lambda_i = m_ii;
    }
}
void Sub_space_method(double *matrix, int *dimension_matrix, double **lambda, double **vector, int n)
{
    (void)lambda;
    int dimension_vector[2] = {dimension_matrix[1], n};
    int attempt = 0, pos[2], dimension_sub_matrix[2] = {n, n};
    *vector = (double *)malloc(dimension_vector[0] * dimension_vector[1] * sizeof(double));
    *lambda = (double *)malloc(n * sizeof(double));
    // Inicializacion de la matrices auxiliares
    double *sub_matrix = (double *)malloc(n * n * sizeof(double));
    double *matrix_aux = (double *)malloc(n * n * sizeof(double));
    double theta;
    // Inicializacion de los eigenvectores en la base canonica
    obtain_identity_matrix(*vector,
                           dimension_vector);
    while (convergence_sub_space(sub_matrix,
                                 matrix_aux,
                                 dimension_sub_matrix,
                                 attempt))
    {
        // Ortonormalizacion de Gram-Schmidt
        Gram_Schmidt_orthonormalization(*vector,
                                        dimension_vector,
                                        dimension_vector[1]);
        //   Copia de la matriz del subespacio para la convergencia
        copy_matrix(sub_matrix,
                    matrix_aux,
                    dimension_sub_matrix);
        // Obtiene la matriz del subespacio
        obtain_sub_matrix(matrix,
                          *vector,
                          dimension_matrix,
                          dimension_vector,
                          sub_matrix);
        // Metodo de Jacobi
        while (convergence_eigenvaues_jacobi(sub_matrix,
                                             dimension_sub_matrix,
                                             pos))
        {
            // Calculo del angulo de rotacion
            theta = obtain_jacobi_angle(sub_matrix,
                                        dimension_sub_matrix,
                                        pos);
            // Rotacion de la matriz del subespacio y los eigenvectores
            rotate_matrix(sub_matrix,
                          *vector,
                          dimension_sub_matrix,
                          pos, theta);
        }
        // Metodo de la potencia a los eigenvectores en conjunto a la ortonormalizacion
        power_method_per_vector(matrix,
                                *vector,
                                dimension_matrix,
                                dimension_vector);
        attempt++;
    }
    print_lines();
    printf("Numero de iteraciones %d\n", attempt);
    print_lines();
    // Guardado de los resultados de los eigenvalores
    save_lambda(sub_matrix,
                dimension_sub_matrix,
                *lambda);
    free(sub_matrix);
    free(matrix_aux);
}
