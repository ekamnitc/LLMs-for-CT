#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<ll> t(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		sum += t[i];
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int p, x; cin >> p >> x;
		ll tmpSum = sum;
		tmpSum -= t[--p];
		tmpSum += x;
		cout << tmpSum << endl;
	}
	return 0;
}