#include <string.h>
#include "Modules/tools.h"
#include "Modules/qr.h"

int main(int argv, char *argc[])
{
    (void)argv;
    char path_data[50] = "Data/";
    strcat(path_data, argc[1]);
    FILE *data = open_file(path_data, "r");
    double *matrix, *q_matrix, *r_matrix;
    int dimension[2];
    read_dimension(data,
                   dimension);
    read_matrix(data,
                dimension,
                &matrix);
    q_matrix = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    r_matrix = (double *)malloc(dimension[0] * dimension[1] * sizeof(double));
    Gram_Schmidt_orthonormalization(matrix,
                                    q_matrix,
                                    r_matrix,
                                    dimension);
    print_matrix(q_matrix,
                 dimension);
    print_matrix(r_matrix,
                 dimension);
    return 0;
}