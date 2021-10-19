#include "functions.h"
void print_maximum_depth_tree(hash_data *hash_table)
{
    list *list_max = hash_table->list;
    list *list_aux;
    int max = obtain_depth(list_max->root), depth_i, index;
    for (int i = 1; i < size; i++)
    {
        list_aux = hash_table[i].list;
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
    print_preorder(list_max->root);
}