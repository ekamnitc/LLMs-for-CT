#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> c357num;

void dfs(string s, int digit) {
	if (3 <= digit) {
		bool exist3 = false;
		bool exist5 = false;
		bool exist7 = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '3') exist3 = true;
			if (s[i] == '5') exist5 = true;
			if (s[i] == '7') exist7 = true;
		}
		if(exist3 && exist5 && exist7) c357num.push_back(stoll(s));
	}
	if (digit == 9) {
		return;
	}
	digit++;
	for (int i = 0; i < 3; i++) {

		if (i == 0) {
			s += "3";
			dfs(s, digit);
			s.pop_back();
		}
		else if (i == 1) {
			s += "5";
			dfs(s, digit);
			s.pop_back();

		}
		else { // i == 2
			s += "7";
			dfs(s, digit);
			s.pop_back();
		}

	}
}

int main() {

	ll n; cin >> n;
	if (n <= 356) {
		cout << 0 << endl;
		return 0;
	}
	string s = "";
	int d = 0;
	dfs(s, d);
	sort(c357num.begin(), c357num.end());
	ll ans = 0;
	for (int i = 0; i < c357num.size(); i++) {
		if (c357num[i] <= n) ans++;
		else break;
	}
	cout << ans << endl;
	return 0;
}