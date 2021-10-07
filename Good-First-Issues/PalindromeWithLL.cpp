#include<iostream>
#include<stack>
using namespace std;

class node
{
    
    
    public:
    int data;
    node* next=nullptr;
    node(int x)
    {this->data=x;}
}*start,*rear;

void push(int x)
{
    node* temp=new node(x);
    if(start==nullptr)
    {
    start=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

void show()
{
    node*root=start;
    while(root)
    {cout<<root->data<<" ";
    root=root->next;}
}

bool check(node*root,stack<int> s)
{
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        if(root->data!=s.top())
        return false;

        s.pop();
        root=root->next;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        start=nullptr;
        rear=nullptr;
        int d=0;
        stack<int>s;
        while(d!=-1)
        {
            scanf("%d",&d);
            if(d!=-1)
            {
                push(d);
                s.push(d);
            }
        }
        // show();
        
        (check(start,s))?cout<<"true\n":cout<<"false\n";
    }
}