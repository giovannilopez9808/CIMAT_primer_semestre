#include <stdio.h>
void read_string(char string[], int *size)
{
    scanf("%[^\n]s", string);
    for (int i = 0; i < 256; i++)
    {
        if (string[i] == '\0')
        {
            break;
        }
        *size = *size + 1;
    }
}
char inverse_string(char string[], char inverse[], int size)
{
    for (int i = size; i > 0; i--)
    {
        inverse[i - 1] = string[size - i];
    }
    inverse[size + 1] = '\0';
    return *inverse;
}
void is_palindrome(char string[], char inverse[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (string[i] != inverse[i])
        {
            printf("La palabra %s no es palindromo\n", string);
            return;
        }
    }
    printf("La palabra %s si es palindromo\n", string);
}
int main()
{
    char inverse[256];
    char string[256];
    int size = 0;
    read_string(string, &size);
    inverse_string(string, inverse, size);
    is_palindrome(string, inverse, size);
    return 0;
}