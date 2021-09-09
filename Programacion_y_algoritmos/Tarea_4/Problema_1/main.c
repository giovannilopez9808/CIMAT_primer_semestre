#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size 10
#define max_letters 26
char inetegr_to_letter(int number)
{
    return (char)(number + 'A');
}
void initialize_matrix(char matrix[size][size])
{
    /* 
    Inicializa la matriz con puntos
     */
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
    /* 
    Escribe en pantalla el estado de la matriz
     */
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
    /* 
    Recibe la nueva posicion de la letra a imprimir, si esta dentro del área devuelve 1, si no devuelve 0
     */
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
    /* 
    Genera aleatoriamente numeros entre 0,1,2,3
     */
    return rand() % 4;
}
void generate_move(int new_pos[], int pos[], int move[])
{
    /* 
    Realiza el movimiento de la posicion hacia una nueva dependiendo del movimiento antes escogido.
     */

    for (int i = 0; i < 2; i++)
    {
        new_pos[i] = pos[i] + move[i];
    }
}
void select_move(int move[], int number)
{
    /* 
    Selecciona el movimiento dependiendo del valor del numero aleatorio
     */
    move[0] = 0;
    move[1] = 0;
    switch (number)
    {
    case 0:
        // Movimiento hacia arriba
        move[1] = 1;
        break;
    case 1:
        // Movimiento hacia abajo
        move[1] = -1;
        break;
    case 2:
        // Movimiento hasta la izquierda
        move[0] = -1;
        break;
    case 3:
        // Movimiento hasta la derecha
        move[0] = 1;
        break;
    default:
        break;
    }
}
int is_avaliable(char matrix[size][size], int pos[])
{
    /* 
    Verifica si la celda seleccionada esta disponible, si lo esta regresa 1, si no 0
     */
    if (matrix[pos[0]][pos[1]] == '.')
    {
        return 1;
    }
    return 0;
}
int is_any_avaliable(char matrix[size][size], int pos[])
{
    /* 
    Verifica si alguna de las celdas vecinas esta disponible, si alguna no esta regresa 1, si todas estan ocupadas regresa 0
     */
    int move[2] = {0, 0};
    // Posicion auxiliar generada para no modificar la posicion actual
    int pos_aux[2];
    // Contador de celdas disponibles
    int avaliable = 0;
    for (int i = 0; i < 4; i++)
    {
        select_move(move, i);
        generate_move(pos_aux, pos, move);
        if (is_in_the_box(pos_aux))
        {
            if (is_avaliable(matrix, pos_aux))
            {
                avaliable += 1;
            }
        }
    }
    // Si todas estan ocupadas
    if (avaliable == 0)
    {
        return 0;
    }
    // Si hay alguna disponible
    return 1;
}
void random_walk(int pos[], char matrix[size][size])
{
    // Inicio de las letras
    int letter = 1;
    int random;
    // Guardara el movimiento que se realizara en cada paso
    int move[2];
    // Posicion auxiliar generada para no modificar la posicion actual
    int pos_aux[2];
    matrix[pos[0]][pos[1]] = 'A';
    while (letter < max_letters)
    {
        // Si todas estan ocupadas se detiene la caminata
        if (!is_any_avaliable(matrix, pos))
        {
            break;
        }
        random = generate_random_number();
        select_move(move, random);
        generate_move(pos_aux, pos, move);
        // Validacion del movimiento dentro de la cja
        if (is_in_the_box(pos_aux))
        {
            // Validacion de la disponibilidad de la celda
            if (is_avaliable(matrix, pos_aux))
            {
                // Guardado de la posicion
                pos[0] = pos_aux[0];
                pos[1] = pos_aux[1];
                // Marcado del paso
                matrix[pos[0]][pos[1]] = inetegr_to_letter(letter);
                letter++;
            }
        }
    }
}
void decide_case()
{
    char test;
    char matrix[size][size];
    int pos[2];
    printf("¿Deseas usar el programa con los datos de prueba?(Y/n): ");
    scanf("%c", &test);
    if (test == 'Y' || test == 'y')
    {
        pos[0] = rand() % size;
        pos[1] = rand() % size;
    }
    else
    {
        printf("Escribe la posicion x y donde quieres iniciar.\nEscribir con un espacio entre los numeros: ");
        scanf("%d %d", &pos[0] - 1, &pos[1] - 1);
    }
    // Inicializacion de la matriz
    initialize_matrix(matrix);
    // Caminata
    print(matrix);
    printf("\n");
    random_walk(pos, matrix);
    // Impresion del estado
    print(matrix);
}
int main()
{
    srand(time(NULL));
    decide_case();
    return 0;
}
