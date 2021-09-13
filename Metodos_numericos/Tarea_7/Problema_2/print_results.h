void write_matrix_on_file(FILE *file, double *matrix, int dimension_matrix[])
{
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