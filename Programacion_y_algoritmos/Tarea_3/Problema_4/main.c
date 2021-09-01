#include "quick_sort.h"
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
void merge(int numbers1[], int size1, int numbers2[], int size2, int result[])
{
    /* 
    Realiza la union de los dos numeros 
     */
    // Contador para numbers1
    int i = 0;
    // Contador para numbers2
    int j = 0;
    // Contador para result
    int k = 0;
    // Se repetira el ciclo hasta que los dos numeros hayan llegado a su tope
    while (i < size1 || j < size2)
    {
        // Si numbers1 es menor a numbers2 este se posicionara primero en result
        if (numbers1[i] < numbers2[j])
        {
            // Si numbers1 no ha llegado a su tope entonces se posiciona en result
            if (i < size1)
            {
                result[k] = numbers1[i];
                i++;
            }
            // Si llego a tu tope entonces numbers2 se posiciona
            else
            {
                result[k] = numbers2[j];
                j++;
            }
        }
        else
        {
            // Si numbers2 no ha llegado a su tope entonces se posiciona en result
            if (j < size2)
            {

                result[k] = numbers2[j];
                j++;
            }
            // Si llego a tu tope entonces numbers1 se posiciona
            else
            {
                result[k] = numbers1[i];
                i++;
            }
        }
        k++;
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
int main()
{
    char test;
    printf("¿Deseas usar el programa con los datos de prueba?(Y/n): ");
    scanf("%c", &test);
    if (test == 'Y' || test == 'y')
    {
        test_data();
    }
    else
    {
        custom_data();
    }
    return 0;
}