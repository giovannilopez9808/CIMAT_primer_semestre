#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "read_file.h"
#include "quick_sort_name.h"
int main(int argc, char *argv[])
{
    // Dont print warming
    (void)argc;
    int size;
    FILE *file = fopen(argv[1], "r");
    valid_file(file);
    size = obtain_number_persons(file);
    file = fopen(argv[1], "r");
    struct person *pointers[size], names[size];
    read_names(file, size, names, pointers);
    print_lines();
    printf("Nombres desordenados\n\n");
    print_names(pointers, size);
    sorted(pointers, 0, size - 1);
    printf("\n\n");
    print_lines();
    printf("Nombres ordenados\n\n");
    print_names(pointers, size);
    return 0;
}