#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int maxOne = 0;
    int ans = 0;
    int currCol = m - 1;
    for (int i = 0; i < n; i++)
    {
        while (currCol >= 0 && arr[i][currCol] == 1)
        {
            ans = i;
            currCol--;
        }
    }
    cout << ans << "\n";
    return 0;
}