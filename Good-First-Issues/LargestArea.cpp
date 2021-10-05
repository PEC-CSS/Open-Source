#include <iostream>
#include <stack>
using namespace std;

int area(int arr[], int n)
{
    stack<int> temp;
    stack<int> temp2;

    int *left = new int[n];
    //to store the left limits of the bars
    int *right = new int[n];
    //to store the right limits of the bars

    for (int i = 0; i < n; i++)
    {
       
        if (temp.empty() || arr[temp.top()] <= arr[i])
        {                        
            if (i!=0)
            {
                left[i] = temp.top() + 1;
                cout<<"Pushing to left: "<<temp.top()+1<<endl;
            }
            else
                left[i] = 0;
            temp.push(i);
        }

        //if height of current bar greater than stack's top, push it into the stack
        else
        {
            while (arr[temp.top()] >= arr[i])
            {
                temp.pop();
                if(temp.empty())
                break;
            }
            //else; delete from stack till the heights are higher than current
            
            if (temp.empty())
                left[i] = 0;
            //if stack is empty then the limit at left is 0th index

            else
            {
                left[i] = temp.top() + 1;
                cout<<"Pushing to left: "<<temp.top()+1<<endl;
            }
            temp.push(i);
            
        }
    }
//loop to find the left limits array 


    for (int i = n - 1; i >= 0; i--)
    {
        
        if (temp2.empty() || arr[temp2.top()] <= arr[i])
        {
            if (i!=n-1)
                right[i] = temp2.top() - 1;
            else
                right[i] = n - 1;
            temp2.push(i);
        }
        //if height of current bar greater than stack's top, push it into the stack
        else
        {
            while (arr[temp2.top()] >= arr[i])
            {
                
                temp2.pop();
                if(temp2.empty())
                break;
            }
            //else; delete from stack till the heights are higher than current
            
            if (temp2.empty())
                right[i] = n-1;
            //if stack is empty then the limit at left is 0th index

            else
                right[i] = temp2.top()-1;

            temp2.push(i);
            
        }
    }
//loop to find the right limits array

    int max = 0, a;
    for (int i = 0; i < n; i++)
    {
        a = (right[i] - left[i] + 1) * arr[i];
        //for each bar in the histogram, the maximum area possible w that bar inlcuded fully is given by:
        //(rightlimit-leftlimit+)*height-->base*height
        if (a > max)
            max = a;
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    cout << area(arr, n);
}