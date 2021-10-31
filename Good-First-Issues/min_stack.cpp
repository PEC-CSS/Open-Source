#include <bits/stdc++.h>

using namespace std;

//----------------------------------------------------------------

// For each node apart from storing its value also
// store the minimum element seen so far from the
//  bottom of the stack till this element
class MinStack
{
    class Node
    {
        int value;
        int min_so_far;
        Node *next;

    public:
        Node(int val, int min_el)
        {
            value = val;
            min_so_far = min_el;
        }
        int get_min_so_far() { return this->min_so_far; }
        int get_value() { return this->value; }
    };

    std::stack<Node> s;
    

public:
    MinStack() {}
    void push(int x);
    int pop();
    int top() { return s.top().get_value(); }
    int getSize() { return s.size(); }
    int getMin() { return s.top().get_min_so_far(); }
};
void MinStack::push(int x)
{
    if (s.empty())
    {
        s.push(Node(x, x));
        return;
    }
    else
    {
        int min_el = min(x, s.top().get_min_so_far());
        s.push(Node(x, min_el));
    }
    return;
}

int MinStack::pop()
{
    int temp = s.top().get_value();
    s.pop();
    return temp;
}
int main()
{
    MinStack stack;

    stack.push(1);
    cout << "Minimum Element in the stack: " << stack.getMin() << "\n";
    stack.push(2);
    stack.push(-1);
    cout << "Minimum Element in the stack: " << stack.getMin() << "\n";
    stack.pop();
    cout << "Top of the stack: " << stack.top() << "\n";
    cout << "Minimum Element in the stack: " << stack.getMin() << "\n";
    stack.push(-100);
    stack.push(-10000);
    cout << "Minimum Element in the stack: " << stack.getMin() << "\n";
    stack.pop();
    cout << "Minimum Element in the stack: " << stack.getMin() << "\n";
    cout << "Top of the stack: " << stack.top() << "\n";
    cout << "Size of stack: " << stack.getSize() << "\n";

    return 0;
}