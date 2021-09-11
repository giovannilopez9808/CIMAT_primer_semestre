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