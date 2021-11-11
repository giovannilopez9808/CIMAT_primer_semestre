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
    double result, a = -1.0, b = 1.0;
    FILE *output = open_file("Output/f1.csv", "w");
    fprintf(output, "n,result\n");
    for (int i = 0; i < 5; i++)
    {
        result = simpson_method(f1, a, b, n_list[i]);
        write_results(output, n_list[i], result);
    }
    fclose(output);
    output = open_file("Output/f2.csv", "w");
    fprintf(output, "n,result\n");
    for (int i = 0; i < 5; i++)
    {
        result = simpson_method(f2, a, b, n_list[i]);
        write_results(output, n_list[i], result);
    }
    fclose(output);
    return 0;
}