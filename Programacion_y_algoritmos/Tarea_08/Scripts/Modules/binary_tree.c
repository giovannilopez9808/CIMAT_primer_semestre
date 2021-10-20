#include "binary_tree.h"
/* 
Creacion de un nodo del arbol
 */
node *create_node(int value)
{
    node *aux;
    aux = (node *)malloc(sizeof(node));
    aux->info = value;
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}
/* 
Creacion de un nodo del arbol dado su raiz y su valor
 */
node *insert_node(node *root, int value)
{
    // Si el nodo es la raiz, entonces se creara
    if (root == NULL)
        return create_node(value);

    // Si no es la raiz entonces se revisara en donde deberia quedar la hoja
    if (value < root->info)
        // Si es un valor menor a el nodo entonces debera ir en la izquierda
        root->left = insert_node(root->left, value);
    else
        // Si es un valor mayor a el nodo entonces debera ir en la derecha
        root->right = insert_node(root->right, value);
    return root;
}
/* 
Obtiene el minimo valor del subarbol de la raiz que se da
 */
node *min_value_node(node *node_aux)
{
    node *current = node_aux;
    // Ciclo para desplazarse por la izquierda
    while (current && current->left != NULL)
        // Para cuando se llegue a el nodo en donde el lado izquierdo es vacio, entonces habremos llegado a el valor minimo
        current = current->left;
    return current;
}
/* 
Elimina un nodo y lo remplaza por su valor
 */
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
        node *aux;
        // Si el nodo solo contiene uno o ninguna hoja
        if (root->left == NULL)
        {
            aux = root->right;
            free(root);
            return aux;
        }
        else if (root->right == NULL)
        {
            aux = root->left;
            free(root);
            return aux;
        }
        // El nodo contiene dos hojas, se debera encontrar el valor minimo en el subarbol
        aux = min_value_node(root->right);
        // Copia del valor
        root->info = aux->info;
        // Eliminacion del nodo donde se encontraba el valor minimo
        root->right = delete_node(root->right, aux->info);
    }
    return root;
}
/* 
Realiza la cuenta de los nodos de un arbol
 */
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
/* 
Realiza la creacion de un arbol desde cero
 */
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
/* 
Algortimo para la impresion desde un preorden
 */
void Preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->info);
        Preorder(root->left);
        Preorder(root->right);
    }
}
/* 
Realiza la impresion desde un preorden
 */
void print_preorder(node *root)
{
    printf("\tPreorder: {");
    Preorder(root);
    printf("}\n");
}
/* 
Algoritmo para la impresion en orden
 */
void Inorder(node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d, ", root->info);
        Inorder(root->right);
    }
}
/* 
Ejecuta la impresion en orden
 */
void print_inorder(node *root)
{
    printf("Inorder: {");
    Inorder(root);
    printf("}\n");
}
/* 
Algoritmo que realiza la impresion post orden
 */
void Postorder(node *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d, ", root->info);
    }
}
/* 
Ejecuta la impresion post order
 */
void print_postorder(node *root)
{
    printf("Postorder: {");
    Postorder(root);
    printf("}\n");
}
/* 
Obtiene el tamaño del arbol
 */
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

        // Usa unicamente el mas largo
        if (left_depth > right_depth)
            return (left_depth + 1);
        else
            return (right_depth + 1);
    }
}