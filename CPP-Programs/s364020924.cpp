#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
//#include <unordered_map>

using namespace std;

template<typename T> void uin(T &a, T b) {if (b < a) a = b;}
template<typename T> void uax(T &a, T b) {if (b > a) a = b;}


#define int long long
#define double long double
#define right right228
#define mp make_pair
#define all(v) v.begin(), v.end()

const int MOD = 1e9 + 7;

int mod(int x) {
	x %= MOD;
	if (x < 0) x += MOD;
	return x;
}

int fp(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = mod(a * a)) {
		if (b & 1) res = mod(res * a);
	}
	return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '?') s[i]='D';
	}
	cout << s << endl;
	return 0;
}

/*

1
3 2 2
1 2 3 1 
2 3 1 0
1
1 3

01.a
3 3 4
...
.#.
...
1 1 1 3 8 
1 3 1 3 64
2 1 1 3 24
2 1 3 3 40

3 4 3
1 2
2 2
2 4
3
1 1 1 4
2 2 3 3
3 2 2 4

*/
