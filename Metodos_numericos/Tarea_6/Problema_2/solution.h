void solve_triangular_superior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    double result_i, matrix_ii, matrix_ij, sum_ij;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = dimension_matrix[0] - 1; i >= 0; i--)
    {
        // Inicializacion del contador
        sum_ij = 0;
        result_i = *(results + i);
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        for (int j = dimension_matrix[0] - 1; j > i; j--)
        {
            matrix_ij = *(matrix + j * dimension_matrix[0] + i);
            sum_ij += *(*solutions + j) * matrix_ij;
        }
        *(*solutions + i) = (result_i - sum_ij) / matrix_ii;
    }
}