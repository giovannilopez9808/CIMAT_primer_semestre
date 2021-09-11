void solve_diagonal_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    double result_i, matrix_ii;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        result_i = *(results + i);
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        *(*solutions + i) = result_i / matrix_ii;
    }
}