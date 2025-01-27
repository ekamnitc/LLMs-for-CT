#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;
#define rep(i, n) for(int i = 0; i < int(n); i++)

signed main(){
	int n, ans = 0; cin >> n;
	vector<int> a(n), b(n), c(n - 1);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i], ans += b[i];
	rep(i, n - 1) cin >> c[i];
	rep(i, n - 1){
		if(a[i] == a[i + 1] - 1) ans += c[a[i] - 1];
	}
	cout << ans << endl;
}