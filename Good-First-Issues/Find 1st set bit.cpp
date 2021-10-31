/*
Find 1st set bit
------------------
You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).

Input : 18 (Binary Representation 010010)
Output : 2

Input: 19 (Binary Representation 010011)
Output: 1
*/

#include<bits/stdc++.h>
using namespace std;
 
int PositionRightmostSetbit(int n){
  int count = 1;
   
  while(n > 0){ 
    // Checking if last bit is set
    if(n&1) return count;
    // Increment position and right shift number
    count++;
    n = n>>1;
  } 
  // set bit not found.
  return -1;
}
 
int main(){
  int n;
  cin>>n;
   
  int pos = PositionRightmostSetbit(n);
 
  if(pos != -1) cout<<pos;
  else cout<<0;
 
  return 0;
}
