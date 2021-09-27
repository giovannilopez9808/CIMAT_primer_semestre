void print_lines()
{
    printf("----------------------");
    printf("----------------------\n");
}
void valid_solution(double number)
{
    /* 
    Realiza la validacion del sistema de ecuaciones lineales
     */
    if (number == 0)
    {
        print_lines();
        printf("Sistema sin solución\n");
        exit(1);
    }
}
void valid_file(FILE *text_file)
{
    /* 
    Validacion del archivo
     */
    if (text_file == NULL)
    {
        printf("File error\n");
        exit(1);
    }
}
void read_dimension(FILE *file, int dimension[])
{
    /* 
    Lectura de las dimensiones de la matriz a partir de un archivo dado
    inputs:
    + file: puntero del archivo
    + dimension: arreglo de dimension 2 de tipo entero
     */
    fscanf(file,
           "%d %d",
           &dimension[0],
           &dimension[1]);
}
void read_matrix(FILE *file, int dimension[], double **matrix)
{
    /* 
    Lectura de los datos de la matriz a partir de un archivo dado
    inputs:
    + file: puntero del archivo
    + dimension: arreglo de dimension 2 de tipo entero
    + matrix: doble puntero de un tipo de dato double donde se alojaran los datos de la matriz
     */
    *matrix = (double *)malloc((dimension[0]) * (dimension[1]) * sizeof(double));
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            fscanf(file, "%lf",
                   (*matrix + j * dimension[0] + i));
        }
    }
}
void obtain_multiplication_matrix(double *A, double *B, double *AB, int dimension_matrix_A[], int dimension_matrix_B[])
{
    /* 
    Realiza la multiplicacion de matrices
     */
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
double obtain_max_value(double *vector, int dimension[])
{
    double v_i;
    double max = *vector;
    for (int i = 1; i < dimension[0]; i++)
    {
        v_i = fabs(*(vector + i));
        if (max < v_i)
        {
            max = v_i;
        }
    }
    return max;
}
void normalize_vector(double *vector, int dimension[])
{
    double max = obtain_max_value(vector, dimension);
    double *V_i;
    for (int i = 0; i < dimension[0]; i++)
    {
        V_i = (vector + i);
        *V_i = *V_i / max;
    }
}
void write_matrix_on_file(FILE *file, double *matrix, int dimension_matrix[])
{
    /* 
    Imprime la matriz dada en un archivo
    inputs:
    + file: puntero del archivo a escribir
    + matrix: puntero que contiene los datos de la matriz a imprimir
    + dimension_matrix: arreglo de dos dimensiones que contiene las dimensiones de la matriz
     */
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = 0; j < dimension_matrix[0]; j++)
        {
            fprintf(file, "%lf\t", *(matrix + i * dimension_matrix[0] + j));
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}
void print_matrix(double *matrix, int dimension_matrix[])
{
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = 0; j < dimension_matrix[1]; j++)
        {
            printf("%lf\t", *(matrix + j * dimension_matrix[0] + i));
        }
        printf("\n");
    }
    printf("\n");
}
void print_solution(double *solution, int dimension_matrix[])
{
    /* 
    Realiza la impresion de la solucion del sistema de ecuaciones
     */
    print_lines();
    printf("Soluciones del sistema\n\n");
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        printf("x_%d\t= %lf\n",
               i,
               *(solution + i));
    }
}
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
void solve_triangular_superior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    /* 
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular superior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
    double result_i, matrix_ii, matrix_ij, sum_ij;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = dimension_matrix[0] - 1; i >= 0; i--)
    {
        // Inicializacion del contador
        sum_ij = 0;
        // Obtiene el termino b_i
        result_i = *(results + i);
        // Obtiene el termino a_i
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Valida la solucion del sistema
        valid_solution(matrix_ii);
        for (int j = dimension_matrix[0] - 1; j > i; j--)
        {
            // Obtiene el termino a_ij
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            // Realiza la suma del producto de x_j*a_ij
            sum_ij += *(*solutions + j) * matrix_ij;
        }
        // Obtiene el termino x_i
        *(*solutions + i) = (result_i - sum_ij) / matrix_ii;
    }
}
void solve_triangular_inferior_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    /* 
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular inferior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
    double result_i, matrix_ii, matrix_ij, sum_ij;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Inicializacion del contador
        sum_ij = 0;
        // Obtiene el termino b_i
        result_i = *(results + i);
        // Obtiene el termino a_ii
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Validacion de la existencia de la solucion
        valid_solution(matrix_ii);
        for (int j = 0; j < i; j++)
        {
            // Obtiene el termino a_ij
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            // Realiza la suma de los productos x_j*a_ij
            sum_ij += *(*solutions + j) * matrix_ij;
        }
        // Obtiene el termino x_i
        *(*solutions + i) = (result_i - sum_ij) / matrix_ii;
    }
}
void solve_diagonal_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    /* 
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz diagonal
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
    double result_i, matrix_ii;
    *solutions = (double *)malloc((dimension_matrix[0]) * sizeof(double));
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        // Obtiene el termino b_i
        result_i = *(results + i);
        // Obtiene el termino a_i
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        valid_solution(matrix_ii);
        // Obtiene el termino x_i
        *(*solutions + i) = result_i / matrix_ii;
    }
}
void solve_gaussian_matrix(double *matrix, int dimension_matrix[], double *results, double **solutions)
{
    /* 
    Resuleve un sistema de ecuaciones supongiendo que se trata de una matriz triangular superior
    inputs:
    + matrix: puntero de un arreglo de datos bidimensional
    + dimension_matrix: arreglo de enteros de dimension 2
    + results: puntero de un arreglo que contiene los datos de la matriz extendida del sistema
    + solutions: doble puntero de tipo double que alojara las soluciones del sistema
     */
    double matrix_ii, matrix_ij, matrix_jk, matrix_ik, ratio_ij, result_i;
    double *Matrix_jk, *Result_j;
    for (int i = 0; i < dimension_matrix[0] - 1; i++)
    {
        // Obtiene el termino a_ii
        matrix_ii = *(matrix + i * dimension_matrix[0] + i);
        // Obitene el termino b_i
        result_i = *(results + i);
        for (int j = i + 1; j < dimension_matrix[0]; j++)
        {
            // Obtiene el termino a_ij
            matrix_ij = *(matrix + i * dimension_matrix[0] + j);
            // Valida la solucion del sistema
            valid_solution(matrix_ij);
            // Obtiene el factor que se multiplicara en toda la fila
            ratio_ij = matrix_ii / matrix_ij;
            // Obtiene el puntero de
            Result_j = (results + j);
            // Obtiene x_j por el factor
            *Result_j = *Result_j * ratio_ij - result_i;
            // Proceso de diferencias entrre la i-esima fila
            for (int k = i; k < dimension_matrix[1]; k++)
            {
                matrix_ik = *(matrix + k * dimension_matrix[0] + i);
                matrix_jk = *(matrix + k * dimension_matrix[0] + j);
                Matrix_jk = (matrix + k * dimension_matrix[0] + j);
                *Matrix_jk = (matrix_jk * ratio_ij - matrix_ik);
            }
        }
    }
    // La matriz fue transformada a una triangular superior
    solve_triangular_superior_matrix(matrix,
                                     dimension_matrix,
                                     results,
                                     solutions);
}