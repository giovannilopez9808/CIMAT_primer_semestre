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
    // Inicializacion del archivo de datos
    FILE *data = NULL;
    // Inicializacion del puntero de los estudiantes
    struct student *students;
    // Apertura para la lectura de datos
    open_file(&data, argc[1]);
    // Numero inicial de estudiantes
    int persons = obtain_size(data);
    // Inicializacion de los contadores por grupo y turno
    int per_group[6], per_turn[2];
    // Inicializacion de la memoria para cada estudiante
    students = (struct student *)calloc(persons, sizeof(struct student));
    // Lectura de la información inicial de los estudiantes
    obtain_information(students, data, persons);
    // Impresion del menu
    menu(students, persons, data, argc[1], per_group, per_turn);
    // Liberacion de la memoria dinamica
    free(students);
    fclose(data);
    return 0;
}