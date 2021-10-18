#include "hash_table.h"
#include "sets.h"
int obtain_hash_index(int key)
{
    return key % size;
}
void add_tree(hash_data *hash_table, node *root)
{
    int number_nodes = count_nodes(root);
    int index = obtain_hash_index(number_nodes);
    (hash_table + index)->tree = (node *)malloc(sizeof(node));
    (hash_table + index)->tree = root;
    (hash_table + index)->number_nodes = number_nodes;
}
void create_hash_element(hash_data *hash_table)
{
    node *root = create_tree();
    add_tree(hash_table, root);
}
hash_data *initialize_hash_table()
{
    hash_data *hash_table = (hash_data *)malloc(size * sizeof(hash_data));
    add_tree(hash_table, obtain_set1());
    add_tree(hash_table, obtain_set2());
    add_tree(hash_table, obtain_set3());
    return hash_table;
}
void print_all_the_trees(hash_data *hash_table)
{
    for (int i = 0; i < size; i++)
    {
        if (hash_table[i].tree != NULL)
        {
            printf("Index: %d\n", i);
            print_preorder(hash_table[i].tree);
        }
    }
}
void free_all_the_trees(hash_data *hash_table)
{
    for (int i = 0; i < size; i++)
    {
        if (hash_table[i].tree != NULL)
        {
            free_node(hash_table[i].tree);
        }
    }
}