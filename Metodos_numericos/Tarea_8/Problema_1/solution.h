void swap(double *number1, double *number2)
{
    double aux = *number1;
    *number1 = *number2;
    *number2 = aux;
}
void swap_int(int *number1, int *number2)
{
    int aux = *number1;
    *number1 = *number2;
    *number2 = aux;
}
void change_columns(double *matrix, int dimension_matrix[], int position[], int change[])
{
    int j_old = position[1];
    int j_new = change[1];
    double *M_old, *M_new;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        M_old = (matrix + j_old * dimension_matrix[0] + i);
        M_new = (matrix + j_new * dimension_matrix[0] + i);
        swap(M_old, M_new);
    }
}
void change_rows(double *matrix, int dimension_matrix[], double *results, int position[], int change[], int *solution_pos)
{
    (void)results;
    int i_old = position[0];
    int i_new = change[0];
    double *M_old, *M_new, *R_old, *R_new;
    int *SP_old, *SP_new;
    R_old = (results + i_old);
    R_new = (results + i_new);
    SP_old = (solution_pos + i_old);
    SP_new = (solution_pos + i_new);
    (void)SP_new;
    (void)SP_old;
    swap(R_old, R_new);
    swap_int(SP_old, SP_new);
    for (int j = 0; j < dimension_matrix[1]; j++)
    {
        M_old = (matrix + j * dimension_matrix[0] + i_old);
        M_new = (matrix + j * dimension_matrix[0] + i_new);
        swap(M_old, M_new);
    }
}
void initialize_solutions_pos(int *solution_pos, int dimension_matrix[])
{
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        *(solution_pos + i) = i + 1;
    }
}
void check_dominant_diagonal_matrix(double *matrix, int dimension_matrix[])
{
    print_lines();
    double sum_ij, m_ij, m_ii;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        sum_ij = 0;
        m_ii = fabs(*(matrix + i * dimension_matrix[0] + i));
        for (int j = 0; j < dimension_matrix[1]; j++)
        {
            if (i != j)
            {
                m_ij = *(matrix + j * dimension_matrix[0] + i);
                sum_ij += fabs(m_ij);
            }
        }
        if (sum_ij > m_ii)
        {
            printf("La matrix no es diagonal dominante\n");
            printf("Es posible que no se encuentre solucion\n");
            return;
        }
    }
    printf("La matriz si es diagonal dominante\n");
}
void convert_to_dominant_diagonal(double *matrix, int dimension_matrix[], double *results, int **solution_pos)
{
    (void)results;
    double m_ij, max;
    int max_position[2], original_position[2];
    *solution_pos = (int *)malloc(dimension_matrix[0] * sizeof(int));
    initialize_solutions_pos(*solution_pos, dimension_matrix);
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        max = *(matrix + i * dimension_matrix[0] + i);
        max = fabs(max);
        original_position[0] = i;
        original_position[1] = i;
        max_position[0] = i;
        max_position[1] = i;
        for (int j = i; j < dimension_matrix[0]; j++)
        {
            for (int k = i; k < dimension_matrix[1]; k++)
            {
                m_ij = *(matrix + k * dimension_matrix[0] + j);
                if (fabs(m_ij) > max)
                {
                    max = fabs(m_ij);
                    max_position[0] = j;
                    max_position[1] = k;
                }
            }
        }
        if (i != max_position[1])
        {
            change_columns(matrix,
                           dimension_matrix,
                           original_position,
                           max_position);
        }
        if (i != max_position[0])
        {
            change_rows(matrix,
                        dimension_matrix,
                        results,
                        original_position,
                        max_position,
                        *solution_pos);
        }
    }
    check_dominant_diagonal_matrix(matrix, dimension_matrix);
}
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
        theta = sqrt(theta);
        if (theta < 1e-7)
        {
            return 0;
        }
    }
    return 1;
}
void fill_solutions(double *solutions, double *solutions_i, int dimension_solutions[])
{
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
    int attempt = 0;
    double *R_matrix, *D_matrix, *Rx_matrix, *Matrix_res, *Solutions_i;
    *solutions = (double *)malloc(dimension_results[0] * sizeof(double));
    Solutions_i = (double *)malloc(dimension_results[0] * sizeof(double));
    Rx_matrix = (double *)malloc(dimension_results[0] * sizeof(double));
    Matrix_res = (double *)malloc(dimension_results[0] * sizeof(double));
    obtain_D_and_R_matrix(matrix,
                          dimension_matrix,
                          &D_matrix,
                          &R_matrix);
    while (convergence(*solutions,
                       Solutions_i,
                       dimension_results,
                       attempt))
    {
        fill_solutions(*solutions,
                       Solutions_i,
                       dimension_results);
        obtain_multiplication_matrix(R_matrix,
                                     Solutions_i,
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
        attempt += 1;
    }
    free(Solutions_i);
    free(Rx_matrix);
    free(Matrix_res);
    free(R_matrix);
    free(D_matrix);
}