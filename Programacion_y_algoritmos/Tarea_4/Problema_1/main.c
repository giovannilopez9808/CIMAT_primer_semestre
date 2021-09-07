#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size 10
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
void initialize_matrix(char matrix[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = '.';
        }
    }
}
void print(char matrix[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
int is_in_the_box(int pos[])
{
    for (int i = 0; i < 2; i++)
    {
        if ((pos[i] < 0) || (pos[i] >= size))
        {
            return 0;
        }
    }
    return 1;
}
int generate_random_number()
{
    return rand() % 4;
}
void generate_move(int new_pos[], int pos[], int move[])
{
    for (int i = 0; i < 2; i++)
    {
        new_pos[i] = pos[i] + move[i];
    }
}
void select_move(int move[], int number)
{
    move[0] = 0;
    move[1] = 0;
    switch (number)
    {
    case 0:
        move[1] = 1;
        break;
    case 1:
        move[1] = -1;
        break;
    case 2:
        move[0] = -1;
        break;
    case 3:
        move[0] = 1;
        break;
    default:
        break;
    }
}
int is_avaliable(char matrix[size][size], int pos[])
{
    if (matrix[pos[0]][pos[1]] == '.')
    {
        return 1;
    }
    return 0;
}
// int is_any_avaliable(char matrix[size][size], int pos[])
// {
// }
void random_walk(int pos[], char matrix[size][size])
{
    int letter = 11;
    int random;
    // Si es 1 es porque aun hay un camino que escoger
    int in_box = 1;
    int move[2];
    int move_aux[2];
    matrix[pos[0]][pos[1]] = 'A';
    while (letter < 35 && in_box)
    {
        random = generate_random_number();
        select_move(move, random);
        generate_move(move_aux, pos, move);
        if (is_in_the_box(move_aux))
        {
            if (is_avaliable(matrix, move_aux))
            {
                pos[0] = move_aux[0];
                pos[1] = move_aux[1];
                matrix[pos[0]][pos[1]] = integer_to_ascii(letter);
                letter++;
            }
        }
        print(matrix);
        printf("\n\n");
        // letter++;
    }
}
int main()
{
    // 10 hasta 37
    int pos[2] = {0, 0};
    char matrix[size][size];
    srand(time(NULL));
    initialize_matrix(matrix);
    random_walk(pos, matrix);
    print(matrix);
    return 0;
}