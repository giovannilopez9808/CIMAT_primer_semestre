#include <stdio.h>
#include <stdlib.h>
#include "Functions/structures.h"
#include "Functions/read_file.h"
#include "Functions/sort.h"
#include "Functions/count.h"
#include "Functions/update.h"
#include "Functions/inverse.h"
#include "Functions/print_results.h"
#include "Functions/menu.h"
int main(int argv, char *argc[])
{
    (void)argv;
    FILE *data = NULL;
    struct student *students;
    open_file(&data, argc[1]);
    int persons = obtain_size(data);
    int per_group[6], per_turn[2];
    students = (struct student *)calloc(persons, sizeof(struct student));
    obtain_information(students, data, persons);
    menu(students, persons, data, argc[1], per_group, per_turn);
    free(students);
    fclose(data);
    return 0;
}