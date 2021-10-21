#include "Modules/functions.h"
#include "Modules/solvers.h"
#include <string.h>
int main(int argc, char *argv[])
{
    (void)argc;
    if (argc != 3)
    {
        printf("Error al ejecutar\n./main.out 'archivo de la matrix' 'archivo del vector'\n");
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
    // Lectura de la dimension de la matriz
    read_dimension(file_matrix,
                   dimension_matrix);
    // Lectura de la dimension del vector
    read_dimension(file_vector,
                   dimension_vector);
    // Lectura de la matriz
    read_matrix(file_matrix,
                dimension_matrix,
                &matrix);
    // Lectura del vector
    read_matrix(file_vector,
                dimension_vector,
                &vector);
    // Factorizacion de la forma de LU de la matriz
    obtain_LU_crout(matrix,
                    dimension_matrix,
                    &L,
                    &U);
    // Solucion del sistema por medio de LU
    solve_with_LU(L,
                  U,
                  dimension_matrix,
                  vector,
                  &solution);
    // Calculo de la matriz inversa
    obtain_matrix_inverse(L,
                          U,
                          dimension_matrix,
                          &matrix_inverse);
    // Escritura de los resultados de la matriz inversa
    write_matrix_results(file_output_matrix,
                         matrix_inverse,
                         dimension_matrix);
    printf("Resultados escritos existosamente en el archivo: %s\n",
           path_output_matrix);
    // Escritura de los resultados de la solucion del sistema
    write_results(file_output_vec,
                  solution,
                  dimension_vector);
    printf("Resultados escritos existosamente en el archivo: %s\n",
           path_output_vec);
    free(matrix);
    free(vector);
    free(solution);
    free(matrix_inverse);
    free(L);
    free(U);
    fclose(file_matrix);
    fclose(file_output_matrix);
    fclose(file_output_vec);
    fclose(file_vector);
    return 0;
}
