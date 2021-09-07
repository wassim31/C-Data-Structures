#include <stdlib.h>
#include <stdio.h>
typedef struct node node;
struct node
{
    int value;
    node *next;
};
void print(node *root);
void push(node **root, int x);
void pop(node **root);