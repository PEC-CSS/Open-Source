#include<bits/stdc++.h>
using namespace std;
/*
Number of Ways Where Square of Number Is Equal to Product of Two Numbers

Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.

Example:

Input: nums1 = [1,1], nums2 = [1,1,1]
Output: 9

Explanation: All Triplets are valid, because 1^2 = 1 * 1.
Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2). nums1[i]^2 = nums2[j] * nums2[k].
Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]^2 = nums1[j] * nums1[k].

Time complexity: O(M*N)
*/

 void twoProduct(vector<int> & nums, int &count, long long target) {
        map<int, int> mp;
        mp[1] = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(target%nums[i] == 0) {
                int remain= target/nums[i];
                count += mp[remain];
            }
            mp[nums[i]]++;
        }
}

int solve(vector<int> nums1, vector<int> nums2){
	
		int n1 = nums1.size();
        int n2 = nums2.size();
        
        int count = 0;
        for(int i = 0; i<n1; i++) {
            twoProduct(nums2, count, (long)nums1[i]*nums1[i]);
        }
        
        for(int i = 0; i<n2; i++) {
            twoProduct(nums1, count, (long)nums2[i]*nums2[i]);
        }
        
        return count;
	
}

int main(){
	
	vector<int> nums1;
	vector<int> nums2;
	
	int m, n;
	
	cin>>m>>n;
	
	int temp;
	for(int ind=0; ind<m; ind++){
		cin>>temp;
		nums1.push_back(temp);
	}
	for(int ind=0; ind<n; ind++){
		cin>>temp;
		nums2.push_back(temp);
	}
	cout<<solve(nums1,nums2);
  		
}
