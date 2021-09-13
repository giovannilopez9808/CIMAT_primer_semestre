void Fill_initial_values_U_matrix(double *U, int dimension_matrix[])
{
    /* 
    Inicializa la matrix U con unos en la diagonal
    inputs:
    + U: puntero del arreglo de la matriz U
    + dimension_matrix: arreglo de dos dimensiones que contiene el tamaño de la matriz
     */
    double *U_ii;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {

        U_ii = (U + i * dimension_matrix[0] + i);
        *U_ii = 1;
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
void obtain_LU_crout(double *matrix, int dimension_matrix[], double **L, double **U)
{
    /* 
    Aplica la factorizacion LU aplicando la version de Crout
    inputs:
    + matrix: puntero del arreglo que contiene lo datos de la matriz
    + dimension_matrix: puntero del arreglo de dos dimensiones que contiene el tamaño de la matriz
    + L: doble puntero que contendra la matriz L
    + U: doble puntero que contendra la matriz U
     */
    *L = (double *)malloc((dimension_matrix[0]) * dimension_matrix[1] * sizeof(double));
    *U = (double *)malloc((dimension_matrix[0]) * dimension_matrix[1] * sizeof(double));
    // Apunteadores para guardar cada valor
    double *L_ij, *U_ij;
    double sum_ij, l_ii, l_ik, u_kj, matrix_ij;
    // Inicializacion de la matriz U
    Fill_initial_values_U_matrix(*U,
                                 dimension_matrix);
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Procedimiento para obtener los elementos de la matriz L
        for (int j = i; j < dimension_matrix[1]; j++)
        {
            // Inicializacion de la suma
            sum_ij = 0;
            // Localizacion de la matriz L donde se calculara el elemento
            L_ij = (*L + j * dimension_matrix[0] + i);
            // Valor ij de la matriz
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            for (int k = 0; k <= i - 1; k++)
            {
                l_ik = *(*L + j * dimension_matrix[0] + k);
                u_kj = *(*U + k * dimension_matrix[0] + i);
                sum_ij += l_ik * u_kj;
            }
            // Guardado del valor de L_ij
            *L_ij = matrix_ij - sum_ij;
        }
        // Procedimiento para obtener el elemento ij de la matriz U
        l_ii = *(*L + i * dimension_matrix[0] + i);
        validate_l_ii(l_ii);
        for (int j = i + 1; j < dimension_matrix[0]; j++)
        {
            // Inicializacion de la suma
            sum_ij = 0;
            // Localizacion de la matriz U donde se calculara el elemento
            U_ij = (*U + i * dimension_matrix[0] + j);
            matrix_ij = *(matrix + j * dimension_matrix[0] + i);
            for (int k = 0; k < j - 1; k++)
            {
                l_ik = *(*L + i * dimension_matrix[0] + k);
                u_kj = *(*U + k * dimension_matrix[0] + j);
                sum_ij += l_ik * u_kj;
            }
            // Guardado del valor de L_ij
            *U_ij = (matrix_ij - sum_ij) / l_ii;
        }
    }
}