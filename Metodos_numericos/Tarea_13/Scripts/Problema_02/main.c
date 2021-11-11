#include "Modules/legendre_polynome.h"
#include "Modules/newton.h"
#include "Modules/tools.h"
#include <string.h>
int main(int argv, char *argc[])
{
    (void)argv;
    int n = atoi(argc[1]);
    double x;
    char file[50] = "Output/";
    strcat(file, argc[1]);
    strcat(file, ".txt");
    FILE *output = open_file(file, "w");
    printf("Raices del polinomio de legendre de grado %d\n", n);
    for (int i = 0; i < n; i++)
    {
        x = obtain_ai(i, n);
        x = newton_method(x, n);
        printf("Raiz n=%d\tx=%lf\n", i, x);
        write_results(output, i, x);
    }
    fclose(output);
    return 0;
}