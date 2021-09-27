int compare_names(struct person *person1, struct person *person2)
{
    /* 
    Realiza la comparacion de los nombres, si el primer apellido es igual compara el segundo. Si el segundo apellido es igual compara el nombre
     */
    int compare;
    compare = order_names(person1->last_name_1, person2->last_name_1);
    if (compare == 0)
    {
        compare = order_names(person1->last_name_2, person2->last_name_2);
    }
    if (compare == 0)
    {
        compare = order_names(person1->name, person2->name);
    }
    return compare;
}
int reduce_sort(struct person **pointers, int low, int high)
{

    struct person *aux;
    // Seleccion del pivote
    struct person *pivot = pointers[high];
    // posicion inicial de la lista de numeros
    int i = low;
    int compare;
    for (int j = low; j <= high - 1; j++)
    {
        // Si el elemento j es menor o igual al pivote entonces se realizara u intercambio
        compare = compare_names(pointers[j], pivot);
        if (compare < 0)
        {
            // Realiza el cambio de valores
            aux = pointers[j];
            pointers[j] = pointers[i];
            pointers[i] = aux;
            i++;
        }
    }
    // Intercambio del pivote con el elemento i, para que los elementos en la posicion mayores a i tengan un valor mayor igual a el pivote
    // Realiza el cambio de valores
    aux = pointers[high];
    pointers[high] = pointers[i];
    pointers[i] = aux;
    return i;
}

void sorted(struct person **pointers, int start, int last)
{
    /* 
    Realiza el ordenamiento de los numeros de forma decreciente siguiendo el algoritmo de quick sort guardando llos cambios en las posiciones que se hagan realizado en un arreglo
     */
    if (start < last)
    {
        int numbers_partition;
        numbers_partition = reduce_sort(pointers, start, last);
        // Ordena la parte inferior
        sorted(pointers,
               start,
               numbers_partition - 1);
        // Ordena la parte superior
        sorted(pointers,
               numbers_partition + 1,
               last);
    }
}