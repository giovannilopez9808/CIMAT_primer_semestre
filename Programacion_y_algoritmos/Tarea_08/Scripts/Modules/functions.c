#include "functions.h"
void print_maximum_depth_tree(hash_data *hash_table)
{
    hash_data max_hash = *hash_table;
    int max = obtain_depth(max_hash.tree), depth_i, index;
    for (int i = 1; i < size; i++)
    {
        depth_i = obtain_depth(hash_table[i].tree);
        if (depth_i > max)
        {
            max_hash = hash_table[i];
            max = depth_i;
        }
    }
    index = obtain_hash_index(max_hash.number_nodes);
    printf("Index: %d\n", index);
    print_preorder(max_hash.tree);
}
void insert_node_on_tree(hash_data *hash_table)
{
    int aux, index, value;
    printf("Introduce numero de nodos del arbol donde se insertara un nodo: ");
    aux = scanf(" %d", &index);
    index = obtain_hash_index(index);
    while (hash_table[index].tree == NULL)
    {
        printf("Arbol no existe\n");
        printf("Introduce numero de nodos del arbol donde se insertara un nodo: ");
        aux = scanf(" %d", &index);
        index = obtain_hash_index(index);
    }
    printf("Introduce el valor del nodo: ");
    aux = scanf(" %d", &value);
    insert_node(hash_table[index].tree, value);
    (void)aux;
}
void delete_node_on_tree(hash_data *hash_table)
{
    int aux, index, value;
    printf("Introduce numero de nodos del arbol donde se insertara un nodo: ");
    aux = scanf(" %d", &index);
    while (hash_table[index].tree == NULL)
    {
        printf("Arbol no existe\n");
        printf("Introduce numero de nodos del arbol donde se insertara un nodo: ");
        aux = scanf(" %d", &index);
    }
    index = obtain_hash_index(index);
    printf("Introduce el valor del nodo: ");
    aux = scanf(" %d", &value);
    delete_node(hash_table[index].tree, value);
    (void)aux;
}