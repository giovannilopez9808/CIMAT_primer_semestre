#include <stdio.h>
#define size 10
void print_lines()
{
    printf("-------------");
    printf("-------------\n");
}
void print_stack(int stack[], int top)
{
    /* 
    Imprime el estado del stack en un momento dado
     */
    for (int i = 0; i < top; i++)
    {
        printf(" %d |", stack[i]);
    }
    printf("\n");
}
void pop(int stack[], int *top)
{
    /* 
    Realiza pop en el stack e imprime el estado actual
     */
    *top = *top - 1;
    print_stack(stack, *top);
}
void push(int stack[], int *top, int value)
{
    /* 
    Realiza push en el stack e imprime el estado actual
     */
    stack[*top] = value;
    *top = *top + 1;
    print_stack(stack, *top);
}
int main()
{
    int stack[size];
    int top = 0;
    print_lines();
    printf("Push number 2:\n");
    push(stack, &top, 2);
    print_lines();
    printf("Push number 3:\n");
    push(stack, &top, 3);
    print_lines();
    printf("Push number 4:\n");
    push(stack, &top, 4);
    print_lines();
    printf("Push number 5:\n");
    push(stack, &top, 5);
    print_lines();
    printf("Push number 6:\n");
    push(stack, &top, 6);
    print_lines();
    printf("pop:\n");
    pop(stack, &top);
    print_lines();
    printf("pop:\n");
    pop(stack, &top);
    print_lines();
    printf("pop:\n");
    pop(stack, &top);
    print_lines();
    printf("Push number 4:\n");
    push(stack, &top, 4);
    print_lines();
    printf("Push number 5:\n");
    push(stack, &top, 5);
    return 0;
}