#include <stdlib.h>
#include <stdio.h>
#define SIZE 3
typedef struct q q;

void print(q *main);
int dequeue(q *main);
void enqueue(q *main, int value);
q *create_q(unsigned size);
