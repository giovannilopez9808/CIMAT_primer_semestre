void read_numbers(int numbers[], int size)
{
    /* 
    Realiza la lectura de los datos dado un tamaño de estos
     */
    for (int i = 0; i < size; i++)
    {
        printf("Escribe el numero %d de %d: ", i + 1, size);
        scanf("%d", &numbers[i]);
    }
}
void custom_data()
{
    /* 
    Lectura de datos de un usuario y ejecucion del algoritmo con los datos recabados
     */
    int size;
    printf("\nEscribe el tamaño de los datos: ");
    scanf("%d", &size);
    int numbers[size];
    long int product[size];
    // Lectura de los datos
    read_numbers(numbers, size);
    // Producto acumulado de cada elemento
    products(numbers, product, size);
    // Impresion de los resultados
    print_results(numbers, product, size);
}