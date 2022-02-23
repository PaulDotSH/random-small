#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
} node;

typedef struct list
{
    node *head;
} list;

void print(list l)
{
    while(l.head!=NULL)
    {
        printf("%d ",l.head->val);
        l.head=l.head->next;
    }
}
list l;

void append(list *l, int k)
{
    if (l->head==NULL) {
        l->head=malloc(sizeof(node));
        l->head->val=k;
        return;
    }

    node* tmp = l->head;
    node* prv = NULL;
    while(tmp!=NULL)
    {
        prv=tmp;
        tmp=tmp->next;
    }
    tmp=malloc(sizeof(node));
    tmp->val=k;
    tmp->next=NULL;
    prv->next=tmp;
}

int getListLength(list* l) {
    int i=0;
    node* tmp = l->head;
    while (tmp!=NULL) i++,tmp=tmp->next;
    return i;
}

int findKthFromEnd(int k, list l) {
    int len = getListLength(&l);
    node* tmp = l.head;
    int i=0;
    while (i++!=len-k) {
        tmp=tmp->next;
    }
    return tmp->val;
} 
