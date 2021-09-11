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
    fscanf(file,
           "%d %d",
           &dimension[0],
           &dimension[1]);
}
void read_matrix(FILE *file, int dimension[], double **matrix)
{
    *matrix = (double *)malloc((dimension[0]) * (dimension[1]) * sizeof(double));
    for (int i = 0; i < dimension[0]; i++)
    {
        for (int j = 0; j < dimension[1]; j++)
        {
            fscanf(file, "%lf", (*matrix + j * dimension[1] + i));
        }
    }
}
