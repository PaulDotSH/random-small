#include <stdio.h>
#include <stdlib.h>
//#define NULL 0

typedef struct node {
    int val;
    struct node* next;
} Node;
typedef struct queue {
    Node* start;
} Queue;

Queue create_queue(){
    Queue q;
    q.start=NULL;
    return q;
}

Node* create_node(int v) {
    Node* n = malloc(sizeof(Node));
    n->val=v;
    n->next=NULL;
    return n;
}

void enqueue(Queue *q, int x){
    Node* n = create_node(x);
    if (q->start==NULL) {
        q->start = n;
        return;
    }
    Node* tmp = q->start;
    while (tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=n;
}
int dequeue(Queue *q){
    if (q->start==NULL ) return -1;
    Node* n = q->start;
    q->start=q->start->next;
    int v=n->val;
    free(n);
    return v;
}
void print(Queue *q){
    Node* n = q->start;
    while (n!=NULL)
    {
        printf("%d\n",n->val);
        n=n->next;
    }
}

int front(Queue* q) {
    return q->start!=NULL ? q->start->val : -1;
}

int queuesize(Queue* q) {
    Node* n=q->start;
    int i=0;
    while (n!=NULL) n=n->next,i++;
    return i;
}
