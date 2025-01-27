#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
  	cin >> s;
  	int ans = 0;
    for (int i = 0; i < s.length(); i++) if (s[i] == 'o') ans++;
    cout << (ans + 15 - s.length() >= 8 ? "YES" : "NO");
	return 0;
}