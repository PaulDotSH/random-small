#include "stdio.h"
#include "stdlib.h"

typedef struct node node;
struct node {
    node* left;
    //node* parrent;
    node* right;
    int key;
};

typedef struct tree tree;
struct tree {
    node* root;
};

tree* create_tree() {
    tree* t = malloc(sizeof(tree));
    t->root = NULL;
    return t;
}

node* create_node(int val) {
    node* n = malloc(sizeof(node));
    n->left = NULL;
    //n->parrent = NULL;
    n->right = NULL;
    n->key = val;
    return n;
}

/*
void insert(tree* t, node* n) {
    if (t->root==NULL) {
        t->root=n;
        return;
    }

    node* prev = NULL;
    node* tmp = t->root;

    int l=0;

    while (tmp!=NULL) {
        prev = tmp;
        if (n->key>tmp->key)
            tmp=tmp->right,l=0;
        else
            tmp=tmp->left,l=1;
    }

    if (l)
        prev->left = n;
    else
        prev->right = n;
}
*/


void insert(tree* t, int f) {
    node* n=create_node(f);
    if (t->root==NULL) {
        t->root=n;
        return;
    }

    node* prev = NULL;
    node* tmp = t->root;

    int l=0;

    while (tmp!=NULL) {
        prev = tmp;
        if (n->key>tmp->key)
            tmp=tmp->right,l=0;
        else
            tmp=tmp->left,l=1;
    }

    if (l)
        prev->left = n;
    else
        prev->right = n;
}
