#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;

int N;

ll		solve(vector<ll> &A, ll cur)
{
	ll ans = 0;
	for (int i = 1; i < N; i++)
	{
		if (cur > 0 && cur+A[i] >= 0)
		{
			ans += abs(-1-(cur+A[i]));
			cur = -1;
		}
		else if (cur < 0 && cur+A[i] <= 0)
		{
			ans += abs(1-(cur+A[i]));
			cur = 1;
		}
		else
			cur += A[i];
	}
	return (ans);
}

int		main(void)
{
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	ll ans1 = 0, ans2 = 0;
	ll cur = A[0];
	if (cur <= 0)
	{
		ans1 += abs(1-cur);
		cur = 1;
	}
	ans1 += solve(A, cur);
	cur = A[0];
	if (cur >= 0)
	{
		ans2 += abs(-1-cur);
		cur = -1;
	}
	ans2 += solve(A, cur);
	cout << min(ans1, ans2) << endl;
}

