// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
//Assume that at any instant, stack will not have more than 1000 elements.
const int MAX_LENGTH = 1000;

class Stack
{
    // Data Members

    //The length of the stack.
    int length =0;
    //The implementaion of the stack (According to the input explanation, this is an integer stack).
    int array[MAX_LENGTH];

    // Access specifier
    public:

    // Member Functions

    // Returns the number of elements present in stack.
    int getSize()
    {
        return length;
    }

    // Insert a new element to stack.
    void Push(int x)
    {
        array[length] = x;
        length++;
    }

    // Deletes the topmost element of stack.
    void Pop()
    {
        length--;
    }

    // Returns the value of topmost element of stack.
    int Top()
    {
        return array[length-1];
    }
};

int main()
{
    //First line of input contains the integer n, which stores the number of operations that we need to perform.
    int n;
    cin >> n;
    int input1,input2;
    // Creating a new instance of Stack class.
    Stack newStack;
    //Next n lines contain input in the format described in the issue:
    for (int i = 0; i < n; i++)
    {
        //Getting the input
        cin >> input1;
        //The operation is Push(x)
        if (input1 == 0)
        {
            cin >> input2;
            newStack.Push(input2);
        }
        //The operation is Pop
        if (input1 == 1)
        {
            newStack.Pop();
        }
    }
    //Output - printing the size and top element of stack, after performing n operations.
    cout << "Final size of stack is: " << newStack.getSize()<<"\n";
    if (newStack.getSize() != 0)
    {
        cout << "Top element of stack is: " << newStack.Top();
    }
    else
    {
        cout << "Top element of stack is: Not Possible";
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
