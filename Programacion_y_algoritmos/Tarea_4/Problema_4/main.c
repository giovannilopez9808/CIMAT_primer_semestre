#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "quick_sort.h"
#define size 20
void print_lines()
{
    printf("\n-----------------");
    printf("-----------------\n");
}

int generate_random_number(int n)
{
    /* 
    Genera aleatoriamente numeros entre 0,1,2,...,n
     */
    return rand() % n;
}
void initialize_data(int data[size], int positions[size])
{
    for (int i = 0; i < size; i++)
    {
        positions[i] = i;
        data[i] = generate_random_number(50);
    }
}
void print_data(int data[size], int positions[size], int max)
{
    /* 
    Realiza la impresion de los datos con su indice
     */
    print_lines();
    printf("Impresion de los %d primeros datos\n\nPosicion\tValor\n", max);
    for (int i = 0; i < max; i++)
    {
        printf("%d\t\t%d\n", positions[i], data[i]);
    }
}
int main()
{
    srand(time(NULL));
    int data[size];
    int positions[size];
    // Inicializacion de los datos
    initialize_data(data, positions);
    // Impresion de los datos
    print_data(data, positions, size);
    // Orenamiento
    sorted(data, positions, 0, size - 1);
    // Impresion de los primeros tres
    print_data(data, positions, 3);
    return 0;
}