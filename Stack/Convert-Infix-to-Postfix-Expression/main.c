#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node{
    int value;
    node *next;
};

int main(int argc, char const *argv[])
{   
    char *string = malloc(sizeof(char)* 20);
    fgets(string, 20, stdin);
    
    return 0;
}
   
