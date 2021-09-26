void delete_user(struct student *students, int *size, int index)
{
    for (int i = index; i < *size - 1; i++)
    {
        memcpy(&students[i], &students[i + 1], sizeof(struct student));
    }
    *size = *size - 1;
}