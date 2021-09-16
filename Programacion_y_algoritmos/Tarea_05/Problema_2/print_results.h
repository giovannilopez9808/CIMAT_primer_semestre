void print_lines()
{
    printf("\n--------------------------------------");
    printf("--------------------------------------\n");
}

void print_data(double *data, int size[], char *data_name)
{
    /* 
    Realiza la impresion de los datos con su indice
     */
    print_lines();
    printf("%s\n\n", data_name);
    double data_ij;
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
        {
            data_ij = *(data + j * size[0] + i);
            printf("%lf\t", data_ij);
        }
        printf("\n");
    }
}