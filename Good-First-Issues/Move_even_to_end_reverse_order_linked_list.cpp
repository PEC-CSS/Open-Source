#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        next=NULL;
    }

};

void CreateNode(node* &head, node* &tail, int data){
    if(head==NULL){
        tail = new node(data);
        head=tail;
        return;
    }
    tail->next = new node(data);
    tail=tail->next;
    return ;
}

void printList(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"\n";
}

void changeOrder(node* odd){
    node* curr=odd;
    node* prev=NULL;
    node* lastOdd=NULL;
    node* temp;
    int n=0;
    while(curr && ++n){
        temp = curr->next;
        if(n&1){
            if(temp){
                curr->next=curr->next->next;
            }
            lastOdd=curr;
        }
        else{
            curr->next=prev;
            prev=curr;
        }
        curr=temp;
    }
    lastOdd->next=prev;
}

int main(){
    cout<<"Enter Number of Nodes: ";
    int n;
    cin>>n;
    node* head=NULL;
    node* tail=NULL;
    int data;
    cout<<"Enter value of nodes:\n";
    for(int i=0;i<n;i++){
        cin>>data;
        CreateNode(head, tail, data);
    }
    // printList(head);
    changeOrder(head);
    printList(head);
}
