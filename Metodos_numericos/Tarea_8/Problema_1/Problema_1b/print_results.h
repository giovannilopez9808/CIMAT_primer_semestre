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
        for (int j = 0; j < dimension_matrix[1]; j++)
        {
            fprintf(file, "%lf\t", *(matrix + j * dimension_matrix[0] + i));
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
               i + 1,
               *(solution + i));
    }
}
void write_each_central_solution(FILE *results, double *solution, int n)
{
    int pos = n / 2;
    double central_value = *(solution + pos);
    fprintf(results, "%d,%lf\n", n, central_value);
}