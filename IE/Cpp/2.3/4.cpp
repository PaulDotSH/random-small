 
#include <iostream>

class Node {
public:
    Node* right;
    Node* left;
    int value;
    Node(int);
};

class Tree {  
public:
    Node* root;
    void inorder() const;
    void insert(int);
    void inorderaux(Node*) const;
    Node* insertaux(Node*, int) const;
};

Node::Node(int val) {
    value = val;
    left = NULL;
    right = NULL;
}

Node* Tree::insertaux(Node* node, int data) const
{
    /* If the tree is empty,
       return a new node */
    if (node == NULL)
        return new Node(data);
 
    /* Otherwise, recur down the tree */
    if (data <= node->value)
        node->left = insertaux(node->left, data);
    else
        node->right = insertaux(node->right, data);
 
    /* return the (unchanged) node pointer */
    return node;
}

void Tree::insert(int val)
{
    insertaux(root, val);
}

void Tree::inorder() const
{
    inorderaux(root);
}

void Tree::inorderaux(Node* root) const
{
    if (root != NULL) {
        inorderaux(root->left);
        std::cout << root->value << " ";
        inorderaux(root->right);
    }
}
 

// Node* insert(Node* node, int value)
// {
//     /* If the tree is empty,
//        return a new node */
//     if (node == NULL)
//         return newNode(data);
//     /* Otherwise, recur down the tree */
//     if (data <= node->data)
//         node->left = insert(node->left, data);
//     else
//         node->right = insert(node->right, data);
//     /* return the (unchanged) node pointer */
//     return node;
// }


int main(){
    Tree t;
    int i, n;
    std::cin>>n;
    while(n > 0){
        std::cin >> i;
        t.insert(i);
        n--;
    }
    t.inorder();
}

