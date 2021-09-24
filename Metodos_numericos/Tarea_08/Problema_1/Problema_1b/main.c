#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "solve_heat_equation.h"
#include "print_results.h"
#include "Cholesky_decomposition.h"
#include "solution.h"
void run_cases(FILE *file_results_1, FILE *file_results_2, int n)
{
    double *matrix, *L, *LT, *solutions_y, *solutions_x, *results;
    double k = 5, Q = 3, l = 1, q_0 = 10, q_n = 20;
    int size = n - 1;
    int dimension_matrix[2] = {size,
                               size};
    // Creacion de los datos de la matriz
    create_matrix(&matrix,
                  dimension_matrix);
    initialize_results(&results,
                       dimension_matrix,
                       k, Q, l, n, q_0, q_n);
    obtain_Cholesky(matrix,
                    dimension_matrix,
                    &L,
                    &LT);
    solve_triangular_inferior_matrix(L,
                                     dimension_matrix,
                                     results,
                                     &solutions_y);
    solve_triangular_superior_matrix(LT,
                                     dimension_matrix,
                                     solutions_y,
                                     &solutions_x);
    write_each_central_solution(file_results_1,
                                solutions_x,
                                n);
    write_each_central_solution(file_results_2,
                                solutions_x,
                                n - 2);
    free(matrix);
    free(L);
    free(LT);
    free(solutions_x);
    free(solutions_y);
    free(results);
}
int main()
{
    FILE *file_results_1 = fopen("results_1.csv", "w");
    FILE *file_results_2 = fopen("results_2.csv", "w");
    fprintf(file_results_1,
            "N,Value\n");
    fprintf(file_results_2,
            "N,Value\n");
    for (int i = 10; i < 220; i += 10)
    {
        run_cases(file_results_1,
                  file_results_2,
                  i);
    }
    return 0;
    fclose(file_results_1);
    fclose(file_results_2);
}
