#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

using ll = long long;

constexpr ll mod = 1000000007;

ll n, m;
ll x[100001], y[100001];

int main()
{
	scanf("%lld%lld", &n, &m);
	rep(i, n)
		scanf("%lld", x + i);
	rep(i, m)
		scanf("%lld", y + i);

	ll w = 0;
	rep(i, n)
		w = (w + (i - (n-1 - i))*x[i]) % mod;

	ll h = 0;
	rep( i, m )
		h = (h + (i - (m-1 - i))*y[i]) % mod;

	printf("%lld\n", w*h%mod);

	return 0;
}