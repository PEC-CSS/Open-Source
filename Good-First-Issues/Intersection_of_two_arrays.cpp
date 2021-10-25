//Kaushal Barhate
//Intersection of two arrays

#include <iostream>
using namespace std;

void bubble_sort(int A[], int n)
{
    int temp;
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = 0; i < n - k - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
}

int binarySearch(int array[], int x, int high)
{
    int low = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;
    int temp[n];
    int j = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];
    temp[j++] = arr[n - 1];
    for (int i = 0; i < j; i++)
        arr[i] = temp[i];
    return j;
}

int main()
{
    int a = 0;
    cout << "Enter number of elements in first array" << endl;
    int n1;
    cin >> n1;
    int nums1[n1];
    int nums3[n1];
    cout<<"Enter "<<n1<<" Elements: "<<endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }
    cout << "Enter number of elements in second array" << endl;
    int n2;
    cin >> n2;
    int nums2[n2];
    cout<<"Enter "<<n2<<" Elements: "<<endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
    }
    bubble_sort(nums2,n2);
    for (int i = 0; i < n1; i++)
    {
        int result = 0;
        result = binarySearch(nums2, nums1[i], n2 - 1);
        cout << result << endl;
        if (result != -1)
        {
            nums3[a] = nums1[i];
            a++;
        }
    }

    a = removeDuplicates(nums3, a);
    
    cout << "Intersection of nums1 and nums2:" << endl;
    cout<<"[";
    for (int i = 0; i < a; i++)
    {
        if(i==a-1){
            cout<<nums3[i];
            break;
        }
        cout << nums3[i] << ",";
    }
    cout<<"]";
}