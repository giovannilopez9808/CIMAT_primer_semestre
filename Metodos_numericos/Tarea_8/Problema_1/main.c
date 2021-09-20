#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "solve_heat_equation.h"
#include "print_results.h"
#include "Cholesky_decomposition.h"
#include "solution.h"
int main()
{
    double *matrix, *L, *LT, *solutions_y, *solutions_x, *results;
    double k = 5, Q = 3, l = 1, q_0 = 10, q_n = 20;
    int n = 4;
    int size = n - 1;
    int dimension_matrix[2] = {size, size};
    int dimension_results[2] = {size, 1};
    // Creacion de los datos de la matriz
    create_matrix(&matrix, dimension_matrix);
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
    free(matrix);
    free(L);
    free(LT);
    return 0;
}