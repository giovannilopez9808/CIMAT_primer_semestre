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
    fclose(data);
    data = fopen(filename, "w");
    fprintf(data, "Calificacion Edad Grupo Turno Nombre\n");
    for (int i = 0; i < size; i++)
    {
        fprintf(data, "%s %d %c %c %s",
                students[i].grade,
                students[i].age,
                students[i].s.group,
                students[i].s.turn,
                students[i].name);
        if (i != size - 1)
        {
            fprintf(data, "\n");
        }
    }
    fclose(data);
    open_file(&data, filename);
}