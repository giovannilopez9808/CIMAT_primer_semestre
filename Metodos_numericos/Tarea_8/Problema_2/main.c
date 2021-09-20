#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "read_files.h"
#include "print_results.h"
#include "matrix_operations.h"
#include "dominant_diagonal.h"
#include "solution.h"
int main(int argc, char *argv[])
{
    (void)argc;
    FILE *file_matrix, *file_results;
    double *matrix, *results, *solutions = NULL;
    int *solutions_pos = NULL;
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
    convert_to_dominant_diagonal(matrix,
                                 dimension_matrix,
                                 results,
                                 &solutions_pos);
    solve_jabobi(matrix,
                 dimension_matrix,
                 results,
                 dimension_result,
                 &solutions);
    print_solution(solutions,
                   solutions_pos,
                   dimension_result);
    free(matrix);
    free(results);
    free(solutions);
    free(solutions_pos);
    return 0;
}