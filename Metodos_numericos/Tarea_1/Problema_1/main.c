#include <stdio.h>
#include <math.h>
/* 
Find intervals contains solutions to the following equations
 */
float function1(float x)
{
    return x - pow(2, -x);
}
float function2(float x)
{
    return 2 * x * cos(2 * x) - pow(x + 1, 2);
}
float evaluate_function(int select, float x)
{
    switch (select)
    {
    case 1:
        return function1(x);
        break;
    case 2:
        return function2(x);
        break;
    default:
        return 0;
        break;
    }
}
void binary_search(float x, float fx, float limits[])
{
    if (fx > 0)
    {
        limits[1] = x;
    }
    else
    {
        limits[0] = x;
    }
}
float obtain_middle_point(float limits[])
{
    return (limits[0] + limits[1]) / 2;
}
void change_limits(float xi, float xf, float limits[], int select)
{
    float fxi = evaluate_function(select, xi);
    float fxf = evaluate_function(select, xf);
    if (fxi < fxf)
    {
        limits[0] = xi;
        limits[1] = xf;
    }
    else
    {
        limits[0] = xf;
        limits[1] = xi;
    }
}

int main()
{
    int select;
    float xi, xf, x, fx;
    float limits[2];
    printf("Selecciona la funcion que quieres usar\nOpciones:\n\t1) x - 2**(-x)\n\t2) 2xcos(2x)-(x+1)**2\n");
    scanf("%d", &select);
    printf("Ingresa el valor del intervalo inferior:\n");
    scanf("%f", &xi);
    printf("Ingresa el valor del intervalo inferior:\n");
    scanf("%f", &xf);
    change_limits(xi,
                  xf,
                  limits,
                  select);
    x = obtain_middle_point(limits);
    fx = evaluate_function(select, x);
    while (fabs(fx) > 0.0001)
    {
        binary_search(x,
                      fx,
                      limits);
        x = obtain_middle_point(limits);
        fx = evaluate_function(select,
                               x);
    }
    printf("La raiz de la funcion es %f con f(x)=%f", x, fx);
    return 0;
}