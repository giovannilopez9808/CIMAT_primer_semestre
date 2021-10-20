#include "Modules/newton.h"
double f_x(double x)
{
    return exp(2 * x - 2) - 2 * x + 1;
}
int main()
{
    newton_method(f_x, 1e-6, 1e-6, -2);
    return 0;
}