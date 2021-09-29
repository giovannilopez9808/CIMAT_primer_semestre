void print_person_per_group(int persons[6])
{
    printf("Grupo\tPersonas\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%c\t%d\n", 'A' + i, persons[i]);
    }
}
void print_person_per_turn(int persons[2])
{
    printf("Turno\t\tPersonas\n");
    printf("Matutino\t%d\n", persons[0]);
    printf("Vespertino\t%d\n", persons[1]);
}
void print_file(FILE *data, char *filename, struct student *students, int size)
{
    /* 
    Realiza la impresion de los datos de los estudiantes
     */
    // Cierra el archivo
    fclose(data);
    // Abre en modo de escritura
    data = fopen(filename, "w");
    // Validacion
    valid_file(data);
    // Impresion del header
    fprintf(data, "Calificacion Edad Grupo Turno Nombre\n");
    // Impresion de la informacion de cada estudiante
    for (int i = 0; i < size; i++)
    {
        fprintf(data, "%s %d %c %c %s",
                students[i].grade,
                students[i].age,
                students[i].s->group,
                students[i].s->turn,
                students[i].name);
        // Si no es el ultimo estudiante entonces da enter
        if (i != size - 1)
        {
            fprintf(data, "\n");
        }
    }
    // Cierra el archivo para guardar los cambios
    fclose(data);
    // Apertura y validacion del archivo en modo lectura
    open_file(&data, filename);
}