#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	int ans = 0;
	rep(i, n - 1)
	{
		if (a[i] == a[i + 1])
		{
			a[i + 1] = -1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}