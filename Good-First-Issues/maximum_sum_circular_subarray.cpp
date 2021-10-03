#include <bits/stdc++.h>
using namespace std;

int maxCircularSum(int a[], int n){
	if (n == 1){
		return a[0];
    }
	
	int sum = 0;                    // Initialize sum variable which store total sum of the array
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];

	for (int i = 1; i < n; i++) {
		curr_max = max(curr_max + a[i], a[i]);          // Use Kadane's Algorithm to find Maximum subarray sum
		max_so_far = max(max_so_far, curr_max);

		curr_min = min(curr_min + a[i], a[i]);          // Use Kadane's Algorithm to find Minimum subarray sum
		min_so_far = min(min_so_far, curr_min);
	}

	if (min_so_far == sum){
		return max_so_far;
    }
	
	return max(max_so_far, sum - min_so_far);           // return maximum value
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	cout<<maxCircularSum(arr,n)<<endl;
	return 0;
}

/*
Sample Input: nums = [1,-2,3,-2]
Sample Output: 3
Time Complexity : O(n)
Space Complexity : O(1)
n = size of input array
*/