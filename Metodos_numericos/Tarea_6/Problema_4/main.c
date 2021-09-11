#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "read_files.h"
#include "print_results.h"
#include "solution.h"
int main()
{
    FILE *file_matrix, *file_results;
    double *matrix, *results, *solutions;
    int dimension_matrix[2],
        dimension_result[2];
    // file_matrix = fopen("test_matrix.txt", "r");
    // file_results = fopen("result.txt", "r");
    file_matrix = fopen("M_LARGE.txt", "r");
    file_results = fopen("V_LARGE.txt", "r");
    valid_file(file_matrix);
    valid_file(file_results);
    read_dimension(file_matrix,
                   dimension_matrix);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    read_dimension(file_results,
                   dimension_result);
    read_matrix(file_results,
                dimension_result,
                &results);
    print_initial_state(matrix,
                        dimension_matrix,
                        results);
    solve_gaussian_matrix(matrix,
                          dimension_matrix,
                          results,
                          &solutions);
    print_solution(solutions,
                   dimension_matrix);
    free(solutions);
    return 0;
}