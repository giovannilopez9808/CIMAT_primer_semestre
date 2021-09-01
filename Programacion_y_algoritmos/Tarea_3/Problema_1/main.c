#include "reverse.h"
#include "functions.h"
int main()
{
    int number;
    print_lines();
    printf("Escribe el numero que quieres saber si es palindromo:\n");
    scanf("%d", &number);
    print_lines();
    is_palindrome(number);
    return 0;
}