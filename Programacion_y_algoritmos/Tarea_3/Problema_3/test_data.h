#include <stdlib.h>
#include <time.h>
void fill_numbers(int numbers[], int size)
{
    /* 
    Llenado de numeros aleatorios entre 1 y 20
     */
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 20 + 1;
    }
}
void test_data()
{
    int size = 5;
    int numbers[size];
    long int product[size];
    fill_numbers(numbers, size);
    products(numbers, product, size);
    print_results(numbers, product, size);
}