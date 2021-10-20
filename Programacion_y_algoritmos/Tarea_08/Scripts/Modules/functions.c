#include "functions.h"
void print_maximum_depth_tree(hash_data *hash_table)
{
    hash_data *hash_aux;
    list *list_aux, *list_max = NULL;
    int max = 0, depth_i, index;
    for (int i = 0; i < size; i++)
    {
        hash_aux = (hash_table + i);
        list_aux = hash_aux->list;
        list_aux = list_aux->next;
        while (list_aux != NULL)
        {
            depth_i = obtain_depth(list_aux->root);
            if (depth_i > max)
            {
                list_max = list_aux;
                max = depth_i;
            }
            list_aux = list_aux->next;
        }
    }
    index = obtain_hash_index(list_max->key);
    printf("Index: %d\n", index);
    printf("Key: %s\n", list_max->key);
    print_preorder(list_max->root);
}
void insert_node_on_tree(hash_data *hash_table)
{
    char *key = NULL;
    key = (char *)malloc(sizeof(char));
    int aux, index, value;
    hash_data *hash_aux;
    list *list_aux;
    printf("Introduce la key del arbol donde se insertara un nodo: ");
    aux = scanf(" %s", key);
    index = obtain_hash_index(key);
    hash_aux = (hash_table + index);
    list_aux = hash_aux->list;
    list_aux = list_aux->next;
    while (list_aux->root == NULL)
    {
        printf("Arbol no existe\n");
        printf("Introduce la key del arbol donde se insertara un nodo: ");
        aux = scanf(" %s", key);
        index = obtain_hash_index(key);
        printf("%d\n", index);
        hash_aux = (hash_table + index);
        list_aux = hash_aux->list;
        list_aux = list_aux->next;
    }
    while ((strcmp(list_aux->key, key) != 0) && (list_aux->root != NULL))
    {
        list_aux = list_aux->next;
    }
    if ((list_aux->root) == NULL)
    {
        printf("Nodo no encontrado\n");
        return;
    }
    printf("Introduce el valor del nodo: ");
    aux = scanf(" %d", &value);
    insert_node(list_aux->root, value);
    printf("Nodo creado exitosamente\n");

    (void)aux;
}
void delete_node_on_tree(hash_data *hash_table)
{
    char *key = NULL;
    key = (char *)malloc(sizeof(char));
    int aux, index, value;
    hash_data *hash_aux;
    list *list_aux;
    printf("Introduce la key del arbol donde se insertara un nodo: ");
    aux = scanf(" %s", key);
    index = obtain_hash_index(key);
    hash_aux = (hash_table + index);
    list_aux = hash_aux->list;
    list_aux = list_aux->next;
    while (list_aux->key == NULL)
    {
        printf("Arbol no existe\n");
        printf("Introduce la key del arbol donde se insertara un nodo: ");
        aux = scanf(" %s", key);
        index = obtain_hash_index(key);
        printf("%d\n", index);
        hash_aux = (hash_table + index);
        list_aux = hash_aux->list;
        list_aux = list_aux->next;
    }
    while ((strcmp(list_aux->key, key) != 0) && (list_aux->root != NULL))
    {
        list_aux = list_aux->next;
    }
    if ((list_aux->root) == NULL)
    {
        printf("Nodo no encontrado\n");
        return;
    }
    index = obtain_hash_index(key);
    printf("Introduce el valor del nodo: ");
    aux = scanf(" %d", &value);
    delete_node(list_aux->root, value);
    printf("Nodo eliminado exitosamente\n");
    (void)aux;
}