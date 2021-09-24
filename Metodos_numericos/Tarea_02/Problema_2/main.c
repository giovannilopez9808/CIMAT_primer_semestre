#include <stdio.h>
#include <math.h>
double function(double x)
{
    /* 
    Obtiene el valor de la funcion
     */
    return 1 / (sqrt(pow(x, 2) + 1) - x);
}
double function_racionalized(double x)
{
    /*
Obtiene el valor de la funcion  racionalizada
 */
    return sqrt(pow(x, 2) + 1) + x;
}
void init_program(double x)
{
    /* 
    Ejecucion de las tres funciones dado un valor de x e imprime los resultados
     */
    printf("------------------------------\n");
    printf("Para x\t= %lf\n", x);
    // Evalua la fncion
    double fx = function(x);
    printf("f(x)\t= %lf\n", fx);
    // Evalua la función racionalizada
    double frx = function_racionalized(x);
    printf("fr(x)\t= %lf\n", frx);
    printf("RD(x)\t= %lf\n", fabs(frx - fx));
}
int main()
{
    // Numero de potenicas de 10 que usara
    int n = 8;
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
