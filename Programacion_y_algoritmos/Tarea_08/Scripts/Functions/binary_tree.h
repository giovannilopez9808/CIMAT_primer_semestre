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

void print_postorder(node *root);
void print_preorder(node *root);
void print_inorder(node *root);

int obtain_max_depth(node *root);
node *Insert_node(node *root, int value);
node *delete_node(node *root, int info);
#endif