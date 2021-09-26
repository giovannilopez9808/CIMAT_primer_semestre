#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "read_file.h"
#include "sort.h"
int main(int argv, char *argc[])
{
    (void)argv;
    FILE *data = NULL;
    struct student *students;
    open_file(&data, argc[1]);
    int persons = obtain_size(data);
    students = (struct student *)calloc(persons, sizeof(struct student));
    obtain_information(students, data, persons);
    print_students(students, persons);
    sort(students, persons, 3);
    printf("\n\n");
    print_students(students, persons);
    free(students);
    fclose(data);
    return 0;
}