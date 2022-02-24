#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Product {
    int code, quantity;
    float price;
    char* name;
    char* recDate;
    char* expDate;
} Product;

typedef struct Node
{
    struct Product val;
    struct Node* next;
} Node;

typedef struct list
{
    Node *head;
} List;

void printNode(Node* n) {
    printf("%d %s %0.1f %d %s %s\n",n->val.code,n->val.name,n->val.price,n->val.quantity,n->val.recDate,n->val.expDate);
}

void print(List l)
{
    Node* curr = l.head;
    while(curr!=NULL)
    {
        printNode(curr);
        curr=curr->next;
    }
}
List l;

Node* createProduct(int _code, char* _name, float _price, int _quantity, char* _recDate, char* _expDate)
{
    Node* product = malloc(sizeof(Node));

    product->val.code=_code;
    product->val.name= malloc(sizeof(char)*50);
    strcpy(product->val.name,_name);
    product->val.price=_price;
    product->val.quantity=_quantity;
    product->val.recDate= malloc(sizeof(char)*50);
    strcpy(product->val.recDate,_recDate);
    product->val.expDate= malloc(sizeof(char)*50);
    strcpy(product->val.expDate,_expDate);
    return product;
}

void appendSorted(List* l, Node* n) {
    if (l->head==NULL) {
        l->head=n;
        return;
    }

    Node* current = l->head;
    Node* previous = NULL;
    while(current!=NULL)
    {
        if (current->val.price>n->val.price) {
            if (previous==NULL) {
                l->head=n;
                n->next=current;
                return;
            }
            previous->next=n;
            n->next=current;
            return;
        }
        previous=current;
        current=current->next;
    }

    previous->next=n;
}

Node* findByCode(List l, int code) {
    Node* current = l.head;
    while (current!=NULL) {
        if (code==current->val.code) return current;
        current=current->next;
    }
    return NULL;
}

int dmyToUnix(int d, int m, int y) {
    struct tm t;
    time_t time;

    t.tm_year = y;
    t.tm_mon = m;
    t.tm_mday = d;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;
    time = mktime(&t);
    return (int)time;
}

int isNewer(char* date1, char* date2) {
    int day1,mo1,yr1,day2,mo2,yr2;
    sscanf(date1, "%d/%d/%d", &day1, &mo1, &yr1);
    sscanf(date2, "%d/%d/%d", &day2, &mo2, &yr2);

    return dmyToUnix(day1,mo1,yr1) > dmyToUnix(day2,mo2,yr2);
}

int isOlder(char* date1, char* date2) {
    return !isNewer(date1,date2);
}

void printValid(List l, char* date) {
    Node* current = l.head;

    while (current!=NULL) {
        if (isOlder(current->val.expDate,date)) {
            current=current->next;
            continue;
        }
        printNode(current);
        current=current->next;
    }
}

void printExpired(List l, char* date) {
    Node* current = l.head;

    while (current!=NULL) {
        if (isNewer(current->val.expDate,date)) {
            current=current->next;
            continue;
        }
        printNode(current);
        current=current->next;
    }
}

void deleteByCode(List* l, int code) {
    Node* current = l->head;
    Node* previous = NULL;

    while (current!=NULL) {
        if (current->val.code==code) {
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

void deleteExpired(List *l, char *date) {
    Node* curr = l->head;
    while (curr!=NULL) {
        if (isOlder(curr->val.expDate,date))
            deleteByCode(l,curr->val.code);
        curr=curr->next;
    }
} 
