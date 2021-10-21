#include "Modules/newton.h"
double f_x(double x)
{
    return exp(2 * x - 2) - 2 * x + 1;
}
int main()
{
    newton_method(f_x,
                  1e-7,
                  1e-7,
                  -10);
    return 0;
}
