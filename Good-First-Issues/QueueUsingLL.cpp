#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node(int x)
    {
        this->data=x;
    }   
    Node* next;
}*front,*rear;

int sizecount=0;

void enqueue(int x)
{
    Node* newnode=new Node(x);

    if(front==nullptr)
    {
        front=rear=newnode;     
        rear->next=nullptr;   
    }
    //Starting form empty queue
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=nullptr;
    }
    ::sizecount++;
}

void dequeue()
{
    if(front==nullptr)
    {
    cout<<"Underflow\n";
    return;
    }
    //Empty Queue
    else if(front==rear)
    {
        front=rear=nullptr;
        ::sizecount--;
    } 
    //Single Element in Queue
    else
    {
        Node* save=front;
        front=front->next;
        delete save;
        ::sizecount--;
    }
}

int size()
{
    return ::sizecount;
}

int main()
{
    front=nullptr;
    rear=nullptr;
    //initializing front and rear pounter as null
    
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();

    cout<<size();
    
}



