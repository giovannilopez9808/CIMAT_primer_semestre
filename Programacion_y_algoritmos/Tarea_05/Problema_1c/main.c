#include <stdio.h>
#include <stdlib.h>
#include "algorithm_string.h"
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