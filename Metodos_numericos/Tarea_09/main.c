#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "read_files.h"
#include "matrix_operations.h"
#include "print_results.h"
#include "eigenvalue.h"
int main(int argc, char *argv[])
{
    (void)argc;
    FILE *file_matrix;
    double *matrix, *vector = NULL;
    double lambda = 0;
    int dimension_matrix[2],
        dimension_vector[2] = {1, 1};
    file_matrix = fopen(argv[1], "r");
    valid_file(file_matrix);
    // Lectura de los datos de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    dimension_vector[0] = dimension_matrix[0];
    obtain_max_eigenvalue(matrix,
                          dimension_matrix,
                          &lambda,
                          &vector);
    print_lines();
    printf("\nlambda = %lf\n\n", lambda);
    print_lines();
    printf("\nVector asociado\n\n");
    print_matrix(vector,
                 dimension_vector);
    free(matrix);
    return 0;
}