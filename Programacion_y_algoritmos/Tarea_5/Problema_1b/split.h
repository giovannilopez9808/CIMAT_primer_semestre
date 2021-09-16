#define size_per_word 40
void obtain_tokens(FILE *text, char **tokens, char simbol)
{
    /* 
    Obtiene todos los tokens a partir de un archivo y los divide dado un simbolo.
     */
    int i = 0, j = 0;
    char letter;
    int letter_int, simbol_int;
    // Valor ascii del simbolo
    simbol_int = char_to_int(simbol);
    // Lectura del primer caracter
    letter = fgetc(text);
    while (letter != EOF)
    {
        // Valor ascii del caractr
        letter_int = char_to_int(letter);
        // Si es distinto a el simbolo se guarda en el mismo stack
        if (letter_int != simbol_int)
        {
            *(*tokens + i * size_per_word + j) = letter;
            j++;
        }
        // Si es igual entonces se corta el stack y se pasa al siguiente
        else
        {
            *(*tokens + i * size_per_word + j) = '\0';
            j = 0;
            i++;
        }
        letter = fgetc(text);
    }
    fclose(text);
}
void split(char *filename, char simbol, int *size, char **tokens)
{
    // Apertura inicial del archivo
    FILE *text = fopen(filename, "r");
    valid_file(text);
    // Conteo total de los simbolos dentro del archivo para inicializar el numero de stacks del token
    int elements = count_simbol(text, simbol);
    *size = elements;
    // Inicializacion de los tokens
    *tokens = (char *)malloc(size_per_word * elements);
    // Reapertura del archivo
    read_file(filename, text);
    // Obtiene los tokens
    obtain_tokens(text, tokens, simbol);
}