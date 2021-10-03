#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* createBinaryTree() {
    int x;
    cin>>x;
    if(x==-1) {
        return NULL;
    }
    Node* root = new Node(x);
    root->left = createBinaryTree();
    root->right = createBinaryTree();
    return root;
}

Node* MirrorTree(Node *tree){
    if(tree ==NULL) {
        return NULL;
    }
    tree->left = MirrorTree(tree->left);
    tree->right = MirrorTree(tree->right);
    swap(tree->left,tree->right);
    return tree;
}

void printTree(Node* root) {
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    cout<<"Input tree\n";
    cout<<"-1 indicates that you want to enter null\n";

// input both trees
    Node* tree = createBinaryTree();

// printing trees
    cout<<"PreOrder of original Tree: ";
    printTree(tree);
    cout<<"\n";

    Node* mirrored = MirrorTree(tree);

    cout<<"PreOrder of Mirrored Tree: ";
    printTree(mirrored);
}


// g++ Mirror_binary_tree.cpp -o Mirror_binary_tree
// ./Mirror_binary_tree.exe

// sample ip: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// op :
// PreOrder of original Tree: 1 2 4 5 3 6 7
// PreOrder of Mirrored Tree: 1 3 7 6 2 5 4