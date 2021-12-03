#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node
{
    int value;
    node *left;
    node *right;
};
// the space complexity depends on the height of the tree O(h)
void preorder(node *root) // DLR 
{
    if(root == NULL)
        return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root) // LDR
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}
void postorder(node *root) // RDL
{
    if(root == NULL)
        return;
    preorder(root->right);
    printf("%d ", root->value);
    preorder(root->left);
}
node * newnode(node *root, int value)
{
    node *temp = malloc(sizeof(node));

    if(root == NULL)
    {
        temp->value = value;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if(value <= root->value)
    {
        root = newnode(root->left,value);
    }
    else if(value >= root->value)
    {
        root = newnode(root->right, value);
    }

}


int main(int argc, char const *argv[])
{
    node *root = NULL;
    root = newnode(root,2);
    root->left = newnode(root,20);
    root->right = newnode(root,30);
    root->left->left = newnode(root,0);
    root->left->right = newnode(root,-3);
    printf("Preorder : ");
    preorder(root);
    printf("\ninorder : ");
    inorder(root);
    printf("\nPostorder : ");
    postorder(root);
    return 0;
}
