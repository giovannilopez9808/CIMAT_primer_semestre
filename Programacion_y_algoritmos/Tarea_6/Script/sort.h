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
int reduce_sort(int (*compare)(struct student, struct student), struct student *students, int low, int high)
{

    struct student aux;
    // Seleccion del pivote
    struct student pivot = students[high];
    struct student student_j = students[high];
    // posicion inicial de la lista de numeros
    int i = low;
    int diff;
    for (int j = low; j <= high - 1; j++)
    {
        // Si el elemento j es menor o igual al pivote entonces se realizara u intercambio
        student_j = students[j];
        diff = compare(student_j, pivot);
        if (diff < 0)
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

void sort_function(int (*compare)(struct student, struct student), struct student *students, int start, int last)
{
    /* 
    Realiza el ordenamiento de los numeros de forma decreciente siguiendo el algoritmo de quick sort guardando llos cambios en las posiciones que se hagan realizado en un arreglo
     */
    if (start < last)
    {
        int numbers_partition;
        numbers_partition = reduce_sort(compare,
                                        students,
                                        start,
                                        last);
        // Ordena la parte inferior
        sort_function(compare,
                      students,
                      start,
                      numbers_partition - 1);
        // Ordena la parte superior
        sort_function(compare,
                      students,
                      numbers_partition + 1,
                      last);
    }
}
void sort(struct student *students, int size, int option)
{
    switch (option)
    {
    case 1:
        sort_function(comparison_names,
                      students,
                      0,
                      size - 1);
        break;
    case 2:
        sort_function(comparison_ages,
                      students,
                      0,
                      size - 1);
        break;
    case 3:
        sort_function(comparison_grades,
                      students,
                      0,
                      size - 1);
        break;
    default:
        break;
    }
}