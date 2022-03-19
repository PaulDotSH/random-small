#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct mesaj mesaj;
struct mesaj {
    char prioritate;
    char* destinatar;
    char* continut;
};

typedef struct node node;
struct node {
    mesaj* val;
    node* next;
};

typedef struct cutiePostala cutiePostala;
struct cutiePostala {
    node* inceput;
};

cutiePostala create_cutiePostala() {
    cutiePostala c;
    c.inceput = NULL;
    return c;
}

mesaj* create_mesaj(char prioritate, char destinatar[], char continut[]) {
    mesaj* msg = malloc(sizeof(mesaj));
    msg->prioritate=prioritate;
    strcpy(msg->continut,continut);
    strcpy(msg->destinatar,destinatar);
    return msg;
}

node* create_node(mesaj* mesaj) {
    node* n = malloc(sizeof(node));
    n->next = NULL;
    n->val = mesaj;
}

void primire_mesaj(cutiePostala* c, char destinatar[]) {
    node* n = c->inceput;
    if (strcmp(n->val->destinatar,destinatar)==0) {
        c->inceput=NULL;
        free(n->val);
        free(n);
        return;
    }
    while (n->next!=NULL) {
        if (strcmp(n->next->val->destinatar,destinatar)==0) {
            n->next=n->next->next;
            free(n->next->val);
            free(n->next);
        }
        n=n->next;
    }
}

void trimitere_mesaj(cutiePostala* c, char prioritate, char destinatar[], char continut[]) {
    //inserare la inceput, daca mesajul e prioritar
    if (prioritate) {
        node* n = create_node(create_mesaj(prioritate,destinatar,continut));
        n->next=c->inceput;
        c->inceput=n;
        return;
    }

    node* n = c->inceput;
    if (n->next==NULL) {
        //daca nodul din queue are prioritate, introducem mesajul dupa
        if (n->val->prioritate) {
            n->next = create_node(create_mesaj(prioritate,destinatar,continut));
            return;
        }
        if (strcmp(destinatar,n->val->destinatar)<0) {
            node* tmp = create_node(create_mesaj(prioritate,destinatar,continut));
            tmp->next = c->inceput;
            c->inceput = tmp;
        } else {
            n->next = create_node(create_mesaj(prioritate,destinatar,continut));
        }
        return;
    }

    while (n->next!=NULL) {
        if (strcmp(destinatar,n->val->destinatar)<0 && strcmp(destinatar,n->next->val->destinatar)>0) {
            //insert dupa n
            node* tmp =  create_node(create_mesaj(prioritate,destinatar,continut));
            tmp->next = n->next;
            n->next=tmp;
            return;
        }
        n=n->next;
    }
    //in cazul in care e la final
    n->next = create_node(create_mesaj(prioritate,destinatar,continut));
}

void afisare(cutiePostala* c) {
    node* n = c->inceput;
    while (n!=NULL) {
        if (n->val->prioritate==0) printf("%s %s",n->val->destinatar,n->val->continut);
        n=n->next;
    }
}

int main() {
    cutiePostala cutie = create_cutiePostala();
} 
