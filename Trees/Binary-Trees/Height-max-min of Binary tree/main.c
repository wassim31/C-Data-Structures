#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
typedef struct node node;
int find_max(node *root);
int find_min(node *root);
node* newNode(node *root, int data);
int height(node *root);
int height(node *root);

struct node{
    int value;
    node *left;
    node *right;
};

int main(int argc, char const *argv[])
{
    node *root = newNode(root,20);
    root->left = newNode(root,-2);
    root->right = newNode(root,5);
    root->left->right = newNode(root,20);
    root->left->right->left = newNode(root,1);
    root->left->right->right = newNode(root,110);
    root->right->right = newNode(root,9);
    root->right->right->left = newNode(root,4);
    printf("min : %d\nmax : %d\nheigh : %d\n", find_min(root),find_max(root),height(root));

    return 0;
}
node* newNode(node *root, int data)
{   
    node *node = malloc(sizeof(node));
    node->value = data;
    node->left = node->right = NULL;
    return (node);
}
 
int find_min(node *root)
{
    if(root == NULL)
        return INT_MAX;
    int min = root->value;
    int left_min = find_min(root->left);
    int right_min = find_min(root->right);
    if(left_min < min)
        min = left_min;
    if(right_min < min)
        min = right_min;
    return min;    
}
int find_max(node *root)
{
    if(root == NULL)
        return INT_MIN;
    int max = root->value;
    int left_max = find_max(root->left);
    int right_max = find_max(root->right);
    if(left_max > max)
        max = left_max;
    if(right_max > max)
        max = right_max;
    return max;

}
int max(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int height(node *root)
{
    if(root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return max(left_height,right_height) + 1;

}
