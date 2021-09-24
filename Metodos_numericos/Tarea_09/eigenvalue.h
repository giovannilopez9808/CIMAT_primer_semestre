void fill_vector(double *vector, double *vector_i, int dimension[])
{
    for (int i = 0; i < dimension[0]; i++)
    {
        *(vector_i + i) = *(vector + i);
    }
}
void initialize_vector(double *vector, int dimension[])
{
    *(vector) = 1;
    for (int i = 1; i < dimension[0]; i++)
    {
        *(vector + i) = 0;
    }
}
int convergence_max_eigenvalues(double lambda, double lambda_i, int attempt)
{
    double theta;
    if (attempt != 0)
    {
        theta = fabs(lambda - lambda_i);
        if (theta < 1e-7)
        {
            return 0;
        }
    }
    return 1;
}
void obtain_max_eigenvalue(double *matrix, int dimension_matrix[], double *lambda, double **vector)
{
    double *vector_i = (double *)malloc(dimension_matrix[0] * sizeof(double));
    int attempt = 0;
    double lambda_i;
    int dimension_vector[2] = {dimension_matrix[0], 1};
    *vector = (double *)malloc(dimension_matrix[0] * sizeof(double));
    initialize_vector(*vector,
                      dimension_matrix);
    while (convergence_max_eigenvalues(*lambda,
                                       lambda_i,
                                       attempt))
    {
        lambda_i = *lambda;
        fill_vector(*vector,
                    vector_i,
                    dimension_vector);
        obtain_multiplication_matrix(matrix,
                                     vector_i,
                                     *vector,
                                     dimension_matrix,
                                     dimension_vector);
        *lambda = *(*vector) / (*vector_i);
        attempt += 1;
    }
    print_lines();
    printf("\nNúmero de iteraciones:\t%d\n\n",attempt);
    normalize_vector(*vector,
                     dimension_vector);
}
