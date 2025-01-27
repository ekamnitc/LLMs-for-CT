#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	string s;
	bool ans = false;
	string keyword = "keyence";
	cin >> s;
	if (s == keyword)ans = true;
	else {
		if (s.substr(0, 7) == keyword)ans = true;
		else if (s.substr(s.length() - 7, 7) == keyword)ans = true;
		else {
			REP(i, 7) {
				if (s.substr(0, i) == keyword.substr(0, i)) {
					if (s.substr(s.length() - 7 + i, 7 - i) == keyword.substr(i, 7 - i)) {
						ans = true;
						break;
					}
				}
			}
		}
	}
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
