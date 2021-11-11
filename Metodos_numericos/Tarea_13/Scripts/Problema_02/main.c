#include "Modules/newton.h"
#include "Modules/legendre_polynome.h"
#include "Modules/tools.h"
#include <stdio.h>
int main()
{
    int n = 5;
    double x;
    for (int i = 1; i < n; i++)
    {
        x = obtain_ai(i, n);
        x = newton_method(x, i);
        printf("%lf\n", x);
    }
    return 0;
}