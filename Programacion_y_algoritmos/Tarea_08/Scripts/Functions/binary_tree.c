#include "binary_tree.h"
node *Create_node(int value)
{
    node *aux;
    aux = (node *)malloc(sizeof(node));
    aux->info = value;
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}
node *insert_node(node *root, int value)
{
    // Si el nodo es la raiz, entonces se creara
    if (root == NULL)
        return Create_node(value);

    // Si no es la raiz entonces se revisara en donde deberia quedar la hoja
    if (value < root->info)
        // Si es un valor menor a el nodo entonces debera ir en la izquierda
        root->left = insert_node(root->left, value);
    else
        // Si es un valor mayor a el nodo entonces debera ir en la derecha
        root->right = insert_node(root->right, value);
    return root;
}
node *min_value_node(node *node_aux)
{
    node *current = node_aux;
    // Ciclo para desplazarse por la izquierda
    while (current && current->left != NULL)
        // Para cuando se llegue a el nodo en donde el lado izquierdo es vacio, entonces habremos llegado a el valor minimo
        current = current->left;
    return current;
}
node *delete_node(node *root, int info)
{
    // Si se trata del nodo principal se regresa el mismo valor
    if (root == NULL)
        return root;
    // Si el nodo a eliminar es menor al nodo raiz entonces se encuentra en la izquierda
    if (info < root->info)
        root->left = delete_node(root->left, info);
    // Si el nodo a eliminar es mayor al nodo raiz entonces se encuentra en la derecha
    else if (info > root->info)
        root->right = delete_node(root->right, info);
    // Si el valor a eliminar es igual al nodo raiz entonces nos entramos en el nodo a elimianr
    else
    {
        node *temp;
        // Si el nodo solo contiene uno o ninguna hoja
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        // El nodo contiene dos hojas, se debera encontrar el valor minimo en el subarbol
        temp = min_value_node(root->right);
        // Copia del valor
        root->info = temp->info;
        // Eliminacion del nodo donde se encontraba el valor minimo
        root->right = delete_node(root->right, temp->info);
    }
    return root;
}
int count_nodes(node *root)
{
    if (root != NULL)
    {
        int count_right = count_nodes(root->right);
        int count_left = count_nodes(root->left);
        return count_left + count_right + 1;
    }
    return 0;
}
node *create_tree()
{
    node *root = NULL;
    int nodes_number, value, aux;
    printf("Ingresa el numero de nodos del arbol: ");
    aux = scanf(" %d", &nodes_number);
    for (int i = 0; i < nodes_number; i++)
    {
        printf("Ingresa el valor del nodo: ");
        aux = scanf(" %d", &value);
        root = insert_node(root, value);
    }
    (void)aux;
    return root;
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
    printf("Preorder: {");
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
    printf("Inorder: {");
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
    printf("Postorder: {");
    Postorder(root);
    printf("}\n");
}
int obtain_depth(node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        // Obtiene el tamaño del arbol de lado izquierdo
        int left_depth = obtain_depth(root->right);
        // Obtiene el tamaño del arbol de lado derecho
        int right_depth = obtain_depth(root->left);

        /* use the larger one */
        if (left_depth > right_depth)
            return (left_depth + 1);
        else
            return (right_depth + 1);
    }
}
