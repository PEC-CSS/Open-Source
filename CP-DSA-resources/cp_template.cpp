#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define DOWN(i,a,b) for(int i = a; i >= b; i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define FR(i,a) for(int i = 0; i < a; i++)
#define REP(i,a) for(int i = 0; i < a; i++)
#define Rep(i,a) for(int i = 0; i < a; i++)
#define For(i,a,b) for(int i = a; i <= b; i++)

#define sqr(x) (x)*(x)
#define dout debug && cout
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n
#define ll long long
#define ull unsigned long long
/* CONSTANT  */
#define oo 1000000002
/* DEBUGGING */
bool debug = false;
/* MAIN PROGRAM */

using namespace std;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

   
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<ll>odd, even;

        for (ll i = 0; i < n; i++) {
            if (arr[i] % 2)
                odd.push_back(arr[i]);
            else
                even.push_back(arr[i]);

        }


        if (even.size() == 0 || odd.size() == 0) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < odd.size(); i++)
                cout << odd[i] << " ";
            for (int i = 0; i < even.size(); i++)
                cout << even[i] << " ";


        }
        cout << endl;

    }





    return 0;







    //first time ctrl+shift+b;
    //for other use ctrl +b on code
    // ctrl+d for multiple selection
    //ctr + shift +d for copying the code down
}

