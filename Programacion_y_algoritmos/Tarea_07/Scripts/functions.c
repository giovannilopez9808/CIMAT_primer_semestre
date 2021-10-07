#include "functions.h"
void print_yes() {
    printf("yes\n");
}
FILE* read_wav(char *filename)
{
    FILE *file=fopen(filename,"r");
    printf("%s",file);
}
