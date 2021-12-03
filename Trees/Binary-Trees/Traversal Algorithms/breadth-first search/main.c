#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct bt_node bt_node;
typedef struct ll_node ll_node;
typedef struct queue queue;
struct queue
{
    ll_node *rear, *front;
};
struct bt_node 
{
    int value;
    bt_node *left;
    bt_node *right;
};

struct ll_node
{
    bt_node *added_node;
    ll_node *next;
};
bt_node *new_tree(bt_node *root, int data)
{
    bt_node *temp = malloc(sizeof(bt_node));
    if(root == NULL)
    {
        temp->value = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if(data >= root->value)
    {
        root->right = new_tree(root->right,data);
    }
    else if(data <= root->value)
    {
        root->left = new_tree(root->left,data);
    }
}

ll_node *newnode(bt_node *actual_node)
{
    ll_node *temp = malloc(sizeof(ll_node));
    temp->added_node = actual_node;
    temp->next = NULL;
    return temp;
}
queue *newQueue() 
{
    queue *q = malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(queue *q, bt_node *actual)
{
    ll_node *temp = newnode(actual);

    if(q->rear == NULL)
    {
        q->rear = q->front = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;

}
void dequeue(queue *q)
{
    if(q->front == NULL)
    {
        return;
    }

    ll_node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
}
bool isempty(queue *q)
{
    if(q->front == NULL)
        return true;
    else
        return false;
}
int isEmpty(queue *q) {

    // queue is empty if there's no front or rear nodes
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    }

    return 0;
}
void Level_Order_Traversal(bt_node *root)
{
    if(root == NULL)
    {
        return;
    }
    queue *q = newQueue(); // create the queue abstractly
    enqueue(q,root);
    while(isEmpty(q) == 0)
    {
        ll_node *temp = q->front;
        printf("%d\n", temp->added_node->value);
        dequeue(q);
        if(temp->added_node->left != NULL)
        {
            enqueue(q,temp->added_node->left);
        }
        if(temp->added_node->right != NULL)
        {
            enqueue(q,temp->added_node->right);
        }
    }

}
int main(int argc, char const *argv[])
{
    bt_node *root = NULL;
    root = new_tree(root,1);
    root = new_tree(root,2);
    root = new_tree(root,-4);
    root = new_tree(root,10);
    root = new_tree(root,-10);
    Level_Order_Traversal(root);

    return 0;
}
