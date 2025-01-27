#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 303, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	double s = 0;
	vector<int> a(n);
	for(auto &i : a) cin >> i, s += i;
	s /= n;
	int id = 0;
	for(int i = 1; i < n; i++) if(abs(a[i]-s) < abs(a[id]-s)) id = i;
	cout << id << '\n';
	return 0;
}
