void valid_file(FILE *data)
{
    /* 
    Validacion del archivo
     */
    if (data == NULL)
    {
        perror("");
        exit(EXIT_FAILURE);
    }
}
void open_file(FILE **data, char *filename)
{
    /* 
    Apertura del archivo en modo lectura y validacion del mismo
     */
    *data = fopen(filename, "r");
    valid_file(*data);
}
int obtain_size(FILE *data)
{
    /* 
    Obtiene el número de filas que contiene un archivo
     */
    char letter;
    int size = 0;
    letter = fgetc(data);
    while (letter != EOF)
    {
        letter = fgetc(data);
        // Si se dio un enter entonces es una fila
        if (letter == '\n')
        {
            size++;
        }
    }
    // Retorno al inicio del archivo
    rewind(data);
    // Devolucion del numero de filas
    return size;
}
void read_header(FILE *data)
{
    char *header = NULL;
    fscanf(data, "%[^\n]", header);
}
void print_students(struct student *students, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s %s %d %c %c\n",
               students[i].name,
               students[i].grade,
               students[i].age,
               (students[i].s)->group,
               (students[i].s)->turn);
    }
    printf("\n");
}
void obtain_information(struct student *students, FILE *data, int size)
{
    /* 
    Lecuta de los datos de los estudiantes
     */
    // Se salta el header
    fscanf(data, "%*[^\n]");
    for (int i = 0; i < size; i++)
    {
        // Inicializacion de los strigns
        students[i].name = malloc(sizeof(char *));
        students[i].grade = malloc(sizeof(char *));
        students[i].s = (struct school *)malloc(sizeof(struct school));
        fscanf(data, "%s %d %c %c %[^\n]",
               students[i].grade,
               &students[i].age,
               &(*students[i].s).group,
               &(*students[i].s).turn,
               students[i].name);
    }
    // Devolucion al inicio del archivo
    rewind(data);
}