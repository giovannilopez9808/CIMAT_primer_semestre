void inverse_file(struct student *students, int size)
{
    struct student aux;
    for (int i = 0; i < size / 2; i++)
    {
        aux = students[i];
        students[i] = students[size - i - 1];
        students[size - i - 1] = aux;
    }
}