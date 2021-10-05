#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int N = 10e5+10;
const int inf = 0x3f3f3f3f;
int t, n, a[N], b[N];

map<int, int>mpa;
map<int, int>mpb;

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d", &a[i]);
			mpa[a[i]] = i;
		}
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d", &b[i]);
			mpb[b[i]] = i;
		}
		sort(a+1, a+1+n);
		sort(b+1, b+1+n);
		int minn = inf;
		int ans = inf;
		for(int i = 1; i <= n; i ++)
		{
			minn = min(minn, mpa[a[i]]);
			ans = min(ans, minn + mpb[b[i]] - 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}