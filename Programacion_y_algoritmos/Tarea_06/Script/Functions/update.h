void delete_student(struct student *students, int *size)
{
    /* 
    Realiza la baja de un estudiante
     */
    // Inicializacion de la opcion
    char select = 'n';
    int index;
    // Se repetira si no es el estudiante que se quiere dar de baja
    while (select == 'n')
    {
        printf("Escribe el ID del estudiante que deseas eliminar\n");
        // Lectura del ID
        scanf(" %d", &index);
        // Transformacio al espacio de los elementos
        index -= 2;
        // Verificacion del ID
        if (index >= *size || index < 0)
        {
            printf("ID invalido\n");
        }
        else
        {
            // Si es un ID valido entonces se preguntara si es el estudiante a dar de baja
            printf("Se elimimara el estudiante\n");
            printf("%s\n", students[index].name);
            printf("Confirma la eliminación (Y/n): ");
            // Con un espacio para que no realice la lectura de \n
            scanf(" %c", &select);
            // Si lo es, entonces se remplazara la informacion del estudiante con el que se encuentra en la ultima posicion
            if (select != 'n')
            {
                // Si el estudiante a darse de baja es el ultimo estudiante no se realiza nada
                if (index != *size - 1)
                {
                    students[index] = students[*size - 1];
                }
                // Disminucion del total de estudiantes
                *size = *size - 1;
            }
        }
    }
}
void add_student(struct student **students, int *size)
{
    /* 
    Realiza la alta de un estudiante
     */
    // Aumento en la memoria para alojar al nuevo estudiante
    *students = (struct student *)realloc(*students, (*size + 1) * sizeof(struct student));
    // Inicializacion de sus variables
    (*students)[*size].name = malloc(sizeof(char *));
    (*students)[*size].grade = malloc(sizeof(char *));
    // Lectura de los datos del estudiante
    printf("Escribe el nombre del nuevo estudiante: ");
    scanf(" %[^\n]", (*students)[*size].name);
    printf("Escribe su calificacion: ");
    scanf(" %s", (*students)[*size].grade);
    printf("Escribe su edad: ");
    scanf(" %d", &(*students)[*size].age);
    printf("Escribe su grupo: ");
    scanf(" %c", &(*students)[*size].s->group);
    printf("Escribe su turno: ");
    scanf(" %c", &(*students)[*size].s->turn);
    // Aumento en el total de estudiantes
    *size = *size + 1;
}