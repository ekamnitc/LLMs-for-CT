#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] ^ a[j]) {
				for (int k = j + 1; k < n; ++k) {
					if (a[i] ^ a[k] && a[j] ^ a[k] && (ll) a[i] + a[j] + a[k] > (ll) 2 * max(a[i], max(a[j], a[k]))) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}