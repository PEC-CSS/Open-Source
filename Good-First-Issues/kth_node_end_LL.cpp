#include<iostream>
using namespace std;

// Node class
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next=NULL;
    }
};

// Add node at the end of linked list
void addNode(Node* &head, Node* &tail, int data){
    if(head==NULL){
        tail=new Node(data);
        head=tail;
        return;
    }
    tail->next = new Node(data);
    tail=tail->next;
    return;
}


int kthNodeEnd(Node *head, int k){
    if(k<=0)
        return -1;
    // count length of linked list
    int count=0;
    Node *temp = head;
    while(temp){
        count++;
        temp=temp->next;
    }
    // traverse till count-k and return the data of that node
    int x = count-k;
    int i=0;
    temp=head;
    while(i<x){
        temp=temp->next;
        i++;
    }
    return temp->data;
}


int main(){
    int n, k;
    // take n: numer of node and k: nodes to reverse in a group as input
    cin>>n>>k;
    Node* head=NULL;
    Node* tail=NULL;
    // input n elements denoting a linked list
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        addNode(head, tail, data);
    }
    cout<<kthNodeEnd(head, k)<<endl;
}