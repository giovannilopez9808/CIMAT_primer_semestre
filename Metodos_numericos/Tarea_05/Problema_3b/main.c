#include "functions.h"
#include "bisection.h"
#include "newton.h"
#include "secant.h"
double function(double x)
{
    double f;
    f = sin(x) - x * x + 1;
    return f;
}
int main()
{
    double x0 = -1;
    double x1 = 1;
    printf("Los valores mínimos de la función son:\n");
    bisection_method(function, x0, x1);
    newton_method(function, (x1 + x0) / 2);
    secant_method(function, x0, x1);
    return 0;
}
