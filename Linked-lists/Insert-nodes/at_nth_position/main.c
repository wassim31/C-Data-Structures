#include "main.h"
int main(int argc, char const *argv[])
{
    node *head = NULL;

    nth_insert(&head, 1, 1);
    nth_insert(&head, 2, 2);
    nth_insert(&head, 8, 3);
    print(head);
    deallocate(&head);
    return 0;
}

void nth_insert(node **root , int value, int n)
{
    node *temp1 = malloc(sizeof(node));
    temp1->value = value;
    temp1->next = NULL;
    if(n == 1)
    {
        temp1->next = *root;
        *root = temp1;
        return;
    }
    node *temp2 = *root;
    for(int i = 1 ; i < n-1 ; i++) // first node n = 1
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;

}

void deallocate(node **root)
{
    for(node *curr = *root; curr->next != NULL ;)
    {
        node *aux = curr;
        curr = curr->next;
        free(aux);
    }
}
void print(node *root)
{
    for(node *curr = root ; curr != NULL ; curr = curr->next)
    {
        printf("%d ", curr->value);
    }
    printf("\n");
}