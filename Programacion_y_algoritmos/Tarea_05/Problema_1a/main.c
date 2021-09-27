#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"
#include "recognise_simbols.h"
#include "find_a_word_in_a_text.h"
int main(int argc, char *argv[])
{
    (void)argc;
    FILE *text_file;
    text_file = fopen(argv[1], "r");
    valid_file(text_file);
    int word_count = find_word(text_file, argv[2]);
    printf("La palabra %s se encontro %d veces\n",
           argv[2],
           word_count);
    return 0;
}