double obtain_moving_average_ij(double *data, int pos_ij[], int size[])
{
    /* 
    Obtiene el promedio de una sub matriz de 3x3
    inputs:
    + data: informacion de la matriz original
    + pos_ij: posicion central de la matriz 
    + size: tamaño de la matriz
     */
    // Inicializacion de suma
    double data_ij, sum = 0;
    for (int i = pos_ij[0] - 1; i < pos_ij[0] + 2; i++)
    {
        for (int j = pos_ij[1] - 1; j < pos_ij[1] + 2; j++)
        {
            // dato de la matriz de la posicion ij
            data_ij = *(data + j * size[0] + i);
            // Suma
            sum += data_ij;
        }
    }
    // Promedio
    sum = sum / 9;
    return sum;
}
double obtain_median_ij(double *data, int pos_ij[], int size[])
{
    /* 
    Obtiene la mediana de una sub matriz de 3x3
    inputs:
    + data: informacion de la matriz original
    + pos_ij: posicion central de la matriz 
    + size: tamaño de la matriz
     */
    // Inicializa la lista de los nueve datos de la sub matriz de 3x3
    double data_ij, median_ij[9];
    int k = 0;
    for (int i = pos_ij[0] - 1; i < pos_ij[0] + 2; i++)
    {
        for (int j = pos_ij[1] - 1; j < pos_ij[1] + 2; j++)
        {
            // dato de la matriz de la posicion ij
            data_ij = *(data + j * size[0] + i);
            // Guarda el dato
            median_ij[k] = data_ij;
            k++;
        }
    }
    // Ordena los datos para obtener la media
    sorted(median_ij, 0, 8);
    // Mediana
    return median_ij[4];
}
void obtain_moving_average_and_median(double *data, double *moving_average, double *median, int size[])
{
    /* 
    Obtiene el moving average y la mediana de una matriz
    inputs:
    + data: puntero de los datos originales
    + moving average: puntero hacia los datos del moving average
    + median: puntero hacia los datos de la mediana
    + size: tamaño de las matrices
     */
    double *Ma_ij, *Median_ij;
    int pos_ij[2];
    for (int i = 1; i < size[0] - 1; i++)
    {
        for (int j = 1; j < size[1] - 1; j++)
        {
            // posicion ij del moving average
            Ma_ij = (moving_average + j * size[0] + i);
            // posicion ij de la mediana
            Median_ij = (median + j * size[0] + i);
            pos_ij[0] = i;
            pos_ij[1] = j;
            // obtiene el moving average
            *Ma_ij = obtain_moving_average_ij(data, pos_ij, size);
            // obtiene la mediana
            *Median_ij = obtain_median_ij(data, pos_ij, size);
        }
    }
}