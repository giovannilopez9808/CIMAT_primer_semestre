#include <stdlib.h>
#include <stdio.h>
#include "read_file.h"
#include "recognise_simbols.h"
#include "algorithms.h"
#include "quick_sort.h"
#include "results.h"
int main(int argc, char *argv[])
{
    // Dont print warming
    (void)argc;
    // Matriz de a a la z más el total de las columans y filas
    int data[number_letters][number_letters];
    int probabilities[number_letters];
    int positions_probabilities[number_letters];
    int total = 0;
    FILE *text_file;
    // Lectura del archivo
    text_file = fopen(argv[1], "r");
    initialize_data(data, probabilities, positions_probabilities);
    valid_file(text_file);
    obtain_data(text_file, data, probabilities);
    obtain_total_letters(&total, probabilities);
    write_sample_space(data);
    write_probabilities(probabilities, total);
    sorted(probabilities, positions_probabilities, 0, number_letters - 1);
    print_probabilities(probabilities, positions_probabilities, total);
    write_conditional_probabilities(probabilities, positions_probabilities, data);
    return 0;
}