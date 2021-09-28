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
int convergence_eigenvalues(double lambda, double lambda_i, int attempt)
{
    double theta;
    if (attempt != 0)
    {
        theta = fabs(lambda - lambda_i);
        if (theta < 1e-8)
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
    double lambda_i, max_vi, max_v;
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
        max_vi = obtain_max_value(vector_i, dimension_vector);
        max_v = obtain_max_value(*vector, dimension_vector);
        *lambda = max_v / max_vi;
        attempt += 1;
        printf("lambda = %lf\n", *lambda);
        normalize_vector(*vector, dimension_vector);
    }
    print_lines();
    printf("\nNúmero de iteraciones:\t%d\n\n", attempt);
    // normalize_vector(*vector,
    //                  dimension_vector);
    free(vector_i);
}
void fill_matrix_aux(double *matrix, double *matrix_aux, int dimension_matrix[], int n)
{
    double m_ij;
    double *M_aux_ij;
    for (int i = n; i < dimension_matrix[0]; i++)
    {
        for (int j = n; j < dimension_matrix[1]; j++)
        {
            m_ij = *(matrix + j * dimension_matrix[0] + i);
            M_aux_ij = (matrix_aux + (j - n) * (dimension_matrix[0] - n) + i - n);
            *M_aux_ij = m_ij;
        }
    }
}
void apply_Housholder(double **matrix, int dimension_matrix[], double *vector, int dimension_vector[])
{
    (void)matrix;
    double *H_ij;
    double norm = obtain_norm(vector, dimension_vector), I;
    double *matrix_H, *matrix_aux;
    matrix_aux = (double *)malloc(dimension_vector[0] * dimension_vector[0] * sizeof(double));
    *vector = *vector + norm;
    norm = obtain_norm(vector, dimension_vector);
    obtain_multiplication_vvT(vector, dimension_vector, &matrix_H);
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = 0; j < dimension_matrix[0]; j++)
        {
            H_ij = matrix_H + j * dimension_matrix[0] + i;
            if (i == j)
            {
                I = 1;
            }
            else
            {
                I = 0;
            }
            *H_ij = I - 2 * *H_ij / (norm * norm);
        }
    }
    obtain_multiplication_matrix(matrix_H, *matrix, matrix_aux, dimension_matrix, dimension_matrix);
    obtain_multiplication_matrix(matrix_aux, matrix_H, *matrix, dimension_matrix, dimension_matrix);
    free(matrix_aux);
    free(matrix_H);
}
void initialize_matrix_i(double *matrix, double **matrix_i, int dimension[])
{
    double m_ij, *Mi_ij;
    *matrix_i = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            m_ij = *(matrix + j * dimension[0] + i);
            Mi_ij = (*matrix_i + j * dimension[0] + i);
            *Mi_ij = m_ij;
        }
    }
}
void obtain_n_max_eigenvalue(double *matrix, int dimension_matrix[], double **lambda, double **vectors, int n_lambdas)
{
    (void)lambda;
    (void)vectors;
    double *matrix_aux, *matrix_i, *vector = NULL;
    double lambda_max = 0;
    int dimension_aux[2],
        dimension_vector[2] = {1, 1},
        dimension_vector_max[2] = {1, 1};
    (void)dimension_vector;
    initialize_matrix_i(matrix, &matrix_i, dimension_matrix);
    for (int i = 0; i < n_lambdas; i++)
    {
        dimension_aux[0] = dimension_matrix[0] - i;
        dimension_aux[1] = dimension_matrix[1] - i;
        dimension_vector[0] = dimension_matrix[0] - i;
        dimension_vector_max[0] = dimension_matrix[0];
        matrix_aux = (double *)malloc(dimension_aux[0] * dimension_aux[1] * sizeof(double));
        if (lambda_max != 0)
        {
            apply_Housholder(&matrix_i,
                             dimension_matrix,
                             vector,
                             dimension_vector_max);
        }
        fill_matrix_aux(matrix_i,
                        matrix_aux,
                        dimension_matrix, i);
        obtain_max_eigenvalue(matrix_aux,
                              dimension_vector,
                              &lambda_max,
                              &vector);
        print_matrix(vector, dimension_vector);
        // printf("lambda = %lf\n", lambda_max);
    }
}
void obtain_min_eigenvalue(double *matrix, int dimension_matrix[], double *lambda, double **vector)
{
    double lambda_i, max_vi, max_v;
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
        max_vi = obtain_max_value(vector_i, dimension_vector);
        max_v = obtain_max_value(*vector, dimension_vector);
        *lambda = max_vi / max_v;
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
