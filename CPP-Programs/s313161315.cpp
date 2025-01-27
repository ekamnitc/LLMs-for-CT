#include <bits/stdc++.h>

#define ull unsigned long long
#define MOD 998244353
using namespace std;


ull power(ull a, ull b)
{
	ull res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a) % MOD;
		b = b / 2;
		a = (a * a) % MOD;
	}
	return res;
}

ull modi(ull a)
{
	return power(a, MOD - 2);
}

int main()
{
	ull N, S;
	cin >> N >> S;
	vector<ull> v(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];
	vector<vector<ull>> dp(N + 1, vector<ull>(S + 1, 0));
	dp[0][0] = power(2, N);
	ull inv2 = modi(2);
	for (ull i = 1; i <= N; ++i)
	{
		for (ull j = 0; j <= S; ++j)
		{
			dp[i][j] = dp[i - 1][j];

			if (j >= v[i])
			{
				dp[i][j] += (dp[i - 1][j - v[i]] * inv2) % MOD;
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[N][S];
	return 0;
}