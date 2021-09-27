#include <stdlib.h>
#include <time.h>
void fill_numbers(int numbers[], int size)
{
    /* 
    Llenado aleatorio de numeros entre -50 y 50
     */
    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 100 - 50;
    }
}
void test_data()
{
    // Inicailizacion para los numeros aleatorios
    srand(time(NULL));
    // Tamaño de numeros 1 entre 1-20
    int size_1 = rand() % 20 + 1;
    // Tamaño de numeros 2 entre 1-20
    int size_2 = rand() % 20 + 1;
    // Tamaño de numeros 3
    int size_3 = size_1 + size_2;
    int numbers_1[size_1];
    int numbers_2[size_2];
    int result[size_3];
    // Llenado con numeros aleatorios
    fill_numbers(numbers_1, size_1);
    fill_numbers(numbers_2, size_2);
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