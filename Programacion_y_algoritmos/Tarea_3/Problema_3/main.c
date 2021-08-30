#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void products(int numbers[], int product[], int size)
{
    product[0] = numbers[0];
    for (int i = 1; i < size; i++)
    {
        product[i] = numbers[i] * product[i - 1];
    }
}
void fill_numbers(int numbers[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 5 + 1;
    }
}
int main()
{
    int size = 10;
    int numbers[size];
    int product[size];
    fill_numbers(numbers, size);
    products(numbers, product, size);
    printf("Numbers\tProduct\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\n", numbers[i], product[i]);
    }
    return 0;
}