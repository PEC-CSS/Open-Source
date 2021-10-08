#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int mn = INT_MAX;
    int p = 0;
    for (int i = k - 1; i < n; i++, p++)
    {
        mn = min(mn, arr[i] - arr[p]);
    }

    cout << mn << "\n";

    return 0;
}