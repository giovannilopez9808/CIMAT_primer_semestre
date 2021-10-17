#include "Functions/binary_tree.h"
// #include "Functions/hash_table.h"
int main()
{
    node *root = Create_node(60);
    root->left = Create_node(15);
    root->right = Create_node(80);
    node *aux = root->left;
    aux->left = Create_node(7);
    aux->right = Create_node(18);
    aux = root->right;
    aux->left = Create_node(65);
    aux->right = Create_node(100);
    print_postorder(root);
    return 0;
}
