void select_menu(int option, struct student **students, int *size, FILE *data, char *filename, int per_group[6], int per_turn[2])
{
    /* 
    Selecciona cada opcion dependiendo de que numero ingreso el usuario
     */
    (void)data;
    switch (option)
    {
    case 1:
        // Caso para imprimir en un archivo los datos actuales
        // print_file(data, filename, *students, *size);
        print_students(*students, *size);
        printf("\nSe creo exitosamente el archivo %s\n", filename);
        break;
    case 2:
        // Caso para ordenar a los estudiantes por nombre alfabeticamente
        sort(*students, *size, 1);
        printf("\nSe ordeno exitosamente por nombre\n");
        break;
    case 3:
        // Caso para ordenar a los estudiantes por su edad de forma ascendiente
        sort(*students, *size, 2);
        printf("\nSe ordeno exitosamente por edad\n");
        break;
    case 4:
        // Caso para odenar a los estudiantes por sus calificaciones de forma descendenet
        sort(*students, *size, 3);
        printf("Se ordeno exitosamente por promedio\n");
        break;
    case 5:
        // Caso para realizar el conteo de los estudiantes por grupo
        count_per_group(*students, *size, per_group);
        // Impresion del conteo
        print_person_per_group(per_group);
        break;
    case 6:
        // Caso para realizar el conteo de los estudiantes por grupo
        count_per_turn(*students, *size, per_turn);
        // Impresion del conteo
        print_person_per_turn(per_turn);
        break;
    case 7:
        // Caso para dar de baja a un estudiante
        delete_student(*students, size);
        printf("\nSe elimino el alumno exitosamente\n");
        break;
    case 8:
        // Caso para dar de alta a un estudiante
        add_student(students, size);
        printf("\nSe agrego el alumno exitosamente\n");
        break;
    case 9:
        // Caso para invertir los datos de los estudiantes
        inverse_file(*students, *size);
        printf("\nSe inviertieron los alumnos exitosamente\n");
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("\nOpcion invalida\n");
        break;
    }
}
void menu(struct student *students, int size, FILE *data, char *filename, int per_group[6], int per_turn[2])
{
    /* 
    Impresion del menu y activador de cada opcion
     */
    int option;
    // Ciclo infinito para que el programa sea finalizado al seleccionar la opcion salir
    while (1)
    {
        printf("\n\nLista de opciones:\n");
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
        printf("\nSeleccione una opcion: ");
        // Lecura de la opcion
        scanf(" %d", &option);
        // Selecciona la opcion
        select_menu(option, &students, &size, data, filename, per_group, per_turn);
    }
}