#include "legendre_polynome.h"
double legende_polynome(double x, int n)
{

    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    return ((double)(2 * n - 1) * x * legende_polynome(x, n - 1) - (n - 1) * legende_polynome(x, n - 2)) / n;
}
double obtain_ai(int i, int n)
{
    double up = pi * (i + 0.75);
    double down = n + 1.05;
    return cos(up / down);
}
