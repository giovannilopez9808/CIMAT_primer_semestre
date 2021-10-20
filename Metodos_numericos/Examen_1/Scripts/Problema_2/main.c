#include "Modules/functions.h"
#include "Modules/solvers.h"
#include <string.h>
int main(int argc, char *argv[])
{
    (void)argc;
    if (argc != 3)
    {
        printf("Archivos faltantes");
        exit(0);
    }
    char path_matrix[50] = "../Data/";
    char path_vector[50] = "../Data/";
    char path_output_vec[50] = "Output/x_1000.vec";
    char path_output_matrix[50] = "Output/A_1000.mtx_inv";
    strcat(path_matrix, argv[1]);
    strcat(path_vector, argv[2]);
    FILE *file_matrix, *file_vector, *file_output_vec, *file_output_matrix;
    double *matrix, *vector, *matrix_inverse, *solution, *L, *U;
    int dimension_matrix[2], dimension_vector[2];
    file_matrix = open_file(path_matrix, "r");
    file_vector = open_file(path_vector, "r");
    file_output_vec = open_file(path_output_vec, "w");
    file_output_matrix = open_file(path_output_matrix, "w");
    read_dimension(file_matrix,
                   dimension_matrix);
    read_dimension(file_vector,
                   dimension_vector);
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    read_matrix(file_vector,
                dimension_vector,
                &vector);
    obtain_LU_crout(matrix,
                    dimension_matrix,
                    &L,
                    &U);
    solve_with_LU(L,
                  U,
                  dimension_matrix,
                  vector,
                  &solution);
    obtain_matrix_inverse(L,
                          U,
                          dimension_matrix,
                          &matrix_inverse);
    write_results(file_output_matrix,
                  matrix_inverse,
                  dimension_matrix);
    write_results(file_output_vec,
                  solution,
                  dimension_vector);
    free(matrix);
    free(vector);
    free(solution);
    free(matrix_inverse);
    free(L);
    free(U);
    fclose(file_matrix);
    // fclose(file_output);
    fclose(file_vector);
    return 0;
}