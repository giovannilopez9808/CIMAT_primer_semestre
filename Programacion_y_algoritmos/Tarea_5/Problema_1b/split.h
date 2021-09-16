#define size_per_word 20
void obtain_tokens(FILE *text, char **tokens, char simbol)
{
    int i = 0, j = 0;
    char letter;
    int letter_int, simbol_int;
    simbol_int = char_to_int(simbol);
    letter = fgetc(text);
    while (letter != EOF)
    {
        letter_int = char_to_int(letter);
        if (letter_int != simbol_int)
        {
            *(*tokens + i * size_per_word + j) = letter;
            j++;
        }
        else
        {
            *(*tokens + i * size_per_word + j) = '\0';
            j = 0;
            i++;
        }
        letter = fgetc(text);
    }
}
void split(char *filename, char simbol, int *size, char **tokens)
{
    FILE *text = fopen(filename, "r");
    valid_file(text);
    int elements = count_simbol(text, simbol);
    *size = elements;
    *tokens = (char *)malloc(20 * elements);
    read_file(filename, text);
    obtain_tokens(text, tokens, simbol);
    fclose(text);
}