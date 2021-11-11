#include "simpson_algorithm.h"
double obtain_h(double b, double a, int n)
{
    return (b - a) / (double)n;
}
double obtain_xi(double a, int i, double h)
{
    return a + (double)i * h;
}
double simpson_method(double (*f)(double), double a, double b, int n)
{
    double sum_i, sum = 0, h = obtain_h(b, a, n);
    for (int i = 1; i < n / 3 + 1; i++)
    {
        sum_i = f(obtain_xi(a, 3 * i - 3, h));
        sum_i += 3 * f(obtain_xi(a, 3 * i - 2, h));
        sum_i += 3 * f(obtain_xi(a, 3 * i - 1, h));
        sum_i += f(obtain_xi(a, 3 * i, h));
        sum += sum_i;
    }
    sum = 3 * h * sum / 8;
    return sum;
}