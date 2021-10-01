#include <bits/stdc++.h>
using namespace std;


int largest_sum_zero(int arr[], int n)
{
	unordered_map<int, int> presum;

	int sum = 0; 
	int max_len = 0; 

	for (int i = 0; i < n; i++) {
		sum += arr[i];

		if (arr[i] == 0 && max_len == 0)
			max_len = 1;
		else if (sum == 0)
			max_len = i + 1;

		else if (presum.find(sum) != presum.end()) {

			max_len = max(max_len, i - presum[sum]);
		}
		else {
			presum[sum] = i;
		}
	}

	return max_len;
}

int main(){

	int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<largest_sum_zero(arr,n)<<endl;

	return 0;
}
