#include "Modules/heat_equation.h"
int main()
{
    Parameters parameters;
    parameters.x_min = 0.0;
    parameters.x_max = 0.3;
    parameters.x_num = 100;
    parameters.t_min = 0.0;
    parameters.t_max = 100.0;
    parameters.t_num = 100;
    parameters.k = 5.0E-7;
    parameters.u0 = 0;
    parameters.ua = 0;
    parameters.ub = 0;
    solve_system(parameters);
    return 0;
}
