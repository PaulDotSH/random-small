#include <stdlib.h>
#include <stdio.h>
typedef struct list
{
    struct node *head;
    struct node *foot;
    int length;
} list;

typedef struct node
{
    int val;
    struct node *next;
} node;

void print(list l)
{
    node *first = l.head;
    printf("%d %d", first->val, first->next->val);
}

void printList(list l){
    node *current= l.head;
    do{
        printf("%d ",current->val);
        current=current->next;
    }while(current!= l.head);
    printf("\n");
}
void append(list *l, int k)
{
    node *NewEl = (node *)malloc(sizeof(node));
    NewEl->next = l->head;
    NewEl->val = k;

    if (l->head == NULL)
    {
        l->head = NewEl;
        l->foot = NewEl;
    }
    else
    {
        node *lfoot = l->foot;
        lfoot->next = NewEl;
        l->foot = NewEl;
    }
    l->length++;
}

void SingingChairs(list *l, int k)
{
    int i = 1, listLength = l->length;
    node *current = l->head;
   // printf("#%d\n", k);
    do
    {
        if ((i+1) % k == 0)
        {
            if(current->next == l->head)
                    l->head=current->next->next; 
            current->next = current->next->next;
            listLength--;
            i++;
        }
        i++;
        current=current->next;
    //   printList(*l);
    } while (listLength > 2);
}

list l;
int main()
{
    int n, k, i;
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++)
        append(&l, i);
    SingingChairs(&l, k);
    print(l);
}