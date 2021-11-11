#include "Modules/gauss_quadrature.h"
#include "Modules/legendre_polynome.h"
#include "Modules/tools.h"
#include <math.h>
double f1(double x)
{
    return x * cos(x);
}
double f2(double x)
{
    return x * exp(-x);
}
int main()
{
    int n_list[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    char file_1[50] = "Output/f1.csv";
    char file_2[50] = "Output/f2.csv";
    double integral_1, integral_2;
    FILE *output_1 = open_file(file_1, "w");
    FILE *output_2 = open_file(file_2, "w");
    fprintf(output_1, "n,result\n");
    fprintf(output_2, "n,result\n");
    for (int i = 0; i < 9; i++)
    {
        integral_1 = integrate_with_gauss(f1, pi, 0, n_list[i]);
        integral_2 = integrate_with_gauss(f2, 0, -1, n_list[i]);
        write_results(output_1, n_list[i], integral_1);
        write_results(output_2, n_list[i], integral_2);
    }
    fclose(output_1);
    fclose(output_2);
    return 0;
}