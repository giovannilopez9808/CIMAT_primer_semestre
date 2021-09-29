void fill_vector(double *vector, double *vector_i, int dimension[])
{
    for (int i = 0; i < dimension[0]; i++)
    {
        *(vector_i + i) = *(vector + i);
    }
}
void initialize_vector(double *vector, int dimension[])
{
    for (int i = 0; i < dimension[0]; i++)
    {
        *(vector + i) = 1 / sqrt(dimension[0]);
    }
}
int convergence_eigenvalues(double lambda, double lambda_i, int attempt)
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
    double lambda_i, up, down;
    int dimension_vector[2] = {dimension_matrix[0], 1};
    *vector = (double *)malloc(dimension_matrix[0] * sizeof(double));
    initialize_vector(*vector,
                      dimension_matrix);
    while (convergence_eigenvalues(*lambda,
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
        up = obtain_cdot_multiplication(*vector, vector_i, dimension_vector);
        down = obtain_norm(vector_i, dimension_vector);
        normalize_vector(*vector, dimension_vector);
        *lambda = up / (down * down);
        attempt += 1;
    }
    print_lines();
    printf("\nNúmero de iteraciones:\t%d\n\n", attempt);
    printf("lambda = %lf\n", *lambda);
    free(vector_i);
}
void fill_vector_i(double *vectors, double *vector, int dimension[], int n)
{
    double *Vi_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        v_i = *(vectors + n * dimension[0] + i);
        Vi_i = vector + i;
        *Vi_i = v_i;
    }
}
void obatin_new_vector(double **vector, double *vectors, int dimension[], int n)
{
    double cdot;
    double *vector_i = (double *)malloc(dimension[0] * sizeof(double));
    double *vector_aux = (double *)malloc(dimension[0] * sizeof(double));
    fill_vector(*vector, vector_aux, dimension);
    for (int i = 0; i < n; i++)
    {
        fill_vector_i(vectors, vector_i, dimension, i);
        cdot = obtain_cdot_multiplication(vector_i, *vector, dimension);
        for (int j = 0; j < dimension[0]; j++)
        {
            *(vector_aux + j) -= cdot * *(vector_i + j);
        }
    }
    fill_vector(vector_aux, *vector, dimension);
    free(vector_aux);
    free(vector_i);
}
void fill_vectors(double **vectors, double *vector, int dimension[], int n)
{
    double *V_i, v_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        V_i = (*vectors + n * dimension[0] + i);
        v_i = *(vector + i);
        *V_i = v_i;
    }
}
void obtain_n_max_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas)
{
    // Inicializacion del espacio de valores
    *lambda = (double *)malloc(n_lambdas * sizeof(double));
    *vectors = (double *)malloc(dimension_matrix[0] * n_lambdas * sizeof(double));
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    double *vector_i = (double *)malloc(dimension_matrix[0] * sizeof(double));
    int dimension_vector[2] = {dimension_matrix[0], 1};
    double lambda_i, lambda_aux, up, down;
    for (int i = 0; i < n_lambdas; i++)
    {
        initialize_vector(vector_i,
                          dimension_matrix);
        obatin_new_vector(&vector_i,
                          *vectors,
                          dimension_vector,
                          i);
        int attempt = 0;
        while (convergence_eigenvalues(lambda_i,
                                       lambda_aux,
                                       attempt))
        {
            lambda_aux = lambda_i;
            fill_vector(vector_i,
                        vector_aux,
                        dimension_vector);
            obtain_multiplication_matrix(matrix,
                                         vector_aux,
                                         vector_i,
                                         dimension_matrix,
                                         dimension_vector);
            up = obtain_cdot_multiplication(vector_i,
                                            vector_aux,
                                            dimension_vector);
            down = obtain_norm(vector_aux,
                               dimension_vector);
            lambda_i = up / (down * down);
            normalize_vector(vector_i,
                             dimension_vector);
            obatin_new_vector(&vector_i,
                              *vectors,
                              dimension_vector,
                              i);
            attempt += 1;
        }
        fill_vectors(vectors, vector_i, dimension_vector, i);
        printf("lambda = %lf\n", lambda_i);
        print_lines();
    }
    free(vector_aux);
    free(vector_i);
}
void obtain_min_eigenvalue(double *matrix, int dimension_matrix[], double *lambda, double **vector)
{
    double lambda_i, down, up;
    int attempt = 0;
    double *vector_i = (double *)malloc(dimension_matrix[0] * sizeof(double));
    double *vector_aux = (double *)malloc(dimension_matrix[0] * sizeof(double));
    *vector = (double *)malloc(dimension_matrix[0] * sizeof(double));
    int dimension_vector[2] = {dimension_matrix[0], 1};
    // Procespo de factorizacion LU
    double *L, *U;
    obtain_LU_crout(matrix,
                    dimension_matrix,
                    &L,
                    &U);
    // Inicializacion del vector
    initialize_vector(*vector,
                      dimension_matrix);
    while (convergence_eigenvalues(*lambda,
                                   lambda_i,
                                   attempt))
    {
        lambda_i = *lambda;
        fill_vector(*vector,
                    vector_i,
                    dimension_vector);
        // Resuelve el sistema de ecuaciones
        solve_triangular_inferior_matrix(L,
                                         dimension_matrix,
                                         *vector,
                                         &vector_aux);
        solve_triangular_superior_matrix(U,
                                         dimension_matrix,
                                         vector_aux,
                                         vector);
        down = obtain_cdot_multiplication(*vector, vector_i, dimension_vector);
        up = obtain_norm(vector_i, dimension_vector);
        *lambda = (up * up) / down;
        normalize_vector(*vector, dimension_vector);
        attempt += 1;
    }
    print_lines();
    printf("\nNúmero de iteraciones:\t%d\n\n", attempt);
    normalize_vector(*vector,
                     dimension_vector);
    free(L);
    free(U);
    free(vector_aux);
    free(vector_i);
}
