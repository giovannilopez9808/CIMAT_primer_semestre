#include "Modules/functions.h"
#include "Modules/solvers.h"
#include <string.h>
#include <time.h>
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
    char path_output_vec_sup[50] = "Output/x_3134_sup.vec";
    char path_output_vec_inf[50] = "Output/x_3134_inf.vec";
    char path_output_vec_diag[50] = "Output/x_3134_diag.vec";
    strcat(path_matrix, argv[1]);
    strcat(path_vector, argv[2]);
    FILE *file_matrix, *file_vector, *file_output_vec_sup, *file_output_vec_inf, *file_output_vec_diag;
    clock_t begin, end;
    double *matrix, *vector, *solution, time_spent;
    int dimension_matrix[2], dimension_vector[2];
    file_matrix = open_file(path_matrix, "r");
    file_vector = open_file(path_vector, "r");
    file_output_vec_sup = open_file(path_output_vec_sup, "w");
    file_output_vec_inf = open_file(path_output_vec_inf, "w");
    file_output_vec_diag = open_file(path_output_vec_diag, "w");
    read_diagonal_dimension(file_matrix,
                            dimension_matrix);
    read_dimension(file_vector,
                   dimension_vector);
    read_diagonal_matrix(file_matrix,
                         dimension_matrix,
                         &matrix);
    read_matrix(file_vector,
                dimension_vector,
                &vector);
    // Triangular superior
    print_lines();
    printf("Método para matrices triangulares superiores\n");
    begin = clock();
    solve_triangular_superior_matrix(matrix,
                                     dimension_matrix,
                                     vector,
                                     &solution);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\tTiempo de ejecucion:\t%f\n", time_spent);
    write_results(file_output_vec_sup,
                  solution,
                  dimension_vector);
    free(solution);
    // Triangular inferior
    print_lines();
    printf("Método para matrices triangulares inferiores\n");
    begin = clock();
    solve_triangular_inferior_matrix(matrix,
                                     dimension_matrix,
                                     vector,
                                     &solution);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\tTiempo de ejecucion:\t%f\n", time_spent);
    write_results(file_output_vec_inf,
                  solution,
                  dimension_vector);
    free(solution);
    // Diagonal
    print_lines();
    printf("Método para matrices diagonales\n");
    begin = clock();
    solve_diagonal_matrix(matrix,
                          dimension_matrix,
                          vector,
                          &solution);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\tTiempo de ejecucion:\t%f\n", time_spent);
    write_results(file_output_vec_diag,
                  solution,
                  dimension_vector);
    free(solution);
    free(matrix);
    free(vector);
    fclose(file_matrix);
    fclose(file_output_vec_sup);
    fclose(file_output_vec_inf);
    fclose(file_output_vec_diag);
    fclose(file_vector);
    return 0;
}