void select_menu(int option, struct student **students, int *size, FILE *data, int per_group[6], int per_turn[2])
{
    (void)data;
    switch (option)
    {
    case 1:
        print_students(*students, *size);
        break;
    case 2:
        sort(*students, *size, 1);
        break;
    case 3:
        sort(*students, *size, 2);
        break;
    case 4:
        sort(*students, *size, 3);
        break;
    case 5:
        count_per_group(*students, *size, per_group);
        print_person_per_group(per_group);
        break;
    case 6:
        count_per_turn(*students, *size, per_turn);
        print_person_per_turn(per_turn);
        break;
    case 7:
        delete_student(*students, size, 0);
        break;
    case 8:
        add_student(students, size);
        break;
    case 9:
        inverse_file(*students, *size);
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("\nOpcion invalida\n");
        break;
    }
}
void menu(struct student *students, int size, FILE *data, int per_group[6], int per_turn[2])
{
    int option;
    while (1)
    {
        printf("\n\nSeleccione una opcion:\n");
        printf("Lista de optiones:\n");
        printf("1) Imprimir un archivo\n");
        printf("2) Ordenar por nombbre\n");
        printf("3) Ordenar por edad\n");
        printf("4) Ordenar por promedio\n");
        printf("5) Numero de estudiantes por grupo\n");
        printf("6) Numero de estudiantes por turno\n");
        printf("7) Baja de un estudiante\n");
        printf("8) Alta de un estudiante\n");
        printf("9) Invertir estudiante\n");
        printf("0) Salir\n");
        scanf(" %d", &option);
        select_menu(option, &students, &size, data, per_group, per_turn);
    }
}