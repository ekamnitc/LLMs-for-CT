#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<tuple<ll, ll, ll>> rec(n);
	rep(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		rec[i] = tie(c, a, b);
	}
	sort(rec.rbegin(), rec.rend());
	for (ll c1 = 0; c1 <= 100; ++c1) {
		for (ll c2 = 0; c2 <= 100; ++c2) {
			ll H = 0;
			bool ok = true;
			rep(i, n) {
				if (i == 0) {
					H = get<0>(rec[i]) + abs(get<1>(rec[i]) - c1) + abs(get<2>(rec[i]) - c2);
				}
				else {
					ll tmp = max(0LL, H - abs(get<1>(rec[i]) - c1) - abs(get<2>(rec[i]) - c2));
					if (tmp != get<0>(rec[i])) ok = false;
				}
			}
			if (ok) {
				printf("%lld %lld %lld\n", c1, c2, H);
				return 0;
			}
		}
	}
	return 0;
}