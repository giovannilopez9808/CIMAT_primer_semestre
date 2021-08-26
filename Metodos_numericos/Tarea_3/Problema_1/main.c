#include <stdio.h>
#include <math.h>

double function(double x)
{
    /* 
    Evalua la funcion en x
     */
    double fx;
    fx = x * cos(x) * sin(x) / (x - sin(x));
    return fx;
}
double find_limit(double x, double limit)
{
    double fi = function(x);
    double fs = function(-x);
    double diff = fabs(fs - fi);
    printf("%lf &\t%lf\n", -x, fs);
    if (diff < 10e-6)
    {
        limit = (fi + fs) / 2;
        printf("El límite es %lf\n", limit);
    }
    return limit;
}
int main()
{
    double limit = -999;
    double x = 1;
    int i = 1;
    while (limit == -999 && i < 16)
    {
        limit = find_limit(x, limit);
        x = x / 2;
        i++;
    }
    if (limit == -999)
    {
        printf("El limite no existe\n");
    }
    return 0;
}