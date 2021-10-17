#include "binary_tree.h"
node *Create_node(int value)
{
    node *aux;
    aux = (node *)malloc(sizeof(node));
    aux->info = value;
    aux->left = aux->right = NULL;
    return (aux);
}
void Preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->info);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void print_preorder(node *root)
{
    printf("\n{");
    Preorder(root);
    printf("}\n");
}
void Inorder(node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d, ", root->info);
        Inorder(root->right);
    }
}
void print_inorder(node *root)
{
    printf("\n{");
    Inorder(root);
    printf("}\n");
}
void Postorder(node *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d, ", root->info);
    }
}
void print_postorder(node *root)
{
    printf("\n{");
    Postorder(root);
    printf("}\n");
}
