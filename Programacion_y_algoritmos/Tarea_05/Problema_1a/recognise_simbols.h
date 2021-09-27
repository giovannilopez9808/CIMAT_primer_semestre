// Definicion de las letras y simbolos en ascii
#define final_letter_lower 122
#define begin_letter_lower 97
#define final_letter_cap 90
#define begin_letter_cap 65
int is_a_letter(int letter)
{
    /* 
    Reconoce si el caracter se entra entre A y z en el codigo ascii, si lo esta regresa 1, si no 0
     */
    int is_capital_letter = ((letter >= begin_letter_cap) && (letter <= final_letter_cap));
    int is_lower_letter = ((letter >= begin_letter_lower) && (letter <= final_letter_lower));
    if ((is_lower_letter) || (is_capital_letter))
    {
        return 1;
    }
    return 0;
}
int equal_capital_and_lower_letters(int letter)
{
    /* 
    Recibe una letra y reconoce su ubicación en el abecedario
     */
    int position;
    if (letter >= begin_letter_lower)
    {
        position = letter - begin_letter_lower;
    }
    else
    {
        position = letter - begin_letter_cap;
    }
    return position;
}
char obtain_capital_letter(int i)
{
    return i + 'A';
}