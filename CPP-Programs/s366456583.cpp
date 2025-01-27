#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	for(int i = 0; i < 3; i++) {
		if(s[i] == t[i]) {
			cnt++;
		}
	}
	cout << cnt;
}
