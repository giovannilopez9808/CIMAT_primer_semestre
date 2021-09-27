#include <stdio.h>
double power(double a, int n)
{
    /* 
    Funcion que eleva un numero a a la potencia n, donde n>=0
    */
    double result = 1.0;
    for (int i = 0; i < n; i++)
    {
        result = result * a;
    }
    return result;
}
long int obtain_number_of_digits(long int number)
{
    /* 
    Obtiene el numero de digitos del numero
     */
    long int len = 1;
    while (number / 10 > 1)
    {
        number = number / 10;
        len += 1;
    }
    return len;
}
void integer_to_list(long int size, long int number, int number_array[])
{
    /* 
    Convierte el numero entero en una lista de datos, cada elemento de la lista es un dígito del número
     */
    //  Primer digito del numero
    number_array[0] = number / power(10, size);
    for (int i = 1; i < size + 1; i++)
    {
        // Guarda el number[0:i]
        number_array[i] = number / power(10, size - i);
        for (int j = 0; j < i; j++)
        {
            // Elimina los numero de las decenas, centenas, etc para dejar unicamente la unidad
            number_array[i] -= number_array[j] * power(10, i - j);
        }
    }
}
long int join_numbers(int numbers_array[], long int size)
{
    /* 
    Une la lista de numeros en el orden inverso
     */
    int result = 0;
    for (int i = size; i >= 0; i--)
    {
        // Suma los digitos multiplicando su potencia por 10
        result += numbers_array[i] * power(10, i);
    }
    return result;
}
int main()
{

    long int number;
    printf("Ingresa el número que quieres escribir al reves: ");
    scanf("%ld", &number);
    long int size = obtain_number_of_digits(number);
    int number_array[size];
    integer_to_list(size,
                    number,
                    number_array);
    long int result = join_numbers(number_array,
                                   size);
    printf("El número al reves es:\t%ld\n",
           result);
    return 0;
}