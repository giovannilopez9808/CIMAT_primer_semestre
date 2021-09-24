// void swap(double *number1, double *number2)
// {
//     /*
//     Intercambia de posición los numeros
//      */
//     double aux = *number1;
//     *number1 = *number2;
//     *number2 = aux;
// }
// void swap_int(int *number1, int *number2)
// {
//     /*
//     Intercambia de posición los numeros
//      */
//     int aux = *number1;
//     *number1 = *number2;
//     *number2 = aux;
// }
void change_columns(double *matrix, int dimension_matrix[], int position[], int change[])
{
    /* 
    Realiza el cambio entre columnas de una matriz
    inputs:
    + matrix: puntero que dirige hacia los datos de la matriz
    + dimension_matriz: arreglo de dos dimensiones que contien el tamaño de la matriz
    + position: posicion de la primer columna de los valores que se quieres cambiar
    + change: posicion de la segunda columna de los valores que se quieres cambiar
     */
    int j_old = position[1];
    int j_new = change[1];
    double *M_old, *M_new;
    // Intercambio de toda la columna
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        M_old = (matrix + j_old * dimension_matrix[0] + i);
        M_new = (matrix + j_new * dimension_matrix[0] + i);
        // Intercambio de los valores individuales
        swap(M_old, M_new);
    }
}
void change_rows(double *matrix, int dimension_matrix[], double *results, int position[], int change[], int *solution_pos)
{
    /* 
    Realiza el cambio entre filas de una matriz
    inputs:
    + matrix: puntero que dirige hacia los datos de la matriz
    + dimension_matriz: arreglo de dos dimensiones que contien el tamaño de la matriz
    + position: posicion de la primer file de los valores que se quieres cambiar
    + change: posicion de la segunda fila de los valores que se quieres cambiar
    + solution_pos: arreglo de dos dimensiones que sigue el movimiento de cada file
     */
    int i_old = position[0];
    int i_new = change[0];
    double *M_old, *M_new, *R_old, *R_new;
    int *SP_old, *SP_new;
    R_old = (results + i_old);
    R_new = (results + i_new);
    SP_old = (solution_pos + i_old);
    SP_new = (solution_pos + i_new);
    // Intercambio del vector de resultado
    swap(R_old, R_new);
    // Intercambio del traqueo en el movimiento de cada fila
    swap_int(SP_old, SP_new);
    // Intercambio en los valores de las filas
    for (int j = 0; j < dimension_matrix[1]; j++)
    {
        M_old = (matrix + j * dimension_matrix[0] + i_old);
        M_new = (matrix + j * dimension_matrix[0] + i_new);
        // Intercambio de los valores individuales
        swap(M_old, M_new);
    }
}
void initialize_solutions_pos(int *solution_pos, int dimension_matrix[])
{
    /* 
    Inicializacion de la posicion de las soluciones
     */
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        *(solution_pos + i) = i + 1;
    }
}
void check_dominant_diagonal_matrix(double *matrix, int dimension_matrix[])
{
    /* 
    Checa si la matriz dada es diagonal dominante
     */
    print_lines();
    double sum_ij, m_ij, m_ii;
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Inicializacion de la suma de cada fila
        sum_ij = 0;
        // Elemento de la diagonal de la matriz
        m_ii = fabs(*(matrix + i * dimension_matrix[0] + i));
        for (int j = 0; j < dimension_matrix[1]; j++)
        {
            // Suma de los valores diferentes a la diagonal
            if (i != j)
            {
                // Elemento ij de la matriz
                m_ij = *(matrix + j * dimension_matrix[0] + i);
                sum_ij += fabs(m_ij);
            }
        }
        // Advertencia si la matriz no es diagonal dominante
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
    /*
    Trata de convetir una matriz en diagonal dominante
     */
    double m_ij, max;
    int max_position[2], original_position[2];
    *solution_pos = (int *)malloc(dimension_matrix[0] * sizeof(int));
    initialize_solutions_pos(*solution_pos, dimension_matrix);
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Se supone que el maximo ya se encuentra en la diagonal
        max = *(matrix + i * dimension_matrix[0] + i);
        max = fabs(max);
        original_position[0] = i;
        original_position[1] = i;
        max_position[0] = i;
        max_position[1] = i;
        // Chequeo si existe un valor mayor en alguno de los valores de la matriz menor ij
        for (int j = i; j < dimension_matrix[0]; j++)
        {
            for (int k = i; k < dimension_matrix[1]; k++)
            {
                // Elemento ij de la matriz
                m_ij = *(matrix + k * dimension_matrix[0] + j);
                // Si se encuentra un valor se guarda su valor y posicion
                if (fabs(m_ij) > max)
                {
                    max = fabs(m_ij);
                    max_position[0] = j;
                    max_position[1] = k;
                }
            }
        }
        // Si la posicion de las columnas difiere entonces se realiza un cambio
        if (i != max_position[1])
        {
            change_columns(matrix,
                           dimension_matrix,
                           original_position,
                           max_position);
        }
        // Si la posicion de las filas difiere entonces se realiza un cambio
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
    // Realiza el chequeo si se obtuvo una diagonal dominante
    check_dominant_diagonal_matrix(matrix,
                                   dimension_matrix);
}