void swap(int *number1, int *number2)
{
    /* 
    Realiza el intercambio de valores
     */
    int aux = *number1;
    *number1 = *number2;
    *number2 = aux;
}

int reduce_sort(int numbers[], int positions[], int low, int high)
{
    // Seleccion del pivote
    int pivot = numbers[high];
    // posicion inicial de la lista de numeros
    int i = low;
    for (int j = low; j <= high - 1; j++)
    {
        // Si el elemento j es menor o igual al pivote entonces se realizara u intercambio
        if (numbers[j] >= pivot)
        {
            swap(&numbers[i], &numbers[j]);
            swap(&positions[i], &positions[j]);
            i++;
        }
    }
    // Intercambio del pivote con el elemento i, para que los elementos en la posicion menores a i tengan un valor menor igual a el pivote
    swap(&numbers[i], &numbers[high]);
    swap(&positions[i], &positions[high]);
    return i;
}

void sorted(int numbers[], int positions[], int start, int last)
{
    /* 
    Realiza el ordenamiento de los numeros de forma creciente siguiendo el algoritmo de quick sort 
     */
    if (start < last)
    {
        int numbers_partition;
        numbers_partition = reduce_sort(numbers, positions, start, last);
        // Ordena la parte inferior
        sorted(numbers,
               positions,
               start,
               numbers_partition - 1);
        // Ordena la parte superior
        sorted(numbers,
               positions,
               numbers_partition + 1,
               last);
    }
}