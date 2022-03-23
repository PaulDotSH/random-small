#include "stdlib.h"
#include <stdio.h>
#include "string.h"

typedef struct item {
    char caracter;
    int grad;
} item;

typedef struct node {
    item val;
    struct node* next;
} node;

typedef struct Stack {
    node* top;
} Stack;

node* CreateNode(item val) {
    node* n = malloc(sizeof(node));
    n->val=val;
    n->next=NULL;
    return n;
}

void print(Stack* s) {
    node* n=s->top;
    while (n!=NULL) {
        printf("%d\n",n->val.caracter);
        n=n->next;
    }
}

void push(Stack* s, item val) {
    node* n = CreateNode(val);
    if (s->top==NULL) {
        s->top=n;
        return;
    }

    n->next=s->top;
    s->top=n;
}

item top(Stack* s) {
    node* n = s->top;
    if (n==NULL) {
        item itm;
        itm.grad = -999;
        itm.caracter = 0;
        return itm;
    }
    while (n->next!=NULL) n=n->next;
    return n->val;
}

item pop(Stack* s) {
    node* n = s->top;
    s->top=s->top->next;
    item v=n->val;
    free(n);
    return v;
}

int Size(Stack* s) {
    int i=0;
    node* n=s->top;
    while (n!=NULL) n=n->next,i++;
    return i;
}

Stack create_stack() {
    Stack s;
    s.top=NULL;
    return s;
}

//cand vezi ( adaugi la gradul global 10
//scoatem din stiva cand el nou e <= decat cel din spate

#define STR_SIZE 100

int getGradFromChar(char chr) {
    switch (chr) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default: return -1;
    }
}

int applyOperation(int val1, int val2, char chr) {
    switch (chr) {
        case '-':
            return val1-val2;
        case '+':
            return val1+val2;
        case '*':
            return val1*val2;
        case '/':
            return val1/val2;
        default: return -1;
    }
}

int main() {
    Stack s = create_stack();
    char* input = malloc(sizeof(char)*STR_SIZE);

    fgets(input,STR_SIZE,stdin);

    char* token = strtok(input, " \n");

    //buf e buffer pt expresia postfixata
    char* buf = malloc(sizeof(char)*STR_SIZE);
    int buf_iterator = 0;

    int gradMultiplier = 0;
    while (token != NULL) {
        //printf("%s",token);
        if (token[0] == '(') {
            gradMultiplier += 10;
            token = strtok(NULL, " \n");
            continue;
        }
        if (token[0] == ')') {
            gradMultiplier -= 10;
            token = strtok(NULL, " \n");
            continue;
        }

        //daca e numar il bagam direct in expresie
        if (strchr("0123456789",token[0])) {
            buf[buf_iterator++]=token[0];
        } else {
            item itm;
            itm.caracter = token[0];
            itm.grad = gradMultiplier + getGradFromChar(token[0]);

            if (Size(&s)==0) {
                push(&s,itm);
            } else {
                while (itm.grad <= top(&s).grad) {
                    buf[buf_iterator++] = pop(&s).caracter;
                }
                push(&s,itm);
            }
        }
        token = strtok(NULL, " \n");
    }

    while (Size(&s)>0)
        buf[buf_iterator++]=pop(&s).caracter;

    Stack nr_stack = create_stack();

    for (int i=0; i<buf_iterator; i++) {
        if (strchr("0123456789",buf[i])) {
            item itm;
            itm.caracter = 0;
            itm.grad = buf[i]-'0';
            push(&nr_stack,itm);
        } else {
            int val2 = pop(&nr_stack).grad;
            int val1 = pop(&nr_stack).grad;
            item tmp;
            tmp.grad = applyOperation(val1,val2,buf[i]);
            tmp.caracter = 0;
            push(&nr_stack,tmp);
        }
    }

    printf("%d",pop(&nr_stack).grad);
}

 
