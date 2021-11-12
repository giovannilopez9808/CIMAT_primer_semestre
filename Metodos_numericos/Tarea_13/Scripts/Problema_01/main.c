#include "Modules/simpson_algorithm.h"
#include "Modules/tools.h"
#include <math.h>
double f1(double x)
{
    return exp(x);
}
double f2(double x)
{
    return 1 / (x * x + 1);
}
int main()
{
    int n_list[5] = {3, 6, 9, 12, 15};
    double result_1, result_2, a = -1.0, b = 1.0;
    FILE *output_1 = open_file("Output/f1.csv", "w");
    FILE *output_2 = open_file("Output/f2.csv", "w");
    fprintf(output_1, "n,result\n");
    fprintf(output_2, "n,result\n");
    for (int i = 0; i < 5; i++)
    {
        result_1 = simpson_method(f1, a, b, n_list[i]);
        result_2 = simpson_method(f2, a, b, n_list[i]);
        write_results(output_1, n_list[i], result_1);
        write_results(output_2, n_list[i], result_2);
    }
    fclose(output_1);
    fclose(output_2);
    return 0;
}