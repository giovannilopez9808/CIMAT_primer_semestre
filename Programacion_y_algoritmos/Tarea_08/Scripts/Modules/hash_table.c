#include "hash_table.h"
#include "sets.h"
/* 
Obtiene el hash a partir de una key
 */
int obtain_hash(char *key)
{
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = hash + key[i];
    }
    return hash;
}
/* 
Obtiene el indice a partir de un hash
 */
int obtain_hash_index(char *key)
{
    int hash = obtain_hash(key);
    return hash % size;
}
/* 
Añade un arbol al hash
 */
void add_tree(hash_data *data, node *root, char *key)
{
    // Obtiene el indice del hash table
    int index = obtain_hash_index(key);
    // Variable temporal del bloque
    list *temp = create_list(root, key);
    // Lista donde se escribira el arbol
    list *list_input = (data + index)->list;
    // Recorre hasta el final de la lista
    while (list_input->next != NULL)
    {
        list_input = list_input->next;
    }
    // Escritura de la lista
    list_input->next = temp;
}
/* 
Crea un arbol desde terminal y lo añade a la tabla de hash
 */
void create_hash_element(hash_data *data, char *key)
{
    node *root = create_tree();
    add_tree(data, root, key);
}
/* 
Inicializa la tabla de hash con un preset de arboles
 */
hash_data *initialize_hash_table()
{
    // Inicializacion de la tabla
    hash_data *hash_table = (hash_data *)malloc(size * sizeof(hash_data));
    // inicializacion de cada lista
    for (int i = 0; i < size; i++)
    {
        (hash_table + i)->list = create_dummy_list();
    }
    // Preset1
    add_tree(hash_table, obtain_set1(), "set0");
    // Preset2
    add_tree(hash_table, obtain_set2(), "set1");
    // Preset3
    add_tree(hash_table, obtain_set3(), "tes0");
    return hash_table;
}
/* 
Realiza la impresion de todos los arboles en la tabla de hash
 */
void print_all_the_trees(hash_data *data)
{
    hash_data *hash_aux;
    list *list_aux;
    int attempt;
    // Recorre todas las celdas
    for (int i = 0; i < size; i++)
    {
        hash_aux = (data + i);
        list_aux = hash_aux->list;
        list_aux = list_aux->next;
        attempt = 0;
        // Recorre toda la lista
        while (list_aux != NULL)
        {
            if (attempt == 0)
            {
                printf("Index: %d\n", i);
                attempt++;
            }
            printf("\tKey: %s\n", list_aux->key);
            print_preorder(list_aux->root);
            list_aux = list_aux->next;
        }
    }
}