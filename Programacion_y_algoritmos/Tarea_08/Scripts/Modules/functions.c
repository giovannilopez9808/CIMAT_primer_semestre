#include "functions.h"
/* 
Realiza la impresion del arbol con mayor profundidad en una hash table
 */
void print_maximum_depth_tree(hash_data *hash_table)
{
    hash_data *hash_aux;
    list *list_aux, *list_max = NULL;
    int max = 0, depth_i, index;
    // Recorrido de todas las celdas del hash
    for (int i = 0; i < size; i++)
    {
        // Seleccion de la casilla del hash table
        hash_aux = (hash_table + i);
        // Seleccion de la primer lista
        list_aux = hash_aux->list;
        // La primer celda esta vacia
        list_aux = list_aux->next;
        // Si la lista no esta vacia
        while (list_aux != NULL)
        {
            // Obtendea su altura
            depth_i = obtain_depth(list_aux->root);
            // Si es mayor al maximo se reemplaza
            if (depth_i > max)
            {
                list_max = list_aux;
                max = depth_i;
            }
            // Pasa a la siguiente
            list_aux = list_aux->next;
        }
    }
    // Impresion de los datos
    index = obtain_hash_index(list_max->key);
    printf("Index: %d\n", index);
    printf("Key: %s\n", list_max->key);
    print_preorder(list_max->root);
}
/* 
Inserta un nodo a un arbol dado
 */
void insert_node_on_tree(hash_data *hash_table)
{
    // Proceso de la busqueda del arbol
    char *key = NULL;
    key = (char *)malloc(sizeof(char));
    int aux, index, value;
    hash_data *hash_aux;
    list *list_aux;
    // Lectura de la key
    printf("Introduce la key del arbol donde se insertara un nodo: ");
    aux = scanf(" %s", key);
    // Key a hash a index
    index = obtain_hash_index(key);
    // Lectura de la celda
    hash_aux = (hash_table + index);
    // Lectura del bloque
    list_aux = hash_aux->list;
    list_aux = list_aux->next;
    // Si el bloque no existe se manda a leer otro hash
    while (list_aux == NULL)
    {
        printf("Arbol no existe\n");
        return;
    }
    // Busca el bloque que contenga a la key
    while ((strcmp(list_aux->key, key) != 0) && (list_aux->root != NULL))
    {
        list_aux = list_aux->next;
    }
    // Si no encuentra algun bloque con el hash ess que no existe
    if ((list_aux->root) == NULL)
    {
        printf("Bloque no encontrado\n");
        return;
    }
    // Si paso lo anterior es porque se encontro el bloque
    printf("Introduce el valor del nodo: ");
    aux = scanf(" %d", &value);
    // Insercion del nodo
    insert_node(list_aux->root, value);
    printf("Nodo creado exitosamente\n");

    (void)aux;
}
/* 
Eliminacion un nodo a un arbol dado
 */
void delete_node_on_tree(hash_data *hash_table)
{
    // Proceso de la busqueda del arbol
    char *key = NULL;
    key = (char *)malloc(sizeof(char));
    int aux, index, value;
    hash_data *hash_aux;
    list *list_aux;
    // Lectura de la key
    printf("Introduce la key del arbol donde se insertara un nodo: ");
    aux = scanf(" %s", key);
    // key a hash a index
    index = obtain_hash_index(key);
    // Lectura de la celda
    hash_aux = (hash_table + index);
    // Lectura del bloque
    list_aux = hash_aux->list;
    list_aux = list_aux->next;
    // Si el bloque no existe se manda a leer otro hash
    while (list_aux == NULL)
    {
        printf("Arbol no existe\n");
        break;
    }
    // Busca el bloque que contenga a la key
    while ((strcmp(list_aux->key, key) != 0) && (list_aux->root != NULL))
    {
        list_aux = list_aux->next;
    }
    // Si no encuentra algun bloque con el hash ess que no existe
    if ((list_aux->root) == NULL)
    {
        printf("Nodo no encontrado\n");
        return;
    }
    // Si paso lo anterior es porque se encontro el bloque
    index = obtain_hash_index(key);
    printf("Introduce el valor del nodo: ");
    aux = scanf(" %d", &value);
    // Eliminacion del nodo
    delete_node(list_aux->root, value);
    printf("Nodo eliminado exitosamente\n");
    (void)aux;
}