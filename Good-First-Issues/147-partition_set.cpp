/*
#147. Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
*/

// Solution

#include <bits/stdc++.h>
using namespace std;
int findMin(int arr[], int n){
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += arr[i];
    }
	
	bool dp[n + 1][sum + 1];
	
	for (int i = 0; i <= n; i++){           // initialize first column as true. 0 sum is possible with all elements
		dp[i][0] = true;
    }
	
	for (int i = 1; i <= sum; i++){         // initialize top row, except dp[0][0], as false. With 0 elements, no other sum is possible except 0
		dp[0][i] = false;
    }
	
	for (int i = 1; i <= n; i++) {                      // filling partition table in bottom up manner
		for (int j = 1; j <= sum; j++){
			dp[i][j] = dp[i - 1][j];                    // if 'i'th element is excluded
			if (arr[i - 1] <= j){                       // if i'th element is included
				dp[i][j] |=dp[i-1][j-arr[i-1]];
            }
		}
	}

	int diff = INT_MAX;
	for (int j=sum/2;j>=0;j--){        // Finding largest j such that dp[n][j] is true
		if (dp[n][j] == true) {
			diff = sum - 2 * j;
			break;
		}
	}
	return diff;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	cout<<findMin(arr,n);
	return 0;
}

/*
Sample Input: arr[] = {1, 6, 11, 5}
Sample Output: 1
Time Complexity : O(n * sum)
n = size of input array
sum = sum of elements in the array
*/