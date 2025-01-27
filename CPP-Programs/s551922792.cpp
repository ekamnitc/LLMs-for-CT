#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main() {
	int N; char S[51]; cin >> N >> S;
	int ans = 0;
	for (int i = 0; i < strlen(S)-2; i++) {
		if (memcmp(&S[i], "ABC", 3) == 0) {
			ans++;
		}
	}
	cout << ans << endl;
}