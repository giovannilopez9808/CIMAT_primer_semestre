#include <stdio.h>
#include <math.h>
double function(double x)
{
    /* 
    Definicion de la funcion a usar
     */
    return sin(x);
}
double left_endpoint(double xi, double dx, int n)
{
    /*
    Algoritmo de integracion usando el extremo izquierdo
     */
    double ifx = 0;
    double x;
    for (int i = 1; i < n + 1; i++)
    {
        // Definicion de la x a evaluar
        x = xi + (i - 1) * dx;
        // Suma
        ifx += function(x) * dx;
    }
    return ifx;
}
double right_endpoint(double xi, double dx, int n)
{
    /*
    Algoritmo de integracion usando el extremo derecho
     */
    double ifx = 0;
    double x;
    for (int i = 1; i < n + 1; i++)
    {
        // Definicion de la x a evaluar
        x = xi + i * dx;
        // Suma
        ifx += function(x) * dx;
    }
    return ifx;
}
void print_results(double left, double right)
{
    /* 
    Impresion en terminal de los resultados
    */
    printf("Resultado de las integrales:\n");
    printf("\tLeft-endpoint:\t%lf\n", left);
    printf("\tRight-endpoint:\t%lf\n", right);
    printf("\tDiferencia:\t%lf\n", fabs(right - left));
}
int main()
{
    // Numero de puntos a evaluar
    int n = 10;
    // Numero pi
    double pi = 2 * asin(1.0);
    // Limite inferior y superior de la integral
    double xi = 0.0, xf = pi / 2;
    // Calculo del diferencial
    double dx = (xf - xi) / n;
    // Integral con el algoritmo del extremo izquierdo
    double left = left_endpoint(xi, dx, n);
    // Integral con el algoritmo del extremo derecho
    double right = right_endpoint(xi, dx, n);
    print_results(left, right);
    return 0;
}