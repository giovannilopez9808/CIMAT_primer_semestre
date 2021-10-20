#include "linked_list.h"
list *create_list(node *root, char *key)
{
    list *aux;
    aux = (list *)malloc(sizeof(list));
    aux->root = (node *)malloc(sizeof(node));
    aux->key = key;
    aux->root = root;
    aux->next = NULL;
    return aux;
}
list *create_dummy_list()
{
    list *aux = (list *)malloc(sizeof(sizeof(list)));
    aux->key = NULL;
    aux->root = NULL;
    aux->next = NULL;
    return aux;
}