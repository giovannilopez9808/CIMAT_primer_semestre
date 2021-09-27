void delete_student(struct student *students, int *size)
{
    char select = 'n';
    int index;
    while (select == 'n')
    {
        printf("Escribe el ID del estudiante que deseas eliminar\n");
        scanf(" %d", &index);
        if (index >= *size && index < 0)
        {
            printf("ID invalido\n");
        }
        else
        {
            printf("Se elimimara el estudiante\n");
            printf("%s\n", students[index].name);
            printf("Confirma la eliminación (Y/n): ");
            // Con un espacio para que no realice la lectura de \n
            scanf(" %c", &select);
            if (select != 'n')
            {
                students[index] = students[*size - 1];
                *size = *size - 1;
            }
        }
    }
}
void add_student(struct student **students, int *size)
{
    *students = (struct student *)realloc(*students, (*size + 1) * sizeof(struct student));
    (*students)[*size].name = malloc(sizeof(char *));
    (*students)[*size].grade = malloc(sizeof(char *));
    printf("Escribe el nombre del nuevo estudiante: ");
    scanf(" %[^\n]", (*students)[*size].name);
    printf("Escribe su calificacion: ");
    scanf(" %s", (*students)[*size].grade);
    printf("Escribe su edad: ");
    scanf(" %d", &(*students)[*size].age);
    printf("Escribe su grupo: ");
    scanf(" %c", &(*students)[*size].s.group);
    printf("Escribe su turno: ");
    scanf(" %c", &(*students)[*size].s.turn);
    *size = *size + 1;
}