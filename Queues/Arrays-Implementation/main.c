#include "main.h"

int main(int argc, char const *argv[])
{
    q *new_q = create_q(SIZE);
    enqueue(new_q,1);
    enqueue(new_q,2);
    enqueue(new_q,3);
    print(new_q);
    return 0;
}
struct q
{
    int rear, front;
    unsigned size;
    int *array;
};
q *create_q(unsigned size)
{
    q *new_q = malloc(sizeof(q));
    new_q->front = -1;
    new_q->rear = -1;
    new_q->size = size;
    new_q->array = malloc(sizeof(int) * size);
    return new_q;
}
void enqueue(q *main, int value)
{
    if((main->rear +1) == main->size)
    {
        printf("Overflowed\n");
        return;
    }
    if(main->rear == -1 && main->front == -1)
    {
        main->rear = 0;
        main->front = 0;
        // printf("test");
    }
    else
    {
        (main->rear)++;
    }
    main->array[main->rear] = value;
}
int dequeue(q *main)
{
    if(main->front  == main->size || main->front == -1)
        return -1;
    int value = main->array[main->front];
    (main->front)++;
    return value;
}
void print(q *main)
{
    for(int i = 0 ; i < SIZE ; i++)
    {
        printf("Element %d : %d\n", i, dequeue(main));
    }

}