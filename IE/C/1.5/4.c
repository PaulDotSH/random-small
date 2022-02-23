// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int val;
//     struct node *next;
// };

// struct list{
//     struct node *first;
//     struct node *last;
//     int size;
// };

struct node *make_node(int v) {
    struct node *n = malloc(sizeof(struct node));
    n->val = v;
    n->next = NULL;
    return n;
}

struct list make_list() {
    struct list l = {NULL, NULL, 0};
    return l;
}

void append(struct list *l, int v) {
    struct node *n = make_node(v);
    if (l->first == NULL) {
        l->first = n;
        l->last = n;
    } else {
        l->last->next = n;
        l->last = n;
    }
    l->size++;
}

void display(struct list l) {
    struct node *n = l.first;
    while (n != NULL) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

// int main(){
//     int n;
//     scanf("%d", &n);
//     struct list l = make_list();
//     while(n != 0){
//         append(&l, n);
//         scanf("%d", &n);
//     }
//     printf("%d\n", l.size);
//     display(l);
// }
