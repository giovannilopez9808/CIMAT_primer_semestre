#include "Modules/heat_equation.h"
double f(double x, double t)
{
    return 10 * exp(-(x * x - t)) + 10;
}
int main()
{
    Parameters parameters;
    parameters.x_min = 0.0;
    parameters.x_max = 100.0;
    parameters.x_num = 100;
    parameters.t_min = 0.0;
    parameters.t_max = 3.0;
    parameters.t_num = 200;
    parameters.k = 1000;
    parameters.ua = 100;
    parameters.ub = 0;
    solve_system(parameters, f);
    return 0;
}