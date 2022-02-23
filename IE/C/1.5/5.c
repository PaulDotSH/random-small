struct node *make_node(void *v, void* (*pfun)(void *)) {
    struct node *n = malloc(sizeof(struct node));
    n->val = pfun(v);
    n->next = NULL;
    return n;
}

struct list make_list() {
    struct list l;
    l.size = 0;
    l.first = NULL;
    l.last = NULL;
    return l;
}

void append(struct list *l, void *v, void* (*pfun)(void *)) {
    struct node *n = make_node(v, pfun);
    if (l->size == 0) {
        l->first = n;
        l->last = n;
    } else {
        l->last->next = n;
        l->last = n;
    }
    l->size++;
}

void display(struct list l, void (*pfun)(void *)) {
    struct node *n = l.first;
    while (n != NULL) {
        pfun(n->val);
        n = n->next;
    }
}

void * copy_person(void * p) {
    struct person *p1 = (struct person *) p;
    struct person *p2 = malloc(sizeof(struct person));
    *p2 = make_person(p1->name, p1->age);
    return p2;
}

void display_person(void * p) {
    struct person *p1 = (struct person *) p;
    printf("%s %d\n", p1->name, p1->age);
}