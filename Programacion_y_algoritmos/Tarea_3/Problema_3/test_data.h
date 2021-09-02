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
    srand(time(NULL));
    int size = rand() % 20 + 1;
    int numbers[size];
    long int product[size];
    fill_numbers(numbers, size);
    products(numbers, product, size);
    print_results(numbers, product, size);
}
