#include "stdio.h"
#include "stdlib.h"

typedef struct node node;
struct node {
    node* left;
    node* right;
    int key;
};

typedef struct tree tree;
struct tree {
    node* root;
};
