#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll n, m, v, p; cin >> n >> m >> v >> p;
	vector<ll> a(n), s(n + 1);
	rep(i, 0, n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	rep(i, 0, n) s[i + 1] = s[i] + a[i];

	ll ans = p;
	rep(i, p, n) {
		if (a[i] + m < a[p - 1]) continue;
		ll mx = a[i] + m;
		ll sm = mx * (i - p + 1) - (s[i] - s[p - 1]);
		sm += (p - 1) * m + (n - i) * m;
		if (m * v <= sm) ++ans;
	}
	cout << ans;
	return 0;
}
