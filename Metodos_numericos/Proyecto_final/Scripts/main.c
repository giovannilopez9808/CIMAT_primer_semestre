#include "Modules/heat_equation.h"
double f(double x, double t)
{
    return 2 * exp(-(x * x - t)) + 2;
}
int main()
{
    Parameters parameters;
    parameters.x_min = 0.0;
    parameters.x_max = 100.0;
    parameters.x_num = 200;
    parameters.t_min = 0.0;
    parameters.t_max = 3.0;
    parameters.t_num = 200;
    parameters.k = 100;
    parameters.ua = 0;
    parameters.ub = 0;
    solve_system(parameters, f);
    return 0;
}