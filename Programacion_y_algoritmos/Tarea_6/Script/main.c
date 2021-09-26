#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "read_file.h"
#include "sort.h"
#include "count.h"
#include "update.h"
#include "inverse.h"
#include "print_results.h"
#include "menu.h"
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
    menu(students, persons, data, per_group, per_turn);
    free(students);
    fclose(data);
    return 0;
}