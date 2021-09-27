#include <stdlib.h>
#include <time.h>
void fill_numbers(int numbers[], int size)
{
    /* 
    Llenado de numeros aleatorios entre 1 y 20
     */
    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 20 + 1;
    }
}
void test_data()
{
    /*
    Caso para datos de prueba generados aleatoriamente 
     */
    srand(time(NULL));
    // Tamaño de los datos entre 1 y 20
    int size = rand() % 20 + 1;
    int numbers[size];
    long int product[size];
    // Llenado de los datos
    fill_numbers(numbers, size);
    // Producto acumulado del elemento i
    products(numbers, product, size);
    // Impresion de los resultados
    print_results(numbers, product, size);
}
