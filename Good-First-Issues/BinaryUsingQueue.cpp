#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;

    queue<string> binaryQ;
    binaryQ.push("1");
    int i=0;
    while(i<n)
    {
        cout<<binaryQ.front()<<" ";
        string next1=binaryQ.front()+"0";
        string next2=binaryQ.front()+"1";

        binaryQ.push(next1);
        binaryQ.push(next2);

        binaryQ.pop();
        i++;
        
    }
    
}