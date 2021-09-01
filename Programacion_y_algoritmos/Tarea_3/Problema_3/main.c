#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void print_lines()
{
    printf("\n------------------------");
    printf("------------------------\n");
}
void products(int numbers[], long int product[], int size)
{
    int i;
    long int all_product = 1;
    for (i = 0; i < size; i++)
    {
        all_product *= numbers[i];
    }
    for (int i = 0; i < size; i++)
    {
        product[i] = all_product / numbers[i];
    }
}
void fill_numbers(int numbers[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 20 + 1;
    }
}
void print_results(int numbers[], long int product[], int size)
{
    print_lines();
    printf("\n Numbers\tProduct\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d\t%ld\n", numbers[i], product[i]);
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