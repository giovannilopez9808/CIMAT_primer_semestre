#ifndef heat_equation_H
#define heat_equation_H
#include <math.h>
#include "tools.h"
#define pi 3.14159265358979323846
typedef struct Parameters_t
{
    double x_min, x_max, x_num;
    double t_min, t_max, t_num;
    double k, ua, ub;
    double (*f)(double, double);
    double (*f0)(double);
} Parameters;
void solve_system(Parameters);
#endif
