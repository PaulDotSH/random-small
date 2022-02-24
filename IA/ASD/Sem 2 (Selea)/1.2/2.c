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
    printf("\n");
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

void deleteNode(list* l, node* _node) {
    node* current = l->head;
    node* previous = NULL;

    while (current!=NULL) {
        if (current==_node) {
            if (previous!=NULL) {
                previous->next=current->next;
                free(current);
                return;
            }
            l->head=current->next;
            free(current);
        }
        previous=current;
        current=current->next;
    }
}

void removeDuplicates(list* l) {
    node* n = l->head;
    while (n!=NULL) {
        node* m = n->next;
        while (m!=NULL) {
            if (n->val==m->val) {
                node* tmp = m->next;
                deleteNode(l,m);
                m=tmp;
            } else m=m->next;
        }
        n=n->next;
    }
}

list l1, l2, l3;
int main(){
    int n,aux;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&aux);
        append(&l,aux);
    }
    //print(l);
    removeDuplicates(&l);
    print(l);
} 
