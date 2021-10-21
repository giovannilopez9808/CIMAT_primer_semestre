#include "Modules/matrix_system.h"
#include "Modules/functions.h"
#include "Modules/solvers.h"
int main()
{
    n = 2000;
    n_lmabda = 10;
    double *matrix = create_matrix_system(n);
    double *lambda, *vectors;
    int dimension[2] = {n, n};
    int dimension_lambda[2] = {n, 1};
    obtain_eigenvalues_jacobi(matrix,
                              dimension,
                              &lambda,
                              &vectors);
    print_matrix(lambda, dimension_lambda);
    return 0;
}