#include "Modules/heat_equation.h"
int main()
{
    Parameters parameters;
    parameters.x_min = 0.0;
    parameters.x_max = 0.3;
    parameters.x_num = 50;
    parameters.t_min = 0.0;
    parameters.t_max = 100000.0;
    parameters.t_num = 101;
    parameters.k = 3.0E-7;
    parameters.u0 = 2000;
    parameters.ua = 200;
    parameters.ub = 0;
    solve_system(parameters);
    return 0;
}