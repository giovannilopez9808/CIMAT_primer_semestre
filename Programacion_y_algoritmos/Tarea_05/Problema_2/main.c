#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "print_results.h"
#include "inicitalize_data.h"
#include "quick_sort.h"
#include "algoritms.h"
int main(int argc, char *argv[])
{
    srand(time(NULL));
    (void)argc;
    double *data, *moving_average, *median;
    int size[2] = {atoi(argv[1]),
                   atoi(argv[2])};
    // Inicializacion de los datos
    initialize_data(&data,
                    &moving_average,
                    &median,
                    size);
    print_data(data, size, "Datos iniciales");
    obtain_moving_average_and_median(data,
                                     moving_average,
                                     median,
                                     size);
    // Impresion de los datos
    print_data(moving_average,
               size,
               "Moving average");
    print_data(median,
               size,
               "Median");
    return 0;
}