#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int main()
{
    FIO;
    int n; //size of array;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int target_sum; // the required pair sum
    cin >> target_sum;

    unordered_set<int> pair_sum;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (pair_sum.find(target_sum - a[i]) != pair_sum.end())
        {
            cout << "Required elements are: " << a[i] << " & " << target_sum - a[i] << "\n";
            found = true;
        }
        pair_sum.insert(a[i]);
    }
    if (!found)
        cout << "No such pair found found\n";

    return 0;
}