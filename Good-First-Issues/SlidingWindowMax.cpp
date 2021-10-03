#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> SlidingWindow(int arr[], int k, int size)
{
    vector<int> answer;
    deque<int> windowQ;
    //initializing a deque

    for (int i = 0; i < k; i++)//for the first k elements, push them into the deque while taking care fo the fact that their
    //are no unnecessary element. pop from back the elements that are less than the current element to be inserted
    {
       
        while (!windowQ.empty() && arr[i] >= arr[windowQ.back()])
        {
            windowQ.pop_back();
        }
        windowQ.push_back(i);
        

    }
    answer.push_back(arr[windowQ.front()]);
    //max element of this window is at front


    for (int i = k; i < size; i++)
    //repeating the above task for the rest of the array while keeping in mind the changing windows, and hence 
    //popping the not required elements form the front that are not part of the new window
    {
        while (!windowQ.empty() && windowQ.front() <= i - k)
        {
            windowQ.pop_front();
        }
        while (!windowQ.empty() && arr[i] >= arr[windowQ.back()])
        {
            windowQ.pop_back();
        }
        windowQ.push_back(i);
        answer.push_back(arr[windowQ.front()]);


    }

    return answer;
}

int main()
{
    int size;
    cout<<"Size: ";
    cin >> size;
    int *array = new int[size];
    cout<<"Array: ";
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    int k;
    cout<<"k: ";
    cin>>k;
    vector<int> a=SlidingWindow(array,k,size);
    for(int i:a)
    cout<<i<<" ";
}
