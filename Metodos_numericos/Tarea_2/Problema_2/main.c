#include <stdio.h>
#include <math.h>
float float_function(double x)
{
    return 1 / (sqrtf(powf(x, 2) + 1) - x);
}
double double_function(double x)
{
    return 1 / (sqrt(pow(x, 2) + 1) - x);
}
long double long_double_function(double x)
{
    return 1 / (sqrtl(powl(x, 2) + 1) - x);
}
void init_program(double x)
{
    printf("------------------------------\n");
    printf("Para x\t= %lf\n", x);
    float ffx = float_function(x);
    printf("ffx(x)\t= %f\n", ffx);
    double dfx = double_function(x);
    printf("dfx(x)\t= %lf\n", dfx);
    long double dlfx = long_double_function(x);
    printf("dlfx(x)\t= %Lf\n", dlfx);
}
int main()
{
    int n = 11;
    double x;
    for (int i = 0; i < n; i++)
    {
        x = pow(10, i );
        init_program(x);
    }
    return 0;
}
