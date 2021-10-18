#include "hash_table.h"
#include "sets.h"
int obtain_hash_index(int key)
{
    return key % size;
}
void add_tree(hash_data *data, node *root)
{
    int number_nodes = count_nodes(root);
    int index = obtain_hash_index(number_nodes);
    (data + index)->tree = (node *)malloc(sizeof(node));
    (data + index)->tree = root;
    (data + index)->number_nodes = number_nodes;
}
void create_hash_element(hash_data *data)
{
    node *root = create_tree();
    add_tree(data, root);
}
hash_data *initialize_hash_table()
{
    hash_data *hash_table = (hash_data *)malloc(size * sizeof(hash_data));
    add_tree(hash_table, obtain_set1());
    add_tree(hash_table, obtain_set2());
    add_tree(hash_table, obtain_set3());
    return hash_table;
}
void print_all_the_trees(hash_data *data)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i].tree != NULL)
        {
            printf("Index: %d\n", i);
            print_preorder(data[i].tree);
        }
    }
}