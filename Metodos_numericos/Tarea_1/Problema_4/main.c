#include <stdio.h>
#include "functions.h"
/* 
Asume you have n values x, evaluate the sample mean, sample variance with two-pass algorithm and one-pass algorithm
 */
void obtain_mean_and_variances(double data[], int size)
{
    /* 
    Ejecuta el calculo del promedio y la varianza usando los algoritmos de two-pass y one-pass
     */
    double mean = obtain_mean(data, size);
    double variance = obtain_variance_two_pass(data, size);
    long double variance_2 = obtain_variance_one_pass(data, size);
    printf("--------------------------------------\n");
    printf("El promedio de los datos es:\n%lf\n", mean);
    printf("La varianza usando el algoritmo two-pass de los datos es:\n%lf\n", variance);
    printf("La varianza usando el algoritmo one-pass de los datos es:\n%Lf\n", variance_2);
}
int read_size()
{
    /* 
    Lectura del tamaño de los datos
     */
    int size;
    printf("Escribe el total de datos tienes:\n");
    scanf("%d", &size);
    return size;
}
void read_data(double data[], int size)
{
    /* 
    Lectura de los datos
     */
    for (int i = 0; i < size; i++)
    {
        printf("Escribe el numero de la posición %d de %d:\n", i + 1, size);
        scanf("%lf", &data[i]);
    }
}
void custom_data()
{
    int size = read_size();
    double data[size];
    read_data(data, size);
    // Ejecuccion de los algoritmos
    obtain_mean_and_variances(data, size);
}
void data_1()
{
    double data[] = {0.00,
                     0.01,
                     0.02,
                     0.03,
                     0.04,
                     0.05,
                     0.06,
                     0.07,
                     0.08,
                     0.09};
    int size = 10;
    // Ejecuccion de los algoritmos
    obtain_mean_and_variances(data, size);
}
void data_2()
{
    double data[] = {123456789.00,
                     123456789.01,
                     123456789.02,
                     123456789.03,
                     123456789.04,
                     123456789.05,
                     123456789.06,
                     123456789.07,
                     123456789.08,
                     123456789.09};
    int size = 10;
    // Ejecuccion de los algoritmos
    obtain_mean_and_variances(data, size);
}
void test_data()
{
    data_1();
    data_2();
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
}
