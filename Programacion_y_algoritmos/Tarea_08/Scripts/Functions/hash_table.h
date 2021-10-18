#ifndef hash_table_H
#define hash_table_H
#include "binary_tree.h"
#define size 20
typedef struct Hash_data
{
    node *tree;
    int number_nodes;
} hash_data;
hash_data *initialize_hash_table();
void add_tree(hash_data *data, node *root);
void create_hash_element(hash_data *data);
void print_all_the_trees(hash_data *data);
int obtain_hash_index(int key);
#endif