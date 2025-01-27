#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	ll w, h, x, y;
	cin >> w >> h >> x >> y;
	cout << fixed << setprecision(10);
	cout << (w * h) / 2.0 << " ";
	if(x == w / 2.0 && y == h / 2.0) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}