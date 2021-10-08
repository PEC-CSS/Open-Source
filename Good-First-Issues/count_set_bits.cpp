#include <iostream>
using namespace std;

//Function to count the number of set bits in binary representation of N
int countSetBits(int N)
{
    //Initialize count to 0
    int count = 0;

    //Traverse through every bit of N
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        //Check if ith bit is set and increase the count
        if (N & (1 << i))
            count++;
    }
    return count;
}

int main()
{
    int n;

    //Input Number
    cin >> n;

    //Function call
    int ans = countSetBits(n);
    cout << ans << endl;
}