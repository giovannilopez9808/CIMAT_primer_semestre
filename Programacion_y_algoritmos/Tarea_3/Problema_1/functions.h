#include <stdio.h>
void print_lines()
{
    printf("\n------------------------");
    printf("------------------------\n");
}
void is_palindrome(int number)
{
    /* 
    Funcion que verifica si un numero es palindromo
     */
    // Obtiene el numero escrito al reves
    int reverse = reverse_number(number);
    printf("El numero %d ", number);
    if (number != reverse)
    {
        printf("no ");
    }
    else
    {
        printf("si ");
    }
    printf("es palindromo\n");
}