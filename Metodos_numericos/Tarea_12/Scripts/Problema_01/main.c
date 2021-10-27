#include <string.h>
#include "Modules/tools.h"
#include "Modules/qr.h"

int main(int argv, char *argc[])
{
    (void)argv;
    char path_data[50] = "Data/";
    strcat(path_data, argc[1]);
    FILE *data = open_file(path_data, "r");
    double *matrix, *q_matrix = NULL, *r_matrix = NULL;
    int dimension[2];
    read_dimension(data,
                   dimension);
    read_matrix(data,
                dimension,
                &matrix);
    QR_decomposition(matrix,
                     &r_matrix,
                     &q_matrix,
                     dimension);
    print_matrix(r_matrix, dimension);
    print_matrix(q_matrix, dimension);
    free(q_matrix);
    free(r_matrix);
    free(matrix);
    fclose(data);
    return 0;
}