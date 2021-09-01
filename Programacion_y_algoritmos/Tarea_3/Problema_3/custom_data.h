void read_numbers(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Escribe el numero %d de %d: ", i + 1, size);
        scanf("%d", &numbers[i]);
    }
}
void custom_data()
{
    int size;
    printf("\nEscribe el tamaño de los datos: ");
    scanf("%d", &size);
    int numbers[size];
    long int product[size];
    read_numbers(numbers, size);
    products(numbers, product, size);
    print_results(numbers, product, size);
}