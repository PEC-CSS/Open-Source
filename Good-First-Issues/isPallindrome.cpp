#include<iostream>
using namespace std;
bool isPalindrome(string String,int st,int ed)
{
if(st >= ed) //base case
return true;
else // true will be returned if strings match else false
return ((String[st] == String[ed]) && isPalindrome(String,st+1,ed-1));
}
int main()
{
string String;
cin>>String;
cout<< boolalpha <<isPalindrome(String,0,String.length()-1); // bool alpha returns true or false instead of 0 and 1
}
