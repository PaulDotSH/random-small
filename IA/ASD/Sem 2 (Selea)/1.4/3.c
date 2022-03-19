#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int rear; //index
    int front; //tot index
    int* v;
    int limit;
} Queue;

Queue create_queue(int limit) {
    Queue q;
    q.front = 0;
    q.rear = 0;
    q.limit = limit;
    q.v = malloc(sizeof(int)*limit);
    return q;
}

void enqueue(Queue *q, int x) {
    if (q->front > q->limit-1) {
        printf("Limit exceeded\n");
        return;
    }
    q->v[q->front] = x;
    q->front++;
}

int dequeue(Queue *q) {
    q->rear++;
    return q->v[q->rear-1];
}

void print(Queue *q) {
    for (int i=q->rear; i<q->front; i++) {
        printf("%d\n",q->v[i]);
    }
}

 
