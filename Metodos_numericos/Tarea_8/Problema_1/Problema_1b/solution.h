void solve_triangular_superior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    /* 
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular superior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
    double result_i, matrix_ii, matrix_ij, sum_ij;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = dimension_matrix[0] - 1; i >= 0; i--)
    {
        // Inicializacion del contador
        sum_ij = 0;
        // Obtiene el termino b_i
        result_i = *(results + i);
        // Obtiene el termino a_i
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Valida la solucion del sistema
        valid_solution(matrix_ii);
        for (int j = dimension_matrix[0] - 1; j > i; j--)
        {
            // Obtiene el termino a_ij
            matrix_ij = *(matrix + j * dimension_matrix[0] + i);
            // Realiza la suma del producto de x_j*a_ij
            sum_ij += *(*solutions + j) * matrix_ij;
        }
        // Obtiene el termino x_i
        *(*solutions + i) = (result_i - sum_ij) / matrix_ii;
    }
}
void solve_triangular_inferior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    /* 
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular inferior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
    double result_i, matrix_ii, matrix_ij, sum_ij;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Inicializacion del contador
        sum_ij = 0;
        // Obtiene el termino b_i
        result_i = *(results + i);
        // Obtiene el termino a_ii
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Validacion de la existencia de la solucion
        valid_solution(matrix_ii);
        for (int j = 0; j < i; j++)
        {
            // Obtiene el termino a_ij
            matrix_ij = *(matrix + j * dimension_matrix[0] + i);
            // Realiza la suma de los productos x_j*a_ij
            sum_ij += *(*solutions + j) * matrix_ij;
        }
        // Obtiene el termino x_i
        *(*solutions + i) = (result_i - sum_ij) / matrix_ii;
    }
}
void solve_diagonal_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    /* 
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz diagonal
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
    double result_i, matrix_ii;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Obtiene el termino b_i
        result_i = *(results + i);
        // Obtiene el termino a_i
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        valid_solution(matrix_ii);
        // Obtiene el termino x_i
        *(*solutions + i) = result_i / matrix_ii;
    }
}
void solve_gaussian_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    /* 
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular superior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
    double matrix_ii, matrix_ij, matrix_jk, matrix_ik, ratio_ij, result_i;
    double *Matrix_jk, *Result_j;
    for (int i = 0; i < dimension_matrix[0] - 1; i++)
    {
        // Obtiene el termino a_ii
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Obitene el termino b_i
        result_i = *(results + i);
        for (int j = i + 1; j < dimension_matrix[0]; j++)
        {
            // Obtiene el termino a_ij
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            // Valida la solucion del sistema
            valid_solution(matrix_ij);
            // Obtiene el factor que se multiplicara en toda la fila
            ratio_ij = matrix_ii / matrix_ij;
            // Obtiene el puntero de
            Result_j = (results + j);
            // Obtiene x_j por el factor
            *Result_j = *Result_j * ratio_ij - result_i;
            // Proceso de diferencias entrre la i-esima fila
            for (int k = i; k < dimension_matrix[1]; k++)
            {
                matrix_ik = *(matrix + k * dimension_matrix[0] + i);
                matrix_jk = *(matrix + k * dimension_matrix[0] + j);
                Matrix_jk = (matrix + k * dimension_matrix[0] + j);
                *Matrix_jk = (matrix_jk * ratio_ij - matrix_ik);
            }
        }
    }
    // La matriz fue transformada a una triangular superior
    solve_triangular_superior_matrix(matrix,
                                     dimension_matrix,
                                     results,
                                     solutions);
}