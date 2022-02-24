#include <stdio.h>
#include <stdlib.h>

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

int findKthFromEnd(list* l, int k, int* index) {
    int len = getListLength(l);
    node* tmp = l->head;
    int i=0;
    while (i++!=len-k) {
        tmp=tmp->next;
    }
    *index = i-1;
    return tmp->val;
}

int findKthFromStart(list* l, int k) {
    int i=0;
    k--;
    node* n = l->head;
    while (n!=NULL) {
        if (i==k) {
            return n->val;
        }
        i++;
        n=n->next;
    }
    return -1;
}

void setIndex(list *l, int index, int val) {
    node* n = l->head;
    while (--index) {
        n=n->next;
    }
    n->val=val;
    //printf("index %d val %d\n", index,val);
}

void swapk(list *l, int index) {
    int* lastIndex = malloc(sizeof(int));
    int last = findKthFromEnd(l,index, lastIndex);
    int first = findKthFromStart(l,index);

    //printf("%d %d\n",first,index);
    //printf("%d %d\n",last,*lastIndex);

    setIndex(l,index,last);
    setIndex(l,*lastIndex+1,first);
    free(lastIndex);
}

list l1, l2, l3;
int main(){
    int n,k,aux;
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%d",&aux);
        append(&l,aux);
    }
    //print(l);
    swapk(&l,k);
    print(l);
} 
