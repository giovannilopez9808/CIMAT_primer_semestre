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
    file_matrix = fopen("M_TINF.txt", "r");
    file_results = fopen("V_TINF.txt", "r");
    valid_file(file_matrix);
    valid_file(file_results);
    // Lectura de los datos de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    // Lectura de lo datos de la matriz de resultados
    read_dimension(file_results,
                   dimension_result);
    read_matrix(file_results,
                dimension_result,
                &results);
    // Resuelve el sistema de ecuaciones
    solve_triangular_inferior_matrix(matrix,
                                     dimension_matrix,
                                     results,
                                     &solutions);
    print_solution(solutions,
                   dimension_matrix);
    return 0;
}