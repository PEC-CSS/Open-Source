#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class Node
{
    public:
    T data;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(T x)
    {
        this->data=x;
    }
    
};
//defining a node class

Node<int>* takeinput(int d)
{
    
    queue<Node<int>*> pending_nodes;

    if(d==-1)
    return nullptr;

    Node<int>* root=new Node<int>(d);
    pending_nodes.push(root);
    //push the very first node,i.e, the root node into the queue

    while(!pending_nodes.empty()) //loop to do task until queue is empty
    {
        int x;
        Node<int>* temp=pending_nodes.front();
        //create a temporary node to store the front of the queue in it.

        cout<<"Enter Left Child of "<<temp->data<<":\n";
        cin>>x;
        //input the value for left child 
        if(x!=-1)
        {
        Node<int>* leftc=new Node<int>(x);
        //create a left child node with the input value
        temp->left=(leftc);
        //link the child with the parent by setting it as the left child of parent
        pending_nodes.push(leftc);
        //push the child into the queue
        }

        cout<<"Enter Right Child of "<<temp->data<<":\n";
        cin>>x;
        //input the value for right child 
        if(x!=-1)
        {
        Node<int>* rightc=new Node<int>(x);
        //create a right child with the input value
        temp->right=rightc;
        //link the child with the parent by setting it as the left child of parent
        pending_nodes.push(rightc);
        //push the child into the queue
        }

        pending_nodes.pop();
        //pop the front element form the queue

    }
    
return root;
}


void displayPreorder(Node<int>* root)
{
    if(root==nullptr)
    return;
    //base case

    cout<<root->data<<" ";
    //print root
    displayPreorder(root->left);
    //recursively print the left subtree
    displayPreorder(root->right);
    //recursively print the right subtree
}


int main()
{
    cout<<"Enter Root Value of BT: \n";
    int y;
    cin>>y;

    Node<int>* a=takeinput(y);
    //level wise input for the binary tree 

    cout<<"Preorder: ";
    displayPreorder(a);
    //printing the binary tree in preorder format


}