#include <iostream>
#include <stack>
using namespace std;

void print(int *arr, int n)
{
    stack<int> S;

    // Traverse all array elements
    for (int i = 0; i < n; i++)
    {
        // Keep removing top element from S while the top
        // element is greater than or equal to arr[i]
        while (!S.empty() && S.top() >= arr[i])
            S.pop();

        // If all elements in S were greater than arr[i]
        if (S.empty())
            cout << "_, ";
        else //Else print the nearest smaller element
            cout << S.top() << " ";
        S.push(arr[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    print(a, n);
    cout << "\n";
    return 0;
}
