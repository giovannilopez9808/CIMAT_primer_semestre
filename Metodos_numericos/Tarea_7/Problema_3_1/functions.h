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