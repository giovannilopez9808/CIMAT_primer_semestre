#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "read_files.h"
#include "print_results.h"
#include "LU_decomposition.h"
#include "solution.h"
int main(int argc, char *argv[])
{
    (void)argc;
    FILE *file_matrix, *file_results;
    double *matrix, *results, *solutions, *L, *U, *L_solutions;
    int dimension_matrix[2],
        dimension_result[2];
    file_matrix = fopen(argv[1], "r");
    file_results = fopen(argv[2], "r");
    valid_file(file_matrix);
    valid_file(file_results);
    // Lectura de los datos de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    // Lectura de los datos del vector resultado
    read_dimension(file_results,
                   dimension_result);
    read_matrix(file_results,
                dimension_result,
                &results);
    obtain_LU_crout(matrix,
                    dimension_matrix,
                    &L,
                    &U);
    // Resuelve el sistema de ecuaciones
    solve_triangular_inferior_matrix(L,
                                     dimension_matrix,
                                     results,
                                     &L_solutions);
    solve_triangular_superior_matrix(U,
                                     dimension_matrix,
                                     L_solutions,
                                     &solutions);
    print_solution(solutions,
                   dimension_matrix);
    free(L);
    free(U);
    free(L_solutions);
    free(solutions);
    return 0;
}