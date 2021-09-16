#include <bits/stdc++.h>
using namespace std;
class twostack
{
    int* a;
    int top1;
    int top2;
    int size;
    public :
    twostack(int n)
    {
        top1=-1;
        top2=n/2-1;
        size=n;
        a=new int[n];
    }
    void push1(int element)
    {
            if(top1<size/2)
            {
                a[++top1]=element;
            }
            else
            {
                cout<<"OVERFLOW"<<endl;
            }
    }
      void push2(int element)
    {
            if(top2<size)
            {
                a[++top2]=element;
            }
            else
            {
                cout<<"OVERFLOW"<<endl;
            }
    }
    void pop1()
    {
            if(top1>0)
            {
                top1-=1;
            }
            else
            {
                cout<<"UNDERFLOW"<<endl;
            }
    }
       void pop2()
    {
            if(top2>size/2)
            {
                top2-=1;
            }
            else
            {
                cout<<"UNDERFLOW"<<endl;
            }
    }
     int size1()
     {
         return top1+1;
     }
     int size2()
     {
         return (top2-size/2+1);
     }
     int gettop1()
     {
         if (top1>=0)
         return a[top1];
        else
        return -1;
     }
     int gettop2()
     {
         if(top2>=size/2)
         return a[top2];
         else return -1;
     }
};
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
    twostack s1(10000);
    int t;
    cin>>t;
    int s,element;
    bool check;
    while(t--)
    {
        cin>>s;
        if(s==1)
        {
            cin>>check;
            if(check == 0)
            {
                cin>>element;
               s1.push1(element);
            }
            else
            s1.pop1();
        }
        else if(s==2)
        {
            cin>>check;
            if(check == 0)
            {
                cin>>element;
               s1.push2(element);
            }
            else
            s1.pop2();
        }
        else
        cout<<"INVALID INPUT"<<endl;
    }
    cout<<"Final size of stack1 is: "<<s1.size1()<<endl;
    if(s1.gettop1()!=-1)
    cout<<"Top element of stack1 is: "<<s1.gettop1()<<endl;
    else
    cout<<"Top element of stack1 doesn't exist"<<endl;
    cout<<"Final size of stack2 is: "<<s1.size2()<<endl;
      if(s1.gettop2()!=-1)
    cout<<"Top element of stack2 is: "<<s1.gettop2()<<endl;
    else
    cout<<"Top element of stack2 doesn't exist"<<endl;
    return 0;
}