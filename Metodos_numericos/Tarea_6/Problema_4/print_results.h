void print_initial_state(double *matrix, int dimension_matrix[], double *results)
{
    print_lines();
    printf("Estado inicial del problema\n\n");
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        for (int j = 0; j < dimension_matrix[1]; j++)
        {
            printf("%lf ", *(matrix + i + dimension_matrix[0] * j));
        }
        printf("\t| %lf\n", *(results + i));
    }
    printf("\n");
}
void print_solution(double *solution, int dimension_matrix[])
{
    print_lines();
    printf("Soluciones del sistema\n\n");
    for (int i = 0; i < dimension_matrix[0]; i++)
    {
        printf("x_%d =\t%lf\n", i + 1, *(solution + i));
    }
}