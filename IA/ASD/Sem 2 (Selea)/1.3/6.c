#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

typedef struct Stack {
    node* top;
} Stack;

node* CreateNode(int val) {
    node* n = malloc(sizeof(node));
    n->val=val;
    n->next=NULL;
    return n;
}

void print(Stack* s) {
    node* n=s->top;
    while (n!=NULL) {
        printf("%d\n",n->val);
        n=n->next;
    }
}

void push(Stack* s, int val) {
    node* n = CreateNode(val);
    if (s->top==NULL) {
        s->top=n;
        return;
    }

    n->next=s->top;
    s->top=n;
}

int top(Stack* s) {
    node* n = s->top;
    if (s->top==NULL) return -1;
    while (n->next!=NULL) n=n->next;
    return n->val;
}

int pop(Stack* s) {
    if (s->top==NULL ) return -1;

    node* n = s->top;
    s->top=s->top->next;
    int v=n->val;
    free(n);
    return v;
}

int Size(Stack* s) {
    int i=0;
    node* n=s->top;
    while (n!=NULL) n=n->next,i++;
    return i;
}

/* dintr-un motiv pe care ni-l putem doar imagina, in unele ex facem noi main-ul iar in altele suntem
obligati sa folosim un main gata facut
Stack* create_stack() {
    Stack* s = malloc(sizeof(Stack));
    s->top=NULL;
    return s;
}
*/

Stack create_stack() {
    Stack s;
    s.top=NULL;
    return s;
}
