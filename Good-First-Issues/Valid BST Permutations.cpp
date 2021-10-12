/*
Given an integer, determine the number of valid Binary Search Trees that can be created by nodes numbered from 1 to that integer.

Input: Integer denoting the nodes

Output: Number of total BST

Input: 2
Output: 2

There will be two possible BST with 2 nodes.
2 (root)                            1(root)
1 (right child of the root)            2(left child of the root)

Input: 1
Output: 1

Input: 3
Output: 5
*/

#include <bits/stdc++.h>
using namespace std;
 
unsigned long int binomialCoeff(unsigned int n, unsigned int k){
    unsigned long int res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n - k) k = n - k;
 
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
 
// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long int catalan(unsigned int n){
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2*n, n);
 
    // return 2nCn/(n+1)
    return c/(n+1);
}
 
// A function to count number of BST with n nodes
// using catalan
unsigned long int countBST(unsigned int n){
    // find nth catalan number
    unsigned long int count = catalan(n);
 
    // return nth catalan number
    return count;
}

int main(){
    int n;
    cin>>n;
 
    // find count of BST with n nodes and print
    cout<<countBST(n);
    return 0;
}
