int convergence(double *solutions, double *solutions_i, int dimension_solutions[], int attempt)
{
    /* 
    Calcula si la convergencia del metodo es suficiente para terminarlo
    */
    double s_i, si_i;
    double theta = 0;
    // No lo calcula para el primer intento
    if (attempt != 0)
    {
        // Calcula la diferencia entre soluciones de la iteracion actual y la anterior
        for (int i = 0; i < dimension_solutions[0]; i++)
        {
            s_i = *(solutions + i);
            si_i = *(solutions_i + i);
            // Suma de las difeencias al cuadrado
            theta += (s_i - si_i) * (s_i - si_i);
        }
        // Raiz de la suma de diferencias
        theta = sqrt(theta);
        // Si cumple el criterio termina
        if (theta < 1e-7)
        {
            return 0;
        }
    }
    // Si no sigue
    return 1;
}
void fill_solutions(double *solutions, double *solutions_i, int dimension_solutions[])
{
    /* 
    Transcribe las soluciones de la iteracion actual al puntero que guarda las soluciones de la iteracion anterior
         */
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
    /* 
    Aplica el metodo de iterativo de Jacobi para matrices
    inputs:
    + matrix: puntero que dirije hacia los datos de la matrix
    + dimension_matrix: arreglo de dos dimensiones que guarda el tamaño de la matriz
    + results: puntero que dirige al vector constante del sistema de ecuaciomes
    + dimension_results: arreglo de dos dimnsiones que guarda el tamaño de la matriz
    + solutions: doble puntero en donde se guardaran las soluciones al sistema de ecuaciones
     */
    int attempt = 0;
    double *Solutions_i, *S_i;
    double m_ii, m_ij, r_i, s_j, sum;
    *solutions = (double *)malloc(dimension_results[0] * sizeof(double));
    Solutions_i = (double *)malloc(dimension_results[0] * sizeof(double));
    while (convergence(*solutions,
                       Solutions_i,
                       dimension_results,
                       attempt))
    {
        // Copia los valores de las soluciones de la iteracion actual a la anterior
        fill_solutions(Solutions_i,
                       *solutions,
                       dimension_results);
        // Obtiene el resultado x_i^k
        for (int i = 0; i < dimension_results[0]; i++)
        {
            // Elemento ii de la matrix
            m_ii = *(matrix + i * dimension_matrix[0] + i);
            valid_solution(m_ii);
            // Elemento i de x_i
            r_i = *(results + i);
            // Elemento i se las soluciones
            S_i = (*solutions + i);
            sum = 0;
            // Obtiene la suma x_i * a_ij
            for (int j = 0; j < dimension_matrix[0]; j++)
            {
                if (j != i)
                {
                    s_j = *(Solutions_i + j);
                    m_ij = *(matrix + j * dimension_matrix[0] + i);
                    sum += m_ij * s_j;
                }
            }
            *S_i = (r_i - sum) / m_ii;
        }
        // Contador de los intentos
        attempt += 1;
    }
    print_lines();
    printf("\nNúmero de iteraciones totales:\t%d\n", attempt);
    free(Solutions_i);
}