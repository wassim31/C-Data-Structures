#include "main.h"

int main(int argc, char const *argv[])
{
    printf("How many elements in the stack : ");
    do
    {
        scanf("%d", &n);
    } while(n > 10 || n <= 0);
    int *array = malloc(n * (sizeof(int)));
    init(array);
    push(array, 6); // testing the overflow & maintain it 
    print(array);
    pop();
    print(array);
    free(array);
    return 0;
}
void push(int *array, int x)
{
    top++; // 0
    if(top == n)
    {
        // we copy the actual array , and put it in a new array
        // the new_array.size = actual_array.size * 2
        // so if the actual_array has n elements , to copy it 
        // it took us O(n).
        // Here we understand the benefits of linked-lists
        int *new_array = resize(array);
        *(array+top) = x;
    }
    *(array+top) = x;
}
int *resize(int *array)
{
    int new_size = n * 2, i = 0;
    int *new_array = malloc(sizeof(int) * new_size);
    for(; i < new_size ; i++)
    {
        *(new_array+i) = *(array+i);
    }
    return new_array;
}
void pop()
{
    if(top == -1)
    {
        printf("Empty Stack\n");
        return;
    }
    top--;
}
void init(int *array)
{
    
    for(int i = 0, x ; i < n ; i++)
    {
        printf("Element %d : ", i);
        scanf("%d", &x);
        push(array, x);
    }    
}
void print(int *array)
{
    for(int i = 0 ; i < top+1 ; i++)
    {
        printf("%d ", *(array+i));
    }  
    printf("\n");
}
