void create_matrix(double **matrix, int dimension_matrix[])
{
    double *Matrix_ij;
    *matrix = (double *)malloc(dimension_matrix[0] * dimension_matrix[1] * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = 0; j < dimension_matrix[0]; j++)
        {
            Matrix_ij = (*matrix + j * dimension_matrix[0] + i);
            if (abs(i - j) == 1)
            {
                *Matrix_ij = -1;
            }
            else if (i == j)
            {
                *Matrix_ij = 2;
            }
        }
    }
}
void initialize_results(double **results, int dimension_matrix[], double k, double Q, double l, int n, double q_0, double q_n)
{
    double *R_i;
    double dx = l / n;
    double cons = Q * dx * dx / k;
    *results = (double *)malloc(dimension_matrix[0] * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        R_i = (*results + i);
        *R_i = cons;
        if (i == 0)
        {
            *R_i += q_0;
        }
        if (i == dimension_matrix[0] - 1)
        {
            *R_i += q_n;
        }
    }
}