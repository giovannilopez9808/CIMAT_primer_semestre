void valid_file(FILE *text_file)
{
    /* 
    Validacion del archivo
     */
    if (text_file == NULL)
    {
        printf("File error\n");
        exit(1);
    }
}
void read_file(char *filename, FILE *text)
{
    /* 
    Lectura y validacion del archivo
     */
    text = fopen(filename, "r");
    valid_file(text);
}
int count_simbol(FILE *text, char simbol)
{
    /* 
    Realiza el conteo del caracter dado en un texto
     */
    char letter;
    int letter_int, simbol_int, i = 0;
    simbol_int = char_to_int(simbol);
    letter = fgetc(text);
    while (letter != EOF)
    {
        letter_int = char_to_int(letter);
        // Si el caracter leido en el texto es igual al simbolo buscado
        if (letter_int == simbol_int)
        {
            // Se aumentara en uno el contador
            i++;
        }
        letter = fgetc(text);
    }
    fclose(text);
    return i + 1;
}