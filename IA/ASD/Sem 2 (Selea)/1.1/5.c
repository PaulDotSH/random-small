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
