#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
void generate(int n)
{

    queue<string> q;
    q.push("1");
 
    int i = 1;
    while (i++ <= n)
    {
        q.push(q.front() + "0");
        q.push(q.front() + "1");
 
        cout << q.front() << ' ';
        q.pop();
    }
}
 
int main()
{
    int n ;
    cin>>n;

    generate(n);
 
    return 0;
}
