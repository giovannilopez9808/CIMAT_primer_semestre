int comparison_names(struct student student1, struct student student2)
{
    /* 
    Realiza la comparación de dos nombres para obtener un orden alfabetico. Si un nombre es prefijo de otro entonces este abarca una posición menor.
     */
    int i = 0;
    int compare;
    // Nombres de los estudiantes
    char *grade1 = student1.name;
    char *grade2 = student2.name;
    // Compara hasta que lleguen al final de su nombre
    while (grade1[i] != '\0' && grade2[i] != '\0')
    {
        // Comparacion
        compare = grade1[i] - grade2[i];
        if (compare != 0)
        {
            // Si son diferentes entocnes devuelve la diferencia en caracteres ascii
            return compare;
        }
        i = i + 1;
    }
    // Si se llego al final de un nombre entonces se checara cual de los dos es prefijo del otro
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
    /* 
    Realiza la comparacion de las edades
     */
    int compare = student1.age - student2.age;
    return compare;
}
int compare_sign(char sign1, char sign2)
{
    /* 
    Comparacion de los signos de una calificacion
     */
    // Si a primer calificacion no tiene signo pero la segunda si
    if (sign1 == '\0' && sign2 != '\0')
    {
        // Se comprueba si es un + o un -
        if (sign2 == '+')
        {
            return -1;
        }
        return 1;
    }
    // Si la primer calificacion tiene signo, entonces no hace nada
    return 0;
}
int comparison_grades(struct student student1, struct student student2)
{
    /* 
    Realiza la comparacion de las calificaciones
     */
    // Calificaciones de los estudiantes
    char *grade1 = student1.grade;
    char *grade2 = student2.grade;
    int compare = grade1[0] - grade2[0];
    // Si son iguales se comparará que signo tienen
    if (compare == 0)
    {
        // Se verifica si la calificacion 2 tiene signo
        compare = compare_sign(grade1[1], grade2[1]);
        if (compare != 0)
            return compare;
        // Se verifica si la calificacion 1 tiene signo
        compare = compare_sign(grade2[1], grade1[1]);
        if (compare != 0)
            return compare;
        // Si los dos tienen signo se comparan
        compare = grade1[1] - grade2[1];
        return compare;
    }
    // Si son diferentes entonces
    return compare;
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
    /* 
    Realiza el ordenamiento de los datos por nombre, años y grados usando el algoritmo de quick sort
     */
    switch (option)
    {
    case 1:
        // Caso para ordenar por nombres
        sort_function(comparison_names,
                      students,
                      0,
                      size - 1);
        break;
    case 2:
        // Caso para ordenar por años
        sort_function(comparison_ages,
                      students,
                      0,
                      size - 1);
        break;
    case 3:
        // Caso para ordenar por calificacion
        sort_function(comparison_grades,
                      students,
                      0,
                      size - 1);
        break;
    default:
        break;
    }
}