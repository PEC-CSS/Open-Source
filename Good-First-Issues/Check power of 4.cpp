/*
Check power of 4
------------------
You are given an integer N. You need to check if N is power of 4 or not. Return true or false accordingly
Using bit manipulation.

Input : 16
Output : TRUE

Input : 31
Output : FALSE
*/

#include<bits/stdc++.h>
using namespace std;
 
bool isPowerOfFour(unsigned int n){
    int count = 0;
    /*Check if there is only one bit set in n*/
    if (n && !(n&(n-1))){
        /* count 0 bits before set bit */
        while(n > 1){
            n >>= 1;
            count += 1;
        }
        /*If count is even then return true else false*/
        return (count%2 == 0)? 1 :0;
    }
    /* If there are more than 1 bit set then n is not a power of 4*/
    return false;
}
 
int main(){
    int n;
    cin>>n;
    if(isPowerOfFour(n)) cout << "TRUE";
    else cout << "FALSE";
    return 0;
}
