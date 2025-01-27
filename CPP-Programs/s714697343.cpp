// Bismillahirrahmanirrahim
// by Batrrr Tolkynbayev
#include <bits/stdc++.h>
// skripi krasava
#define respa return 0
#define all(x) x.begin(), x.end()
#define sz size
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5 + 17, M = N << 2, mod = 1e9 + 7; 

int tt = 1, n, a[N];

void solve () {
	cin >> n;	
	for (int i = 1; i <= n << 1; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + n + 1);
	int res = 0;
	for (int i = 2; i <= n << 1; i += 2) {
		res += min(a[i], a[i - 1]);
	}
	cout << res;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}