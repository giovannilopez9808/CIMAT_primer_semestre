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