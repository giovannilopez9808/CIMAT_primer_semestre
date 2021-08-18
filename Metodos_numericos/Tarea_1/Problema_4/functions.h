#include <math.h>
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
        sum_x2 += powl(data[i], 2);
        // Suma para obtener el promedio
        mean += data[i];
    }
    mean = mean / size;
    mean = powl(mean, 2);
    sum_x2 = sum_x2 / size;
    return sum_x2 - mean;
}