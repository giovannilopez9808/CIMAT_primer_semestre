#ifndef linked_list_H
#define linked_list_H
#include "binary_tree.h"
typedef struct List
{
    node *root;
    char *key;
    struct List *next;
} list;
list *create_list(node *root, char *key);
list *create_dummy_list();
#endif