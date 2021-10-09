/*

You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.

*/

// Solution

#include<bits/stdc++.h>
using namespace std;

int findNumberOfTriplets(int arr[], int n, int K) {
    vector<vector<int>>ans;                                             // vector for storing triplets
    sort(arr,arr+n);                                                    // sorting the input array

    for (int i = 0; i < n; i++) {
        int target = K - arr[i];
        int front = i + 1;
        int back = n - 1;

        while (front < back) {
            int sum = arr[front] + arr[back];

            if (sum < target) {                                         // finding answer which starts from arr[i]
                front++;
            }
            else if (sum > target) {
                back--;
            }
            else {
                int x = arr[front];
                int y = arr[back];
                ans.push_back({arr[i], arr[front], arr[back]});

                while (front < back && arr[front] == x) {               // incrementing front pointer until we reach a different number
                    front++;
                }
                while (front < back && arr[back] == y) {                // decrementing last pointer until we reach a different number
                    back--;
                }
            }
        }

        while(i+1<n && arr[i] == arr[i+1]) {                            // ensuring that we don't encounter duplicate values for arr[i]
            i++;
        }
    }
    return ans.size();
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int x;
        cin>>x;
        cout<<findNumberOfTriplets(arr,n,x)<<"\n";
    }
}

/*
Sample Input:

2
7
1 2 3 4 5 6 7
19
9
2 -5 8 -6 0 5 10 11 -3
10

Sample Output:

0
5

Time Complexity: O(N^2)
Space Complexity: O(1)
N : number of elements in input array
*/