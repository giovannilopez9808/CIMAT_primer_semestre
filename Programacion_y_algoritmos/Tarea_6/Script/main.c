#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "read_file.h"
#include "sort.h"
#include "count.h"
#include "print_results.h"
int main(int argv, char *argc[])
{
    (void)argv;
    FILE *data = NULL;
    struct student *students;
    open_file(&data, argc[1]);
    int persons = obtain_size(data);
    int persons_per_group[6], persons_per_turn[2];
    (void)persons_per_group;
    students = (struct student *)calloc(persons, sizeof(struct student));
    obtain_information(students,
                       data,
                       persons);
    count_per_group(students, persons, persons_per_group);
    count_per_turn(students, persons, persons_per_turn);
    print_person_per_group(persons_per_group);
    print_person_per_turn(persons_per_turn);
    free(students);
    fclose(data);
    return 0;
}