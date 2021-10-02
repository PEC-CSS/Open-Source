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

bool helper(Node* root,int lower,int upper) {
    if(root==NULL) {
        return true;
    }
    bool check1 = root->data<= upper && root->data >= lower;
    bool check2 = helper(root->left,lower,root->data-1);
    bool check3 = helper(root->right,root->data,upper);

    return check1 && check2 && check3;
}

bool isBST(Node* root) {
    return helper(root,INT_MIN,INT_MAX);
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

// input  tree
    Node* tree = createBinaryTree();

// printing tree
    cout<<"PreOrder of original Tree: ";
    printTree(tree);
    cout<<"\n";

    bool ans = isBST(tree);
    if(ans) {
        cout<<"Yes, its a BST";
    } else {
        cout<<"Not a BST";
    }

}

//  g++ Check_for_BST.cpp -o Check_for_BST
// ./Check_for_BST.exe