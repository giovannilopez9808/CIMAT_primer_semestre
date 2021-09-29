void inverse_file(struct student *students, int size)
{
    /* 
    Realiza la inversion de los datos de los estudiantes. Toma a los estudiantes de los extremos para intercambiar sus posiciones en el arreglo.
     */
    // Estructura auxiliar
    struct student aux;
    // Recorrido hasta la mitad de los datos
    for (int i = 0; i < size / 2; i++)
    {
        aux = students[i];
        students[i] = students[size - i - 1];
        students[size - i - 1] = aux;
    }
}