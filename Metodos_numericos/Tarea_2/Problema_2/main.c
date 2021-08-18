#include <stdio.h>
#include <math.h>
float float_function(double x)
{
    /* 
    Obtiene el valor de la funcion usando unicamente float
     */
    return 1 / (sqrtf(powf(x, 2) + 1) - x);
}
double double_function(double x)
{
    /* 
    Obtiene el valor de la funcion usando unicamente double
     */
    return 1 / (sqrt(pow(x, 2) + 1) - x);
}
long double long_double_function(double x)
{
    /* 
    Obtiene el valor de la funcion usando unicamente long double
    */
    return 1 / (sqrtl(powl(x, 2) + 1) - x);
}
void init_program(double x)
{
    /* 
    Ejecucion de las tres funciones dado un valor de x e imprime los resultados
     */
    printf("------------------------------\n");
    printf("Para x\t= %lf\n", x);
    // Ejecuta la funcion tipo float
    float ffx = float_function(x);
    printf("ffx(x)\t= %f\n", ffx);
    // Ejecuta la funcion tipo double
    double dfx = double_function(x);
    printf("dfx(x)\t= %lf\n", dfx);
    // Ejecuta la funcion tipo long double
    long double dlfx = long_double_function(x);
    printf("dlfx(x)\t= %Lf\n", dlfx);
}
int main()
{
    // Numero de potenicas de 10 que usara
    int n = 11;
    double x;
    for (int i = 0; i < n; i++)
    {
        // 10^i, i=0,1,2,...,n
        x = pow(10, i);
        // Calcula las tres funciones con el valor de x
        init_program(x);
    }
    return 0;
}
