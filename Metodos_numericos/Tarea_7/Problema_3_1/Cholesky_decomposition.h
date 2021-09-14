void validate_matrix(double *matrix, int dimension_matrix[])
{
    /* 
    Valida si la matriz introducida al metoto es simetrica, si no lo es el programa se elimina
     */
    double matrix_ij, matrix_ji;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = i; j < dimension_matrix[0]; j++)
        {
            // No checar elementos de la diagonal
            if (i != j)
            {
                matrix_ij = *(matrix + i * dimension_matrix[0] + j);
                matrix_ji = *(matrix + j * dimension_matrix[0] + i);
                if (matrix_ij != matrix_ji)
                {
                    printf("Matriz invalida para el método\n");
                    exit(1);
                }
            }
        }
    }
}
void vadidate_positive_matrix(double number)
{
    /* 
    Valida si la matriz es positiva definida
    */
    if (number < 0)
    {
        printf("La matriz no es positiva definida \n");
        exit(1);
    }
}
void validate_l_ii(double l_ii)
{
    /* 
    Valida que la diagonal de la matriz L es diferente de cero
     */
    if (l_ii == 0)
    {
        printf("Matriz no apta para el método. l_ii = 0\n");
        exit(1);
    }
}
void fill_L_transpose(double *L, double *LT, int dimension_matrix[])
{
    /* 
    Realiza la transpuesta de L y la escribe en el puntero LT
     */
    double *LT_i, l_i;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = i; j < dimension_matrix[0]; j++)
        {
            LT_i = (LT + i * dimension_matrix[0] + j);
            l_i = *(L + j * dimension_matrix[0] + i);
            *LT_i = l_i;
        }
    }
}
void obtain_Cholesky(double *matrix, int dimension_matrix[], double **L, double **LT)
{
    /* 
    Realiza la factorizacion de una matriz por el metodo de Cholesky
    inputs:
    + matrix: puntero de un arreglo que contiene los datos de la matriz
    + dimension_matrix: arreglo de dos dimensiones que contiene las dimensiones de la matriz
    + L: doble puntero donde se guardara la matriz L
    + LT: doble puntero donde se guardara la matriz LT
     */
    double *L_ii, *L_ij;
    double sqrt_number, sum, l_ik, l_jk, matrix_ii, matrix_ij;
    validate_matrix(matrix, dimension_matrix);
    *L = (double *)malloc(dimension_matrix[0] * dimension_matrix[1] * sizeof(double));
    *LT = (double *)malloc(dimension_matrix[0] * dimension_matrix[1] * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        sum = 0;
        // Elemento L_ii
        L_ii = (*L + i * dimension_matrix[0] + i);
        // Elemento de la ii de la matriz
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Calculo de los elementos L_ii
        for (int j = 0; j < i; j++)
        {
            l_ik = *(*L + i * dimension_matrix[0] + j);
            sum += l_ik * l_ik;
        }
        sqrt_number = matrix_ii - sum;
        vadidate_positive_matrix(sqrt_number);
        *L_ii = sqrt(sqrt_number);
        validate_l_ii(*L_ii);
        // Calculo de los elementos L_ij
        for (int j = i; j < dimension_matrix[1]; j++)
        {
            sum = 0;
            // Obtiene el elemento L_ij
            L_ij = (*L + j * dimension_matrix[0] + i);
            // Obtiene el elemento ij de la matrix
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            for (int k = 0; k < i; k++)
            {
                l_ik = *(*L + i * dimension_matrix[0] + k);
                l_jk = *(*L + j * dimension_matrix[0] + k);
                sum += l_ik * l_jk;
            }
            // Obtiene el elemento L_ij
            *L_ij = (matrix_ij - sum) / *L_ii;
        }
    }
    // Completa la matriz LT a partir de L
    fill_L_transpose(*L, *LT, dimension_matrix);
}