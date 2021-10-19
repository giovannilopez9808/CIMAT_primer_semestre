#ifndef linked_list_H
#define linked_list_H
#include "binary_tree.h"
typedef struct List
{
    node *root;
    char *key;
    struct List *next;
} list;
#endif