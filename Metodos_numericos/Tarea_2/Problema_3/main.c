#include <stdio.h>
#include <math.h>
double factorial(int n)
{
    /* 
    Definicion del factorial
    */
    double result = 1;
    for (int i = 1; i < n + 1; i++)
    {
        result = result * i;
    }
    return result;
}
double obtain_ai(int i)
{
    double ai = 1 / factorial(i);
    return ai;
}
double function_approximation(double x, int n)
{
    /* 
    Definicion de la funcion aproximada.
    f(x)=\sum_{i=0}^n (x^i)/i!
     */
    double fx = obtain_ai(n);
    for (int i = n - 1; i >= 0; i--)
    {
        fx = obtain_ai(i) + x * fx;
    }
    return fx;
}
void print_result(double x, double n)
{
    /* 
    Imprime el resultado de la funcion 
     */
    printf("f(%lf) = %lf\n", x, function_approximation(x, n));
}
void custom_problem()
{
    /* 
    Entorno para recibir valores de entrada
     */
    int n;
    double x;
    printf("Escribe el número de terminos de la serie que quieres calcular:\n");
    scanf("%d", &n);
    printf("Escribe el número de x que quieres evaluar:\n");
    scanf("%lf", &x);
    print_result(x, n);
}
void test_problem()
{
    /* 
    Entorno para mostrar los valores de prueba
     */
    int n = 10;
    double x = 2.0;
    print_result(x, n);
}
void init_program()
{
    /* 
    Entorno para decidir si se usaran valores predefinidos o del usuario
     */
    char test;
    printf("¿Deseas usar el programa con los datos de prueba?(Y/n): ");
    scanf("%c", &test);
    if (test == 'Y' || test == 'y')
    {
        test_problem();
    }
    else
    {
        custom_problem();
    }
}
int main()
{
    init_program();
    return 0;
}
