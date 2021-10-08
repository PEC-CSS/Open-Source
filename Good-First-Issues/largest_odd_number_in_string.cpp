#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    cin >> st;
    bool found = false;
    for (int i = st.length() - 1; i >= 0; i--)
    {
        if ((st[i] - '0') % 2 != 0)
        {
            cout << st.substr(0, i + 1);
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "";
    }

    return 0;
}
