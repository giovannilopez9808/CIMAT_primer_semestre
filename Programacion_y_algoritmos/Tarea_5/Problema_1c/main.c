#include <stdio.h>
#include <stdlib.h>
int obtain_len_string(char *text)
{
    /* 
    Obtiene el tamaño de un string sin contar \0
     */
    int i = 0;
    while (text[i] != '\0')
    {
        i += 1;
    }
    return i;
}
void join_strings(char *text1, char *text2)
{
    /* 
    Une a dos strings y lo guarda en el primer argumento
     */
    // Obtiene el tamaño de los strings
    int len_text1 = obtain_len_string(text1);
    int len_text2 = obtain_len_string(text2);
    // Aumenta el tamaño del primer argumento
    text1 = (char *)realloc(text1, (len_text1 + len_text2) * sizeof(char));
    for (int i = 0; i < len_text2; i++)
    {
        // Guarda la informacion
        *(text1 + i + len_text1) = text2[i];
    }
    *(text1 + len_text1 + len_text2) = '\0';
}
void read_strings(char **string, char *text)
{
    /*
    Lectura del string de un argv y lo guarda en un puntero 
     */
    int len = obtain_len_string(text);
    // Tamaño del string
    *string = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        // Guardado de la información
        *(*string + i) = text[i];
    }
    *(*string + len) = '\0';
}
int main(int argc, char *argv[])
{
    (void)argc;
    char *text1 = NULL;
    char *text2 = NULL;
    read_strings(&text1, argv[1]);
    read_strings(&text2, argv[2]);
    printf("Texto 1:\t%s\nTexto 2:\t%s\n", text1, text2);
    join_strings(text1, text2);
    printf("Union:\t\t%s\n", text1);
    free(text1);
    free(text2);
    return 0;
}