void obtain_D_and_R_matrix(double *matrix, int dimension_matrix[], double **D_matrix, double **R_matrix)
{
    *D_matrix = (double *)malloc(dimension_matrix[0] * dimension_matrix[1] * sizeof(double));
    *R_matrix = (double *)malloc(dimension_matrix[0] * dimension_matrix[1] * sizeof(double));
    double *R_ij, *D_ij;
    double matrix_ij, matrix_ii;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        D_ij = (*D_matrix + i * dimension_matrix[0] + i);
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        *D_ij = matrix_ii;
        for (int j = 0; j < dimension_matrix[0]; j++)
        {
            if (i != j)
            {
                R_ij = (*R_matrix + j * dimension_matrix[0] + i);
                matrix_ij = *(matrix + j * dimension_matrix[0] + i);
                *R_ij = matrix_ij;
            }
        }
    }
}
void solve_jabobi(double *matrix, int dimension_matrix[], double *results, int dimension_results[], double *solutions)
{
    (void)results;
    (void)dimension_results;
    (void)solutions;
    solutions = (double *)malloc(dimension_results[0] * sizeof(double));
    double *R_matrix, *D_matrix;
    obtain_D_and_R_matrix(matrix,
                          dimension_matrix,
                          &D_matrix,
                          &R_matrix);
}