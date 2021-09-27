void swap(double *number1, double *number2)
{
    /* 
    Realiza el intercambio de valores
     */
    double aux = *number1;
    *number1 = *number2;
    *number2 = aux;
}

int reduce_sort(double numbers[], int low, int high)
{
    // Seleccion del pivote
    double pivot = numbers[high];
    // posicion inicial de la lista de numeros
    int i = low;
    for (int j = low; j <= high - 1; j++)
    {
        // Si el elemento j es menor o igual al pivote entonces se realizara u intercambio
        if (numbers[j] >= pivot)
        {
            // Realiza el cambio de valores
            swap(&numbers[i], &numbers[j]);
            i++;
        }
    }
    // Intercambio del pivote con el elemento i, para que los elementos en la posicion mayores a i tengan un valor mayor igual a el pivote
    // Realiza el cambio de valores
    swap(&numbers[i], &numbers[high]);
    return i;
}

void sorted(double numbers[], int start, int last)
{
    /* 
    Realiza el ordenamiento de los numeros de forma decreciente siguiendo el algoritmo de quick sort guardando llos cambios en las posiciones que se hagan realizado en un arreglo
     */
    if (start < last)
    {
        int numbers_partition;
        numbers_partition = reduce_sort(numbers, start, last);
        // Ordena la parte inferior
        sorted(numbers,
               start,
               numbers_partition - 1);
        // Ordena la parte superior
        sorted(numbers,
               numbers_partition + 1,
               last);
    }
}