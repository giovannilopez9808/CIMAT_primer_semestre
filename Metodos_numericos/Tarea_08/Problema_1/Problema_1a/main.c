#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "solve_heat_equation.h"
#include "print_results.h"
#include "Cholesky_decomposition.h"
#include "solution.h"
void run_cases(int cases)
{
    double *matrix, *L, *LT, *solutions_y, *solutions_x, *results;
    double k = 5, Q = 3, l = 1, q_0 = 10, q_n = 20;
    int n;
    switch (cases)
    {
    case 1:
        n = 4;
        break;
    case 2:
        n = 100;
        break;
    default:
        break;
    }
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
    print_solution(solutions_x,
                   dimension_results);
    free(matrix);
    free(L);
    free(LT);
    free(solutions_x);
    free(solutions_y);
    free(results);
}
int main()
{
    for (int i = 1; i < 3; i++)
    {
        run_cases(i);
    }

    return 0;
}