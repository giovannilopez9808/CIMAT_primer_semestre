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
    fscanf(file, "%d", &size);
    struct person *pointers[size], names[size];
    read_names(file, size, names, pointers);
    print_names(pointers, size);
    sorted(pointers, 0, size - 1);
    printf("\n\n");
    print_names(pointers, size);
    return 0;
}