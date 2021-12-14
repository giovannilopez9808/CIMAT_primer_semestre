#include "Modules/heat_equation.h"
double f_1(double x, double t)
{
    return 10 * x * (1 - x) * cos(10 * t) + 2 * sin(10 * t);
}
double f0_1(double x)
{
    return sin(pi * x);
}
Parameters select_dataset(int select)
{
    Parameters parameters;
    switch (select)
    {
    case 1:
        parameters.x_min = 0.0;
        parameters.x_max = 1.0;
        parameters.x_num = 20;
        parameters.t_min = 0.0;
        parameters.t_max = 1.0;
        parameters.t_num = 20;
        parameters.k = 1;
        parameters.ua = 0;
        parameters.ub = 0;
        parameters.f0 = f0_1;
        parameters.f = f_1;

    default:
        break;
    }
    return parameters;
}
int main()
{
    Parameters parameters = select_dataset(1);
    solve_system(parameters);
    return 0;
}