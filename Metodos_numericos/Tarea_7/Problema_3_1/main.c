#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "print_results.h"
#include "Cholesky_decomposition.h"
#include "solution.h"
int main(int argc, char *argv[])
{
    (void)argc;
    FILE *file_L, *file_LT;
    double *matrix, *L, *LT;
    (void)file_L;
    (void)file_LT;
    (void)L;
    (void)LT;
    int size = atoi(argv[1]);
    int dimension_matrix[2] = {size, size};
    file_L = fopen(argv[2], "w");
    file_LT = fopen(argv[3], "w");
    // Creacion de los datos de la matriz
    create_matrix(&matrix, dimension_matrix);
    obtain_Cholesky(matrix,
                    dimension_matrix,
                    &L,
                    &LT);
    write_matrix_on_file(file_L,
                         L,
                         dimension_matrix);
    write_matrix_on_file(file_LT,
                         LT,
                         dimension_matrix);
    free(matrix);
    free(L);
    free(LT);
    return 0;
}