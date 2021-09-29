void count_per_group(struct student *students, int size, int *count)
{
    /* 
    Realiza el conteo de las personas en cada grupo
     */
    int letter;
    // Inicializacion del conteo
    for (int i = 0; i < 6; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        // Transformacion de la letra a el espacio de los elementos
        letter = students[i].s->group - 'A';
        count[letter] += 1;
    }
}
void count_per_turn(struct student *students, int size, int *count)
{
    /* 
    Realiza el conteo de las personas en cada grupo
     */
    // Inicializacion del conteo
    for (int i = 0; i < 2; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        // Si es de turno matutino esta en la posicion 0
        if (students[i].s->turn == 'M')
        {
            count[0] += 1;
        }
        // Si no, es del vespertino en la posicion 1
        else
        {
            count[1] += 1;
        }
    }
}