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
    list *temp = create_list(root, key);
    list *list_input = (data + index)->list;
    while (list_input->next != NULL)
    {
        list_input = list_input->next;
    }
    list_input->next = temp;
}
void create_hash_element(hash_data *data, char *key)
{
    node *root = create_tree();
    add_tree(data, root, key);
}
hash_data *initialize_hash_table()
{
    hash_data *hash_table = (hash_data *)malloc(size * sizeof(hash_data));
    for (int i = 0; i < size; i++)
    {
        (hash_table + i)->list = create_dummy_list();
    }
    add_tree(hash_table, obtain_set1(), "set0");
    add_tree(hash_table, obtain_set2(), "set1");
    add_tree(hash_table, obtain_set3(), "tes0");
    return hash_table;
}
void print_all_the_trees(hash_data *data)
{
    hash_data *hash_aux;
    list *list_aux;
    int attempt;
    for (int i = 0; i < size; i++)
    {
        hash_aux = (data + i);
        list_aux = hash_aux->list;
        list_aux = list_aux->next;
        attempt = 0;
        while (list_aux != NULL)
        {
            if (attempt == 0)
            {
                printf("Index: %d\n", i);
                attempt++;
            }
            printf("\tKey: %s\n", list_aux->key);
            print_preorder(list_aux->root);
            list_aux = list_aux->next;
        }
    }
}