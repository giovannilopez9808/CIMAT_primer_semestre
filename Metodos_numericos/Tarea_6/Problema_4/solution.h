void solve_triangular_superior_matrix(double *matrix, int dimension_matrix[], double *results, double *solutions)
{
    double result_i, matrix_ii, matrix_ij, sum_ij;
    for (int i = dimension_matrix[0] - 1; i >= 0; i--)
    {
        // Inicializacion del contador
        sum_ij = 0;
        result_i = *(results + i);
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        for (int j = dimension_matrix[0] - 1; j > i; j--)
        {
            matrix_ij = *(matrix + j * dimension_matrix[0] + i);
            sum_ij += *(solutions + j) * matrix_ij;
        }
        *(solutions + i) = (result_i - sum_ij) / matrix_ii;
    }
}
void solve_gaussian_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    // double matrix_ii, matrix_ij, *matrix_jk, matrix_ik, *results_i, ratio;
    double matrix_ii, matrix_ij, matrix_jk, matrix_ik, ratio_ij, result_i, result_j;
    double *Matrix_jk, *Result_j;
    (void)result_j;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = 0; i < dimension_matrix[0] - 1; i++)
    {
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        result_i = *(results + i);
        for (int j = i + 1; j < dimension_matrix[0]; j++)
        {
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            ratio_ij = matrix_ii / matrix_ij;
            result_j = *(results + j);
            Result_j = (results + j);
            *Result_j = *Result_j * ratio_ij - result_i;
            for (int k = i; k < dimension_matrix[1]; k++)
            {
                matrix_ik = *(matrix + k * dimension_matrix[0] + i);
                matrix_jk = *(matrix + k * dimension_matrix[0] + j);
                Matrix_jk = (matrix + k * dimension_matrix[0] + j);
                *Matrix_jk = (matrix_jk * ratio_ij - matrix_ik);
            }
        }
    }
    solve_triangular_superior_matrix(matrix,
                                     dimension_matrix,
                                     results,
                                     *solutions);
}