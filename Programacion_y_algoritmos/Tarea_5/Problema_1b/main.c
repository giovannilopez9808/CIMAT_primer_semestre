#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"
#include "recognise_simbols.h"
#define size_per_word 20
void read_file(char *filename, FILE *text)
{
    text = fopen(filename, "r");
    valid_file(text);
}
int count_simbol(FILE *text, char simbol)
{
    char letter;
    int letter_int, simbol_int, i = 0;
    simbol_int = char_to_int(simbol);
    letter = fgetc(text);
    while (letter != EOF)
    {
        letter_int = char_to_int(letter);
        if (letter_int == simbol_int)
        {
            i++;
        }
        letter = fgetc(text);
    }
    fclose(text);
    return i + 1;
}

void split(char *filename, char simbol, int *size, char **tokens)
{
    FILE *text;
    text = fopen(filename, "r");
    read_file(filename, text);
    int elements = count_simbol(text, simbol);
    *size = elements;
    *tokens = (char *)malloc(20 * elements);
    read_file(filename, text);
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
void print_tokens(char **tokens, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", *tokens + i * size_per_word);
    }
}
int main(int argc, char *argv[])
{
    (void)argc;
    char *tokens = NULL;
    char simbol = '/';
    int size;
    split(argv[1], simbol, &size, &tokens);
    print_tokens(&tokens, size);
    return 0;
}