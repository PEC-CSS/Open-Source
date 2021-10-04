#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class stack
{
private:
    queue<int> q1;
    queue<int> q2;
    int sze;

public:
    void push(int val);
    stack()
    {
        this->sze = 0;
    }
    void pop();
    void top();
    void size();
    bool isEmpty();
};

void stack::push(int val)
{
    q1.push(val);
    sze++;
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    swap(q1, q2);
}

void stack::pop()
{
    cout << q2.front();
    q2.pop();
    sze--;
}

void stack::top()
{
    cout << q2.front();
}

void stack::size()
{
    cout << sze;
}

bool stack::isEmpty()
{
    return (sze == 0);
}

int main()
{
    int n, d, b;
    stack obj;
    vector<int> s;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin>>d>>b;
        switch(d)
        {
        case 1:
            obj.push(b);
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.top();
            break;
        case 4:
            obj.size();
            break;
        case 5:
            cout << obj.isEmpty();
            break;
        }
    }
}