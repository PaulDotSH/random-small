#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produs {
    int code;
} Produs;

typedef struct node {
    Produs* prod;
    struct node* next;
    struct node* back;
} Node;
typedef struct list {
    Node* head;
} List;

List create_list(){
    List l;
    l.head=NULL;
    return l;
}

Node* create_node(Produs* produs) {
    Node* n = malloc(sizeof(Node));
    n->prod=produs;
    n->next=NULL;
    n->back=NULL;
    return n;
}

Produs* create_produs(int cod) {
    Produs* p = malloc(sizeof(Produs));
    p->code = cod;
    return p;
}

void print_list(List *l){
    Node* n = l->head;
    while (n!=NULL)
    {
        printf("%d\n",n->prod->code);
        n=n->next;
    }
}

void append_list(List* l, Node* n) {
    if (l->head==NULL) {
       l->head=n;
        return;
    }
    Node* tmp = l->head;
    while (tmp->next!=NULL) {
        tmp=tmp->next;
    }
    tmp->next = n;
    n->back = tmp;
}

void delete_index(List* l, int index) {
    Node* n = l->head;
    if (index==0) l->head=n->next;
    while (index-- && n->next!=NULL) {
        n=n->next;
    }
    if (n->back!=NULL)
        n->back->next=n->next;
    if (n->next!=NULL)
        n->next->back=n->back;
    //printf("%d\n",n->prod->code);
    free(n);
}

void delete_product(List* l, Produs* produs) {
    Node* n = l->head;
    int index=0;
    while (n->next!=NULL) {
        if (n->prod==produs) {
            delete_index(l,index);
            return;
        }
        n=n->next;
        index++;
    }
}

void prepend_list(List* l, Node* n) {
    Node* tmp = l->head;
    l->head = n;
    n->next = tmp;
    tmp->back = n;
}

void insert_before_product(List* l, Produs* product, Node* insert) {
    Node* n = l->head;
    while (n->prod!=product) {
        if (n==NULL) return;
        n=n->next;
    }

    insert->next = n;
    insert->back = n->back;
    if (n->back!=NULL)
        n->back->next = insert;
    n->back = insert;

    if (n==l->head)
        l->head=insert;
}

void insert_after_product(List* l, Produs* product, Node* insert) {
    Node* n = l->head;
    while (n->prod!=product) {
        if (n==NULL) return;
        n=n->next;
    }

    insert->next=n->next;
    n->next=insert;
    insert->back=n;
}

int main() {
    return 0;
    
    int n,x;
    scanf("%d",&n);
    List l = create_list();
    for (int i=0; i<n; i++) {
        scanf("%d",&x);
        Produs* p = create_produs(x);
        Node* node = create_node(p);
        append_list(&l, node);
    }
    Produs* NOUA = create_produs(9);
    prepend_list(&l, create_node(NOUA));
    print_list(&l);
    printf("\n\n\n");
    //delete_index(&l,0);
    delete_product(&l,NOUA);
    printf("\n\n\n");
    print_list(&l);
    printf("\n\n\n");

    prepend_list(&l,create_node(NOUA));
    //prepend_list(&l,create_node(create_produs(6)));
    //insert_after_product(&l,NOUA, create_node(create_produs(-1)));
    insert_before_product(&l,NOUA, create_node(create_produs(-1)));
    print_list(&l);
} 
