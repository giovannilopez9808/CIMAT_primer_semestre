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