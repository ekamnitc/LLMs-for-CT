#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
ll a[MAXN], l[MAXN], r[MAXN];
int main() {
	int n; read(n);
	for (int i = 0; i <= n; i++)
		read(a[i]);
	if (n == 0) {
		if (a[0] == 1) puts("1");
		else puts("-1");
		return 0;
	}
	for (int i = n; i >= 0; i--) {
		l[i] = a[i] + (l[i + 1] + 1) / 2;
		r[i] = a[i] + r[i + 1];
	}
	if (l[0] != 1) {
		puts("-1");
		return 0;
	}
	ll ans = 1, cur = 1;
	for (int i = 1; i <= n; i++) {
		cur -= a[i - 1];
		cur = min(r[i], cur * 2);
		ans += cur;
	}
	cout << ans << endl;
	return 0;
}
