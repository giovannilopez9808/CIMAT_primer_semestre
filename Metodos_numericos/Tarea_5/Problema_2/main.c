#include "functions.h"
#include "bisection.h"
#include "newton.h"
#include "secant.h"
double function(double x)
{
    double f;
    f = 3000 * (10 - x) + 5000 * sqrt(x * x + 25);
    return f;
}
int main()
{
    printf("Los valores mínimos de la función son:\n");
    bisection_method(function, 0, 10);
    newton_method(function, 2);
    secant_method(function, 0, 5);
    return 0;
}