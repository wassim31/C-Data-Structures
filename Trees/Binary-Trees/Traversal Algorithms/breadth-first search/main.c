#include <stdlib.h>
#include <stdio.h>
#define ERROR -1101010
typedef struct node node;
struct node 
{
    int value;
    node *next;
};
typedef struct queue queue;
struct queue
{
    node *front;
    node *rear;
};
void enqueue(queue *q, int value)
{
    node *temp = malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    if(q->front == NULL)
    {
        q->front = q->rear = temp;
    }
    (q->rear)->next = temp;
    q->rear = temp;
}
queue *create()
{
    queue *new = malloc(sizeof(queue));
    new->front = new->rear = NULL;
    return new;
}
void print(queue *q)
{
    for(node *temp = NULL ; temp != q->front ; q->front = q->front->next)
    {
        printf("%d\n", q->front->value);
    }
}
int dequeue(queue *q)
{
    if(q->front == NULL && q->rear == NULL)
    {
        return ERROR;
    }
    int value = q->front->value;
    q->front = q->front->next;
    return value;
}
int main(int argc, char const *argv[])
{
    queue *q = create();
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,5);
    enqueue(q,6);
    printf("dequeued value : %d\n", dequeue(q));
    print(q);
    return 0;
}
