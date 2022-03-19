#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int* v;
    int varfPos;
    int limit;
} Stack;

Stack create_stack(int limit){
    Stack s;
    s.v = malloc(sizeof(int)*limit);
    s.varfPos = 0;
    s.limit = limit;
    return s;
}

void push(Stack *s, int x){
    if (s->varfPos+1 > s->limit) {
        printf("Limit exceeded\n");
        return;
    }
    s->v[s->varfPos]=x;
    s->varfPos++;
}
int pop(Stack *s){
    s->varfPos--;
    return s->v[s->varfPos+1];
}
void print(Stack *s){
    for (int i=s->varfPos-1; i>-1; i--) {
        printf("%d\n",s->v[i]);
    }
}
 
