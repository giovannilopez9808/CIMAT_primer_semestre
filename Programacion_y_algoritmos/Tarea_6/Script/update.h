void delete_student(struct student *students, int *size, int index)
{
    for (int i = index; i < *size - 1; i++)
    {
        students[i] = students[i + 1];
    }
    *size = *size - 1;
}