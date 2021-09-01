#include <stdio.h>
void print_lines()
{
    printf("\n------------------------");
    printf("------------------------\n");
}
void print_results(int numbers[], long int product[], int size)
{
    /* 
    Impresion de los resultados
     */
    print_lines();
    printf("\n Numbers\tProduct\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d\t\t%ld\n", numbers[i], product[i]);
    }
}