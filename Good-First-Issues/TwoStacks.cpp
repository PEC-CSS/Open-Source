// TwoStacks.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
//Assume that at any instant, the total number of elements present in both the stacks will not be more than 1000.
const int MAX_LENGTH = 1000;

class TwoStacks
{
    // Data Members

    //The length of the stacks.
    int length1 = 0;
    int length2 = 0;
    //The implementaion of the stacks (According to the input explanation, these are integer stack).
    int array[MAX_LENGTH];

    // Access specifier
    public:

    // Member Functions

    // Returns the number of elements present in stack 1
    int getSize1()
    {
        return length1;
    }

    // Returns the number of elements present in stack 2
    int getSize2()
    {
        return length2;
    }

    // Insert a new element to stack 1.
    void Push1(int x)
    {
        array[length1] = x;
        length1++;
    }
    // Insert a new element to stack 2.
    void Push2(int x)
    {
        array[MAX_LENGTH-1-length2] = x;
        length2++;
    }

    // Deletes the topmost element of stack 1.
    void Pop1()
    {
        length1--;
    }

    // Deletes the topmost element of stack 2.
    void Pop2()
    {
        length2--;
    }

    // Returns the value of topmost element of stack 1.
    int Top1()
    {
        return array[length1 - 1];
    }

    // Returns the value of topmost element of stack 2.
    int Top2()
    {
        return array[MAX_LENGTH - length2];
    }
};

int main()
{
    //First line of input contains the integer n, which stores the number of operations that we need to perform.
    int n;
    cin >> n;
    int s, input1, input2;
    // Creating a new instance of TwoStacks class.
    TwoStacks newInstance;
    //Next n lines contain input in the format described in the issue:
    for (int i = 0; i < n; i++)
    {
        //Getting the s integer (which denotes the stack number).
        cin >> s;
        //Getting the bollean value
        cin >> input1;
        //First stack
        if (s == 1)
        {
            //The operation is Push1(x)
            if (input1 == 0)
            {
                cin >> input2;
                newInstance.Push1(input2);
            }
            //The operation is Pop1
            if (input1 == 1)
            {
                newInstance.Pop1();
            }
        }
        //Second stack
        if (s == 2)
        {
            //The operation is Push2(x)
            if (input1 == 0)
            {
                cin >> input2;
                newInstance.Push2(input2);
            }
            //The operation is Pop2
            if (input1 == 1)
            {
                newInstance.Pop2();
            }
        }
    }
    //Output - printing the size and top element of each stack, after performing n operations.
    //Stack1
    cout << "Final size of stack1 is: " << newInstance.getSize1() << "\n";
    if (newInstance.getSize1() != 0)
    {
        cout << "Top element of stack1 is: " << newInstance.Top1() << "\n";
    }
    else
    {
        cout << "Top element of stack1 is: Doesn't Exist\n";
    }
    //Stack1
    cout << "Final size of stack2 is: " << newInstance.getSize2() << "\n";
    if (newInstance.getSize2() != 0)
    {
        cout << "Top element of stack1 is: " << newInstance.Top2() << "\n";
    }
    else
    {
        cout << "Top element of stack1 is: Doesn't Exist\n";
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
