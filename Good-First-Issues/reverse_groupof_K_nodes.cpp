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


Node *kReverse(Node *head, int k){
    Node *curr=head;
    Node *prev=NULL;
    Node *temp;
    int count=0;
    while(curr && count<k){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        count++;
    }
    if(head){
        head->next=curr;
    }
    count=0;
    while(count<k-1 && curr){
        curr=curr->next;
        count++;
    }
    if(curr){
        curr->next = kReverse(curr->next, k);
    }
    return prev;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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
    head = kReverse(head, k);
    printList(head);
}