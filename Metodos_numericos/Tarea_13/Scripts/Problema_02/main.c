#include "Modules/legendre_polynome.h"
#include "Modules/newton.h"
#include "Modules/tools.h"
#include <string.h>
int main(int argv, char *argc[])
{
    (void)argv;
    int n = atoi(argc[1]);
    double x, x_i;
    char file[50] = "Output/";
    strcat(file, argc[1]);
    strcat(file, ".csv");
    FILE *output = open_file(file, "w");
    fprintf(output, "n,x0,Raiz\n");
    printf("Raices del polinomio de legendre de grado %d\n", n);
    for (int i = 0; i < n; i++)
    {
        x_i = obtain_ai(i, n);
        x = newton_method(x_i, n);
        printf("Raiz n=%d\tx0=%lf\tx=%lf\n", i, x_i, x);
        write_results(output, i, x_i, x);
    }
    fclose(output);
    return 0;
}