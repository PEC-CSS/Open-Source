#include <iostream>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

template <typename T>
void print(T *a, int l, int u, string separator = " ")
{
    for (int i = l; i < u; i++)
        cout << a[i] << separator;
    cout << "\n";
}

signed main()
{
    int n; // size of the array
    int *a;
    cin >> n;
    a = new int[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k; // size of sliding window
    cin >> k;
    int m;
    int *ans = new int[n];
    for (int i = 0; i <= n - k; i++)
    {
        m = a[i];
        for (int j = i; j < i + k; j++)
            m = max(a[j], m);
        ans[i] = m;
    }
    // Time complexity: O(n*k)
    print(ans, 0, n - k + 1);

    return 0;
}