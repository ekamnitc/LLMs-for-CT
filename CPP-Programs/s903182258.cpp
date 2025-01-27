#include<bits/stdc++.h>

#define mp make_pair
#define LL long long

using namespace std;
template<class T> T gi() {
	T x = 0; bool f = 0; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') f = 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f ? -x : x;
}
const int N = 2010, Mod = 1e9 + 7;
int f[N][N], fac[N * N], ifac[N * N];
int fpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1ll * a * a % Mod)
		if (b & 1) res = 1ll * res * a % Mod;
	return res;
}
int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[m] % Mod * ifac[n - m] % Mod;
}
void pls(int &x, int y) { x += y; if (x >= Mod) x -= Mod; }
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n = gi<int>(), k = gi<int>();
	if (k == 1) { puts("1"); return 0; }
	for (int i = fac[0] = 1; i <= n * k; i++)
		fac[i] = 1ll * fac[i - 1] * i % Mod;
	ifac[n * k] = fpow(fac[n * k], Mod - 2);	
	for (int i = n * k; i; i--)
		ifac[i - 1] = 1ll * ifac[i] * i % Mod;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++) {
			f[i][j] = f[i - 1][j];
			if (j) pls(f[i][j], 1ll * f[i][j - 1] * (n - j + 1) % Mod * C((n - j + 1) * k - i + j - 2, k - 2) % Mod);
		}
	printf("%d\n", f[n][n]);
	return 0;
}
