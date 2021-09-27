
double generate_random_number(int n)
{
    /* 
    Genera aleatoriamente numeros entre 0,1,2,...,n
     */
    return (double)(rand() % n);
}
void initialize_data(double **data, double **moving_average, double **median, int size[])
{
    *data = (double *)malloc(size[0] * size[1] * sizeof(double));
    *median = (double *)malloc(size[0] * size[1] * sizeof(double));
    *moving_average = (double *)malloc(size[0] * size[1] * sizeof(double));
    double *Data_ij, *Ma_ij, *Median_ij, number;
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
        {
            Data_ij = (*data + j * size[0] + i);
            Ma_ij = (*moving_average + j * size[0] + i);
            Median_ij = (*median + j * size[0] + i);
            number = generate_random_number(20);
            *Ma_ij = number;
            *Median_ij = number;
            *Data_ij = number;
        }
    }
}