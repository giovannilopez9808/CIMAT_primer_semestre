void print_matrix(double *matrix, int dimension_matrix[])
{
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = 0; j < dimension_matrix[0]; j++)
        {
            printf("%lf\t", *(matrix + i * dimension_matrix[0] + j));
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
               i + 1,
               *(solution + i));
    }
}