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