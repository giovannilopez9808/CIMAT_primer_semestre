#include <stdio.h>
void print_lines()
{
    printf("\n------------------------");
    printf("------------------------\n");
}
int reverse_number(int number)
{
    /* 
    Regresa el numero escrito al reves
     */
    // Inicializacion del numerp
    int reverse = 0;
    // Variable auxiliar
    int aux;
    while (number != 0)
    {
        // Obtiene el primer digito del numero
        aux = number % 10;
        // Suma el primer digito del numero y los anteriores les multiplica por 10
        reverse = reverse * 10 + aux;
        // Eliminacion del primer digito
        number /= 10;
    }
    return reverse;
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