#include <stdio.h>
#include <math.h>
/* 
Asume you have n values x, evaluate the sample mean, sample variance with two-pass algorithm and one-pass algorithm
 */
double obtain_mean(double data[], int size)
{
    /*
    Obtiene el promedio de una lista de datos dada y su tamaño
    */
    double mean = 0.0;
    for (int i = 0; i < size; i++)
    {
        mean += data[i];
    }
    mean = mean / size;
    return mean;
}
long double obtain_variance_two_pass(double data[], int size)
{
    /* 
    Obtiene la varianza de una lista de datos dada y su tamaño siguiendo el algoritmo de two-pass
     */
    double mean = obtain_mean(data, size);
    double variance = 0.0;
    for (int i = 0; i < size; i++)
    {
        variance += pow(data[i] - mean, 2);
    }
    variance = variance / size;
    return variance;
}
long double obtain_variance_one_pass(double data[], int size)
{
    /* 
    Obtiene la varianza de una lista de datos dada y su tamaño siguiendo el algoritmo de one-pass
     */
    // Inicializacion de las sumas
    long double mean = 0.0;
    long double sum_x2 = 0.0;
    for (int i = 0; i < size; i++)
    {
        // Suma de los terminos al cuadrado
        sum_x2 += pow(data[i], 2);
        // Suma para obtener el promedio
        mean += data[i];
    }
    mean = mean / size;
    mean = pow(mean, 2);
    sum_x2 = sum_x2 / size;
    return sum_x2 - mean;
}
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
