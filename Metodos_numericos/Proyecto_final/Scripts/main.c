#include "Modules/heat_equation.h"
int main()
{
    Parameters parameters;
    parameters.x_min = 0.0;
    parameters.x_max = 100;
    parameters.x_num = 100;
    parameters.t_min = 0.0;
    parameters.t_max = 10.0;
    parameters.t_num = 200;
    parameters.k = 334;
    parameters.u0 = -23;
    parameters.ua = 13;
    parameters.ub = 100;
    solve_system(parameters);
    return 0;
}