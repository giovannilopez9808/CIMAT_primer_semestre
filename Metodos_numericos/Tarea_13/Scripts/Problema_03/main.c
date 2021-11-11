#include "Modules/legendre_polynome.h"
#include "Modules/newton.h"
#include "Modules/tools.h"
#include <string.h>
int main(int argv, char *argc[])
{
    (void)argv;
    int n = atoi(argc[1]);
    char file[50] = "Output/";
    strcat(file, argc[1]);
    strcat(file, ".txt");
    FILE *output = open_file(file, "w");
    printf("Raices del polinomio de legendre de grado %d\n", n);
    double *weights = obtain_weight(n);
    free(weights);
    fclose(output);
    return 0;
}