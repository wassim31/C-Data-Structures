// still buggy 

#include <stdlib.h>
#include <stdio.h>
typedef struct node node;
struct node {
    int value;
    node *next;
};
void push(node **root, int value)
{
    node *temp = malloc(sizeof(node));
    temp->value = value;
    if(*root == NULL)
    {
        *root = temp;
        return;        
    }
    temp->next = *root;
    *root = temp;
}
void insert_node(node **root, int value)
{
    node *temp = malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    if(*root == NULL)
    {
        *root = temp;
        return;
    }
    node *curr = *root;
    for(; curr->next != NULL ; curr = curr->next);
    curr->next = temp;
    return;
    
}
void print(node *root)
{
    for(node *temp = root ; temp != NULL ; temp = temp->next)
    {
        printf("%d ", temp->value);
    }
    printf("\n");
}
int num_ofelements(node *root)
{
    int i = 0;
    for(node *curr = root ; curr != NULL ; curr = curr->next, i++);
    return i;
}
int main(int argc, char const *argv[])
{
    node *root = NULL;
    node *stack = NULL;
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 3);
    node *temp = root;
    node *test = temp->next;
    for(int temp2 = temp->value ; temp->next != NULL ; temp = temp->next , temp->value = test->value, test = test->next)
    {
        push(&stack,temp->value);
    }
    print(stack);



    //  print(root);

    return 0;
}
