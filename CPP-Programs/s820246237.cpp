#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main() {
	int N;
	string s[2];
	cin >> N >> s[0] >> s[1];
	
	ll ans;
	int itr = 0;

	if(s[0][0] == s[1][0]) {
		ans = 3;
		itr++;
	}else {
		ans = 6;
		itr += 2;
	}

	while(itr < N) {
		if(s[0][itr] == s[1][itr]) {
			if(s[0][itr-1] == s[1][itr-1]) {
				ans *= 2;
			} else {
				ans *= 1;
			}
			itr++;
		} else {
			if(s[0][itr-1] == s[1][itr-1]) {
				ans *= 2;
			} else {
				ans *= 3;
			}
			itr += 2;
		}
		ans %= MOD;
	}

	cout << ans << endl;
}