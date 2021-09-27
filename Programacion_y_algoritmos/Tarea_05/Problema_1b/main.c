#include <stdio.h>
#include <stdlib.h>
#include "recognise_simbols.h"
#include "read_file.h"
#include "split.h"
#include "print_results.h"
void print_test(char simbol, char *filename)
{
    print_lines();
    printf("Separando el archivo %s por medio del ASCII-%d\n\n",
           filename,
           simbol);
}
void test(int option)
{
    /* 
    Test escritos para diferentes archivos y simbolos
     */
    char simbol;
    char *filename;
    int size = 0;
    char *tokens = NULL;
    switch (option)
    {
    case 0:
        simbol = ',';
        filename = "test1.csv";
        print_test(simbol, filename);
        break;
    case 1:
        simbol = '/';
        filename = "test2.txt";
        print_test(simbol, filename);
        break;
    case 2:
        simbol = ' ';
        filename = "test3.txt";
        print_test(simbol, filename);
        break;
    case 3:
        simbol = '/';
        filename = "test3.txt";
        print_test(simbol, filename);
        break;
    default:
        break;
    }
    // Obtiene los tokes
    split(filename,
          simbol,
          &size,
          &tokens);
    // Impresion  de los tokens
    if (size != 1)
    {
        print_tokens(tokens, size);
        free(tokens);
    }
}
int main()
{
    for (int i = 0; i < 4; i++)
    {
        test(i);
    }
    return 0;
}