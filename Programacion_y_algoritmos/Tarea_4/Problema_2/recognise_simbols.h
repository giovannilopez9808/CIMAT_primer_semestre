// Definicion de las letras y simbolos en ascii
#define final_letter_lower 122
#define begin_letter_lower 87
#define final_letter_cap 90
#define begin_letter_cap 65
#define number_letters 26
#define space 32
int is_a_space(int letter)
{
    /* 
    Reconoce si un caracter es un espacio, si lo es regresa 1, si no regresa 0
     */
    if (letter == space)
    {
        return 1;
    }
    return 0;
}
int is_a_letter(int letter)
{
    /* 
    Reconoce si el caracter se entra entre A y z en el codigo ascii, si lo esta regresa 1, si no 0
     */
    if ((letter >= begin_letter_cap) && (letter <= final_letter_lower))
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
        position = letter - begin_letter_lower - 10;
    }
    else
    {
        position = letter - begin_letter_cap;
    }
    return position;
}