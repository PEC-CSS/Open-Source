#include<iostream>
#include<cstdio>
using namespace std;

class node
{
    public:
    int data;
    node* link=nullptr;
    node(int x)
    {
        this->data=x;
    }
};

void removeDuplicates(node* root)
{
    node*current=root;
    while(current)
    {
        if(current->link==nullptr)
        {
            return;
        }
        
        if(current->data==current->link->data)//if adjacent nodes have same data,remove the second node
        {
            node* delsave=current->link;
            current->link=delsave->link;
            delete delsave;
        }
        else
        current=current->link;//else move to next node
    }
    
}

void display(node* root)
{
    while(root!=nullptr)
    {
    cout<<root->data<<" ";
    root=root->link;
    }
}

int main()
{
    int size,x;
    cin>>size;
    node* start=nullptr,*end=nullptr;

    int* arr=new int[size];
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    //input data from user

    
    for(int i=0;i<size;i++)
    {
        x=arr[i];
        node* temp=new node(x);
        if(start==nullptr)
        {
        temp->link=end;
        start=end=temp;
        }
        else
        {
            end->link=temp;
            end=temp;
        }
        
    }
    //create the linked list


    removeDuplicates(start);
    //removing duplicates
    
    display(start);

    
}