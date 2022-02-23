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
        printf("%d",curr->val);
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

int findKthFromEnd(int k, list l) {
    int len = getListLength(&l);
    node* tmp = l.head;
    int i=0;
    while (i++!=len-k) {
        tmp=tmp->next;
    }
    return tmp->val;
}

void reverse(list *li) {
    node* prev = NULL;
    node* current = li->head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    li->head = prev;
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

void add(list* dest, list* l1, list* l2) {
    int carry = 0;
    node* n1 = l1->head;
    node* n2 = l2->head;

    if (getListLength(l1) > getListLength(l2)) {
        node* tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    while (n1!=NULL) {
        int tmp = n1->val+n2->val+carry;
        if (tmp>9)
        {
            carry=tmp-9;
            append(dest,9);
        } else append(dest,tmp);

        n1=n1->next;
        n2=n2->next;
    }

    while (n2!=NULL) {
        int tmp =n2->val+carry;
        if (tmp>9)
        {
            carry=tmp-9;
            append(dest,9);
        } else append(dest,tmp);

        n2=n2->next;
    }

    while (carry) {
        if (carry>9)
        {
            append(dest,9);
            carry-=9;
        } else append(dest,carry);
    }
}

list l1, l2, l3;
int main(){
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);

    while (x) {
        append(&l1, x%10);
        x/=10;
    }
    while(y){
        append(&l2, y%10);
        y/=10;
    }

//    print(l1);
//    print(l2);
    add(&l3,&l1,&l2);
    reverse(&l3);
    print(l3);
} 
