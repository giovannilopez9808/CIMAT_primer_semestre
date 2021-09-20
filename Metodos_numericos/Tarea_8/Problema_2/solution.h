void obtain_D_and_R_matrix(double *matrix, int dimension_matrix[], double **D_matrix, double **R_matrix)
{
    /* 
    Obtiene la matrix D y R a partir de una matriz
     */
    *D_matrix = (double *)malloc(dimension_matrix[0] * dimension_matrix[1] * sizeof(double));
    *R_matrix = (double *)malloc(dimension_matrix[0] * dimension_matrix[1] * sizeof(double));
    double *R_ij, *D_ij;
    double matrix_ij, matrix_ii;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Elemento ij de D
        D_ij = (*D_matrix + i * dimension_matrix[0] + i);
        // Elemento ii de la matriz
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Inverso de la diagonal
        *D_ij = 1 / matrix_ii;
        for (int j = 0; j < dimension_matrix[0]; j++)
        {
            if (i != j)
            {
                // Elemento ij de R
                R_ij = (*R_matrix + j * dimension_matrix[0] + i);
                // Elemento ij de la matriz diferente a la diagonal
                matrix_ij = *(matrix + j * dimension_matrix[0] + i);
                *R_ij = matrix_ij;
            }
        }
    }
}
int convergence(double *solutions, double *solutions_i, int dimension_solutions[], int attempt)
{
    /* 
    Calcula si la convergencia del metodo es suficiente para terminarlo
    */
    double s_i, si_i;
    double theta = 0;
    // No lo calcula para el primer intento
    if (attempt != 0)
    {
        // Calcula la diferencia entre soluciones de la iteracion actual y la anterior
        for (int i = 0; i < dimension_solutions[0]; i++)
        {
            s_i = *(solutions + i);
            si_i = *(solutions_i + i);
            // Suma de las difeencias al cuadrado
            theta += (s_i - si_i) * (s_i - si_i);
        }
        // Raiz de la suma de diferencias
        theta = sqrt(theta);
        // Si cumple el criterio termina
        if (theta < 1e-7)
        {
            return 0;
        }
    }
    // Si no sigue
    return 1;
}
void fill_solutions(double *solutions, double *solutions_i, int dimension_solutions[])
{
    /* 
    Transcribe las soluciones de la iteracion actual al puntero que guarda las soluciones de la iteracion anterior
         */
    double *S_i, *Si_i;
    for (int i = 0; i < dimension_solutions[0]; i++)
    {
        S_i = (solutions + i);
        Si_i = (solutions_i + i);
        *S_i = *Si_i;
    }
}
void solve_jabobi(double *matrix, int dimension_matrix[], double *results, int dimension_results[], double **solutions)
{
    /* 
    Aplica el metodo de iterativo de Jacobi para matrices
    inputs:
    + matrix: puntero que dirije hacia los datos de la matrix
    + dimension_matrix: arreglo de dos dimensiones que guarda el tamaño de la matriz
    + results: puntero que dirige al vector constante del sistema de ecuaciomes
    + dimension_results: arreglo de dos dimnsiones que guarda el tamaño de la matriz
    + solutions: doble puntero en donde se guardaran las soluciones al sistema de ecuaciones
     */
    int attempt = 0;
    double *R_matrix, *D_matrix, *Rx_matrix, *Matrix_res, *Solutions_i;
    *solutions = (double *)malloc(dimension_results[0] * sizeof(double));
    Solutions_i = (double *)malloc(dimension_results[0] * sizeof(double));
    Rx_matrix = (double *)malloc(dimension_results[0] * sizeof(double));
    Matrix_res = (double *)malloc(dimension_results[0] * sizeof(double));
    // Obtiene las matrices D y R de la matriz dada
    obtain_D_and_R_matrix(matrix,
                          dimension_matrix,
                          &D_matrix,
                          &R_matrix);
    while (convergence(*solutions,
                       Solutions_i,
                       dimension_results,
                       attempt))
    {
        // Copia los valores de las soluciones de la iteracion actual a la anterior
        fill_solutions(*solutions,
                       Solutions_i,
                       dimension_results);
        // Multiplica las matrices Rx
        obtain_multiplication_matrix(R_matrix,
                                     Solutions_i,
                                     Rx_matrix,
                                     dimension_matrix,
                                     dimension_results);
        // Resta las matrices b-Rx
        obtain_subraction_matrix(results,
                                 Rx_matrix,
                                 Matrix_res,
                                 dimension_results);
        // Multiplica las matrices D^{-1}(b-Rx)
        obtain_multiplication_matrix(D_matrix,
                                     Matrix_res,
                                     Solutions_i,
                                     dimension_matrix,
                                     dimension_results);
        // Contador de los intentos
        attempt += 1;
    }
    free(Solutions_i);
    free(Rx_matrix);
    free(Matrix_res);
    free(R_matrix);
    free(D_matrix);
}