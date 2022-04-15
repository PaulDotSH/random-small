#include "stdio.h"
#include "stdlib.h"

typedef struct node node;
struct node {
    node* left;
    node* parrent;
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
    n->parrent = NULL;
    n->right = NULL;
    n->key = val;
    return n;
}

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
    n->parrent = prev;
    if (l)
        prev->left = n;
    else
        prev->right = n;
}

node* actual_search(node* n, int val) {
    //cautare binara
    if (n==NULL || val == n->key)
        return n;

    if (val < n->key)
        return actual_search(n->left,val);
    return actual_search(n->right,val);
}

node* search(tree t, int val) {
    return actual_search(t.root,val);
}

void preorder_node(node* n) {
    if (n==NULL) return;
    printf("%d ",n->key);
    preorder_node(n->left);
    preorder_node(n->right);
}

//RADACINA STANGA DREAPTA
void preorder(tree a){
    preorder_node(a.root);
}

void inorder_node(node* n) {
    if (n==NULL) return;
    inorder_node(n->left);
    printf("%d ",n->key);
    inorder_node(n->right);
}

//STANGA DREAPTA RADACINA
void inorder(tree a){
    inorder_node(a.root);
}

void postorder_node(node* n) {
    if (n==NULL) return;
    postorder_node(n->left);
    postorder_node(n->right);
    printf("%d ",n->key);
}

//STANGA RADACINA DREAPTA
void postorder(tree a){
    postorder_node(a.root);
}

void transplant(tree* T, node* u, node* v) {
    if (u->parrent == NULL)
        T->root = v;
    else if (u == u->parrent->left) {
        u->parrent->left = v;
    } else {
        u->parrent->right = v;
    }

    if (v!=NULL) v->parrent = u->parrent;
}

node* tree_minimum(node* n) {
    if (n->left != NULL) return n->left;
    return n;
}

void tree_delete(tree* T, node* z) {
    if (z->left == NULL) transplant(T,z,z->right);
    else if (z->right == NULL) transplant(T,z,z->left);
    else {
        node* y = tree_minimum(z->right);
        if (y->parrent!=z) {
            transplant(T,y,y->right);
            y->right = z->right;
            y->right->parrent = y;
        }
        transplant(T,z,y);
        y->left = z->left;
        y->left->parrent = y;
    }
}

void delete(tree* a, int v) {
    tree_delete(a, search(*a,v));
}
