#include "hash_table.h"
#include "sets.h"
int obtain_hash(char *key)
{
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = hash + key[i];
    }
    return hash;
}
int obtain_hash_index(char *key)
{
    int hash = obtain_hash(key);
    return hash % size;
}
void add_tree(hash_data *data, node *root, char *key)
{
    int index = obtain_hash_index(key);
    hash_data *hash_index = data + index;
    list *list_input = hash_index->list;
    while (list_input != NULL)
    {
        list_input = (*list_input).next;
    }
    list_input = (list *)malloc(sizeof(list));
    list_input->root = (node *)malloc(sizeof(node));
    list_input->root = root;
    list_input->key = key;
}
void create_hash_element(hash_data *data, char *key)
{
    node *root = create_tree();
    add_tree(data, root, key);
}
hash_data *initialize_hash_table()
{
    hash_data *hash_table = (hash_data *)malloc(size * sizeof(hash_data));
    add_tree(hash_table, obtain_set1(), "set1");
    add_tree(hash_table, obtain_set2(), "set2");
    add_tree(hash_table, obtain_set3(), "set3");
    return hash_table;
}
void print_all_the_trees(hash_data *data)
{
    for (int i = 0; i < size; i++)
    {
        while (data[i].list != NULL)
        {
            printf("Index: %d\n", i);
            printf("Key: %s\n", data[i].list->key);
            print_preorder(data[i].list->root);
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