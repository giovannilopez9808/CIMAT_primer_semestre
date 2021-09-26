void valid_file(FILE *data)
{
    /* 
    Validacion del archivo
     */
    if (data == NULL)
    {
        printf("File error\n");
        exit(1);
    }
}
void open_file(FILE **data, char *filename)
{
    *data = fopen(filename, "r");
    valid_file(*data);
}
int obtain_size(FILE *data)
{
    char letter;
    int size = 0;
    letter = fgetc(data);
    while (letter != EOF)
    {
        letter = fgetc(data);
        if (letter == '\n')
        {
            size++;
        }
    }
    rewind(data);
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
               students[i].s.group,
               students[i].s.turn);
    }
}
void obtain_information(struct student *students, FILE *data, int size)
{
    // Se salta el header
    fscanf(data, "%*[^\n]");
    for (int i = 0; i < size; i++)
    {
        students[i].name = malloc(sizeof(char *));
        students[i].grade = malloc(sizeof(char *));
        fscanf(data, "%s %d %c %c %[^\n]",
               students[i].grade,
               &students[i].age,
               &students[i].s.group,
               &students[i].s.turn,
               students[i].name);
    }
    rewind(data);
}