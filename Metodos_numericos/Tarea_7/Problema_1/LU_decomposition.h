void Fill_initial_values_U_matrix(double *U, int dimension_matrix[])
{
    double *U_ii;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {

        U_ii = (U + i * dimension_matrix[0] + i);
        *U_ii = 1;
    }
}
void obtain_LU_crout(double *matrix, int dimension_matrix[], double **L, double **U)
{
    *L = (double *)malloc((dimension_matrix[0]) * dimension_matrix[1] * sizeof(double));
    *U = (double *)malloc((dimension_matrix[0]) * dimension_matrix[1] * sizeof(double));
    double *L_ij, *U_ij;
    double sum_ij, l_ii, l_ik, u_kj, matrix_ij;
    (void)l_ii;
    Fill_initial_values_U_matrix(*U,
                                 dimension_matrix);
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = i; j < dimension_matrix[1]; j++)
        {
            sum_ij = 0;
            L_ij = (*L + j * dimension_matrix[0] + i);
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            for (int k = 0; k <= i - 1; k++)
            {
                l_ik = *(*L + j * dimension_matrix[0] + k);
                u_kj = *(*U + k * dimension_matrix[0] + i);
                sum_ij += l_ik * u_kj;
            }
            *L_ij = matrix_ij - sum_ij;
        }
        l_ii = *(*L + i * dimension_matrix[0] + i);
        for (int j = i + 1; j < dimension_matrix[0]; j++)
        {
            sum_ij = 0;
            U_ij = (*U + i * dimension_matrix[0] + j);
            matrix_ij = *(matrix + j * dimension_matrix[0] + i);
            for (int k = 0; k < j - 1; k++)
            {
                l_ik = *(*L + i * dimension_matrix[0] + k);
                u_kj = *(*U + k * dimension_matrix[0] + j);
                sum_ij += l_ik * u_kj;
            }
            *U_ij = (matrix_ij - sum_ij) / l_ii;
        }
    }
    print_matrix(*L, dimension_matrix);
    print_matrix(*U, dimension_matrix);
}