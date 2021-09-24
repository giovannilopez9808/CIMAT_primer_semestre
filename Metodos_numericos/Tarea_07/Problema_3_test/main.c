#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "read_files.h"
#include "print_results.h"
#include "Cholesky_decomposition.h"
#include "solution.h"
int main(int argc, char *argv[])
{
    (void)argc;
    FILE *file_matrix, *file_L, *file_LT;
    double *matrix, *L, *LT;
    int dimension_matrix[2];
    file_matrix = fopen(argv[1], "r");
    file_L = fopen(argv[2], "w");
    file_LT = fopen(argv[3], "w");
    valid_file(file_matrix);
    // Lectura de los datos de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
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
    free(L);
    free(LT);
    return 0;
}