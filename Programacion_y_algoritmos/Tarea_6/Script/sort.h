int comparison_names(struct student student1, struct student student2)
{
    int i = 0;
    int compare;
    char *grade1 = student1.name;
    char *grade2 = student2.name;
    while (grade1[i] != '\0' && grade2[i] != '\0')
    {
        compare = grade1[i] - grade2[i];
        if (compare != 0)
        {
            return compare;
        }
        i = i + 1;
    }
    if (grade1[i] == '\0' && grade2[i] != '\0')
    {
        return -grade2[i];
    }
    if (grade2[i] == '\0' && grade1[i] != '\0')
    {
        return grade1[i];
    }
    return 0;
}
int comparison_ages(struct student student1, struct student student2)
{
    int compare = student1.age - student2.age;
    return compare;
}
int comparison_grades(struct student student1, struct student student2)
{
    char *grade1 = student1.grade;
    char *grade2 = student2.grade;
    int i = 0;
    int compare;
    while (grade1[i] != '\0' && grade2[i] != '\0')
    {
        compare = grade1[i] - grade2[i];
        if (compare != 0)
        {
            return compare;
        }
        i = i + 1;
    }
    if (grade1[i] == '\0' && grade2[i] != '\0')
    {
        return grade1[i];
    }
    if (grade2[i] == '\0' && grade1[i] != '\0')
    {
        return -grade2[i];
    }
    return 0;
}
int select_comparison(struct student student1, struct student student2, int option)
{
    int compare;
    switch (option)
    {
    case 1:
        compare = comparison_names(student1, student2);
        break;
    case 2:
        compare = comparison_ages(student1, student2);
        break;
    case 3:
        compare = comparison_grades(student1, student2);
        break;
    default:
        break;
    }
    return compare;
}
int reduce_sort(struct student *students, int low, int high, int option)
{

    struct student aux;
    // Seleccion del pivote
    struct student pivot = students[high];
    struct student student_j = students[high];
    // posicion inicial de la lista de numeros
    int i = low;
    int compare;
    for (int j = low; j <= high - 1; j++)
    {
        // Si el elemento j es menor o igual al pivote entonces se realizara u intercambio
        student_j = students[j];
        compare = select_comparison(student_j, pivot, option);
        if (compare < 0)
        {
            // Realiza el cambio de valores
            aux = students[j];
            students[j] = students[i];
            students[i] = aux;
            i++;
        }
    }
    // Intercambio del pivote con el elemento i, para que los elementos en la posicion mayores a i tengan un valor mayor igual a el pivote
    // Realiza el cambio de valores
    aux = students[high];
    students[high] = students[i];
    students[i] = aux;
    return i;
}

void sorted(struct student *students, int start, int last, int option)
{
    /* 
    Realiza el ordenamiento de los numeros de forma decreciente siguiendo el algoritmo de quick sort guardando llos cambios en las posiciones que se hagan realizado en un arreglo
     */
    if (start < last)
    {
        int numbers_partition;
        numbers_partition = reduce_sort(students,
                                        start,
                                        last,
                                        option);
        // Ordena la parte inferior
        sorted(students,
               start,
               numbers_partition - 1,
               option);
        // Ordena la parte superior
        sorted(students,
               numbers_partition + 1,
               last,
               option);
    }
}