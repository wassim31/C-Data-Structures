#include <stdlib.h>
#include <stdio.h>
#define SIZE 20
typedef struct stack stack;
struct stack
{
    int top;
    unsigned capacity;
    int *array;
};
stack *create_stack(unsigned capacity)
{
    stack *root = malloc(sizeof(stack));
    root->top = -1;
    root->array = malloc(sizeof(int) * capacity);
    root->capacity = capacity;
    return root;
}
void push(stack *root, int value)
{
    (root->top)++;
    root->array[root->top] = value;
}
int pop(stack *root)
{
    int test = root->array[root->top];
    root->top--;
    return test;
}
int my_strlen(char *string)
{
    int i = 0;
    for(; string[i] != '\0'; i++);
    return i-1;
}
void print(stack *root)
{
    for(; root->top != -1; root->top--)
    {
        printf("%d", root->array[root->top]);
    }
}
int main(int argc, char const *argv[])
{
    stack *new_stack = NULL;
    new_stack = create_stack(SIZE);
    char *string = malloc(sizeof(char) * SIZE);
    fgets(string,SIZE, stdin);
    printf("%s", string);

    for(int i = 0 ; i < my_strlen(string) ; i++)
    {
        switch(string[i])
        {
            case '^':
                push(new_stack,string[i]);
            break;

            case '*':
            push(new_stack,string[i]);
            break;

            case '/':
            push(new_stack,string[i]);
            break;

            case '+':
            push(new_stack,string[i]);
            break;
            
            case '-':
            push(new_stack,string[i]);
            break;

            
            
        }
    }
    return 0;
}
