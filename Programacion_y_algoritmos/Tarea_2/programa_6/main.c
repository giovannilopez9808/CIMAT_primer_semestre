#include <stdio.h>
char integer_to_ascii(int number)
{
    /* 
    Si un numero es mayor a 9, este tomara el valor en la tabla ascii, si no retornara el mismo numero pero de tipo caracter
     */
    if (number >= 0 && number <= 9)
    {
        // Se tiene que llevar a ascii, si no el resultado no se guardara
        return (char)(number + '0');
    }
    else
    {
        return (char)(number - 10 + 'A');
    }
}
void print_number(char result[], int size, int base)
{
    /* 
    Imprime el numero en la nueva base
     */
    printf("El numero en base %d es: ", base);
    for (int i = size; i >= 0; i--)
    {
        printf("%c", result[i]);
    }
    printf("\n");
}
void convert_number(int number, int base, char result[])
{
    /* 
    Convierte cualquier numero dado a la base especificada
     */
    int residue;
    int index = 0;
    while (number != 0)
    {
        // Obtiene el residuo del numero con la base
        residue = number % base;
        // Convierte el residuo a un caracter ascii
        result[index] = integer_to_ascii(residue);
        index++;
        // Obtiene la division del numero sin el residuo
        number = number / base;
    }
    print_number(result,
                 index,
                 base);
}

int main()
{
    int base;
    int number;
    char result[100];
    printf("Ingresa la base a la cual se desea convertir el numero: ");
    scanf("%d", &base);
    printf("Ingresa el numero que quieres convertir a la base %d: ", base);
    scanf("%d", &number);
    convert_number(number,
                   base,
                   result);
    return 0;
}