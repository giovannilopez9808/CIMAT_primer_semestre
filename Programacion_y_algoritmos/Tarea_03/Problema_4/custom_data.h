void read_numbers(int numbers[], int size)
{
    /* 
    Lectura de los datos dado un tamaño de estos
     */
    for (int i = 0; i < size; i++)
    {
        printf("Escribe el numero %d de %d: ", i + 1, size);
        scanf("%d", &numbers[i]);
    }
}
void custom_data()
{
    // Tamaño de numeros 1
    int size_1, size_2;
    printf("Escribe el tamaño de los datos 1: ");
    scanf("%d", &size_1);
    printf("Escribe el tamaño de los datos 2: ");
    scanf("%d", &size_2);
    int numbers_1[size_1];
    int numbers_2[size_2];
    printf("\nDatos 1:\n");
    read_numbers(numbers_1, size_1);
    printf("\nDatos 2:\n");
    read_numbers(numbers_2, size_2);
    // Tamaño de numeros 3
    int size_3 = size_1 + size_2;
    int result[size_3];
    // Ordenas de forma creciente los numeros
    sorted(numbers_1, 0, size_1 - 1);
    sorted(numbers_2, 0, size_2 - 1);
    // Impresion de los numeros
    printf("\nNumbers 1:\n");
    print_array(numbers_1, size_1);
    printf("\nNumbers 2:\n");
    print_array(numbers_2, size_2);
    // Merge de los numeros ordenados de forma creciente
    merge(numbers_1, size_1, numbers_2, size_2, result);
    printf("\nMerge numbers:\n");
    print_array(result, size_3);
}