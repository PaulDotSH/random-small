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
    int i=0;
    while(i++<4)
    {
        printf("%d ",l.head->val);
        l.head=l.head->next;
    }
} 
