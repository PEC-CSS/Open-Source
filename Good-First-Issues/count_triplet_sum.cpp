#include <bits/stdc++.h>
using namespace std;

int findTriplets(int arr[], int n, int sum)
{
     
    int count=0;

	for (int i = 0; i < n - 1; i++) {
		unordered_set<int> s;
		for (int j = i + 1; j < n; j++) {
			int x = sum - (arr[i] + arr[j]);
			if (s.find(x) != s.end()){
                count++;
            }
            else
				s.insert(arr[j]);
		}
	}

    return count;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];;
        }

        int sum;
        cin>>sum;

	    cout<<findTriplets(arr, n, sum)<<endl;
    }

	return 0;
}
