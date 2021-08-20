#include <stdio.h>
#include "functions.h"
void select_operation(int fraction1[], int fraction2[], char sign, int result[])
{
    switch (sign)
    {
    case '+':
        obtain_fraction_sum(fraction1,
                            fraction2,
                            result);
        break;
    case '-':
        obtain_fraction_subtraction(fraction1,
                                    fraction2,
                                    result);
        break;
    case '*':
        obtain_fraction_multiplication(fraction1,
                                       fraction2,
                                       result);
        break;
    case '/':
        obtain_fraction_division(fraction1,
                                 fraction2,
                                 result);
        break;
    default:
        print_lines();
        printf("Operación invalida\n");
        print_lines();
        result[0] = 0;
        result[1] = 0;
        break;
    }
}
void print_result(int fraction1[], int fraction2[], int result[], char sign)
{
    /* 
    Imprime en pantalla el resultado de la operacion
     */
    print_lines();
    printf("El resultado es\n%d/%d %c %d/%d = %d/%d\n",
           fraction1[0],
           fraction1[1],
           sign,
           fraction2[0],
           fraction2[1],
           result[0],
           result[1]);
    print_lines();
}
int main()
{
    // Inicializacion de las variables
    int fraction1[2];
    int fraction2[2];
    char sign;
    int result[2];
    // Lectura de la primer fraccion
    read_operation(fraction1,
                   fraction2,
                   &sign);
    select_operation(fraction1,
                     fraction2,
                     sign,
                     result);
    // Impresion delos resultados
    print_result(fraction1,
                 fraction2,
                 result,
                 sign);
    return 0;
}