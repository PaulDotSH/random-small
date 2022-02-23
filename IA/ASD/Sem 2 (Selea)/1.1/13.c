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
    node* curr = l.head;
    while(curr!=NULL)
    {
        printf("%d ",curr->val);
        curr=curr->next;
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

void merge(list *dest, list *l1, list *l2)
{
    node* n1 = l1->head;
    node* n2 = l2->head;

    while (n1!=NULL && n2!=NULL)
    {
        if (n1->val<n2->val)
        {
            append(dest,n1->val);
            n1=n1->next;
        } else {
            append(dest,n2->val);
            n2=n2->next;
        }
    }
    if (n1==NULL)
        n1=n2;
    while(n1!=NULL) {
        append(dest,n1->val);
        n1=n1->next;
    }
} 
