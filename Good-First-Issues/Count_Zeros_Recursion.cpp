#include <iostream>
using namespace std;

int count_zeroes(long long int n)
{
    if (n == 0)
        return 0;
    
    return ((n % 10 == 0) ? 1 : 0) + count_zeroes(n/10);
}

int main()
{
    long long int n = 10304367000;

    // Comment out the next line and test for any user-given input
    // cin >> n; 
    cout << count_zeroes(n);
    return 0;
}