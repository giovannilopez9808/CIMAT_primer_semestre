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
        *D_ij = 1 / matrix_ii;
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
void obtain_subraction_matrix(double *matrix_b, double *matrix_rx, double *matrix_res, int dimesion_matrix[])
{
    double *R_i, *Rx_i, *Res_i;
    for (int i = 0; i < dimesion_matrix[0]; i++)
    {
        Rx_i = (matrix_rx + i);
        R_i = (matrix_b + i);
        Res_i = (matrix_res + i);
        *Res_i = *R_i - *Rx_i;
    }
}
void obtain_multiplication_matrix(double *A, double *B, double *AB, int dimension_matrix_A[], int dimension_matrix_B[])
{
    double a_ik, b_kj, *AB_ij;
    double sum;
    for (int i = 0; i < dimension_matrix_A[0]; i++)
    {
        for (int j = 0; j < dimension_matrix_B[1]; j++)
        {
            sum = 0;
            AB_ij = (AB + j * dimension_matrix_B[0] + i);
            for (int k = 0; k < dimension_matrix_B[0]; k++)
            {
                a_ik = *(A + k * dimension_matrix_A[0] + i);
                b_kj = *(B + j * dimension_matrix_B[0] + k);
                sum += a_ik * b_kj;
            }
            *AB_ij = sum;
        }
    }
}
int convergence(double *solutions, double *solutions_i, int dimension_solutions[], int attempt)
{
    double s_i, si_i;
    double theta = 0;
    if (attempt != 0)
    {
        for (int i = 0; i < dimension_solutions[0]; i++)
        {
            s_i = *(solutions + i);
            si_i = *(solutions_i + i);
            theta += (s_i - si_i) * (s_i - si_i);
        }
        if (theta < 1e-7)
        {
            return 0;
        }
    }
    return 1;
}
void fill_solutuions(double *solutions, double *solutions_i, int dimension_solutions[])
{
    double *S_i, *Si_i;
    for (int i = 0; i < dimension_solutions[0]; i++)
    {
        S_i = (solutions + i);
        Si_i = (solutions_i + i);
        *S_i = *Si_i;
    }
}
void solve_jabobi(double *matrix, int dimension_matrix[], double *results, int dimension_results[], double *solutions)
{
    int attempt = 0;
    double *R_matrix, *D_matrix, *Rx_matrix, *Matrix_res, *Solutions_i;
    solutions = (double *)malloc(dimension_results[0] * sizeof(double));
    Solutions_i = (double *)malloc(dimension_results[0] * sizeof(double));
    Rx_matrix = (double *)malloc(dimension_results[0] * sizeof(double));
    Matrix_res = (double *)malloc(dimension_results[0] * sizeof(double));
    obtain_D_and_R_matrix(matrix,
                          dimension_matrix,
                          &D_matrix,
                          &R_matrix);
    while (convergence(solutions,
                       Solutions_i,
                       dimension_results,
                       attempt))
    {
        fill_solutuions(solutions,
                        Solutions_i,
                        dimension_results);
        obtain_multiplication_matrix(R_matrix,
                                     solutions,
                                     Rx_matrix,
                                     dimension_matrix,
                                     dimension_results);
        obtain_subraction_matrix(results,
                                 Rx_matrix,
                                 Matrix_res,
                                 dimension_results);
        obtain_multiplication_matrix(D_matrix,
                                     Matrix_res,
                                     Solutions_i,
                                     dimension_matrix,
                                     dimension_results);
        print_matrix(solutions, dimension_results);
        attempt += 1;
    }
}