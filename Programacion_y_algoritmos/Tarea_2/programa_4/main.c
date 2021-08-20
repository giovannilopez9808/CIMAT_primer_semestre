#include <stdio.h>
#include <math.h>
int obtain_len_of_number(int number)
{
    /* 
    Obtiene el numero de digitos del numero
     */
    int len = 1;
    while (number / 10 > 1)
    {
        number = number / 10;
        len += 1;
    }
    return len;
}
void fill_array(int size, int number, int number_array[])
{
    number_array[0] = number / pow(10, size);
    for (int i = 1; i < size + 1; i++)
    {
        number_array[i] = number / pow(10, size - i);
        for (int j = 0; j < i; j++)
        {
            number_array[i] -= number_array[j] * pow(10, i - j);
        }
    }
}
int join_numbers(int numbers_array[], int size)
{
    int result = 0;
    for (int i = size; i >= 0; i--)
    {
        result += numbers_array[i] * pow(10, i);
    }
    return result;
}
int main()
{
    int number = 123456789;
    int size = obtain_len_of_number(number);
    int number_array[size];
    fill_array(size,
               number,
               number_array);
    int result = join_numbers(number_array,
                              size);
    printf("El número al reves es:\t%d\n", result);
    return 0;
}