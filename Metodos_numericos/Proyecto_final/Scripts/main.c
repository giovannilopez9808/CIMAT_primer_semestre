#include "Modules/heat_equation.h"
double f(double x, double t)
{
    // return 2 * exp(-(x * x - t)) + 2;
    return 10 * x * (1 - x) * cos(10 * t) + 2 * sin(10 * t);
}
double f0(double x)
{
    return sin(pi * x);
}
int main()
{
    Parameters parameters;
    parameters.x_min = 0.0;
    parameters.x_max = 1.0;
    parameters.x_num = 20;
    parameters.t_min = 0.0;
    parameters.t_max = 1.0;
    parameters.t_num = 20;
    parameters.k = 1;
    parameters.ua = 0;
    parameters.ub = 0;
    solve_system(parameters, f0, f);
    return 0;
}