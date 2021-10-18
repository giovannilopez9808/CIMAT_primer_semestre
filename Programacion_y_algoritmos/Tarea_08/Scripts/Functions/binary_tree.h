#ifndef binary_tree_H
#define binary_tree_H
#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int info;
} node;

node *Create_node(int value);
node *create_tree();

void print_postorder(node *root);
void print_preorder(node *root);
void print_inorder(node *root);

node *Insert_node(node *root, int value);
node *delete_node(node *root, int info);
int obtain_depth(node *root);
int count_nodes(node *root);
#endif