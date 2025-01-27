#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1100000000;
const int H_MAX = 10000;
const int N_MAX = 1000;

int main() {
	int h, n;
	cin >> h >> n;
	int dp[H_MAX+1];
	dp[0] = 0; fill(dp+1, dp+h+1, INF);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 1; j <= h; j++) {
			dp[j] = min(dp[j], b+dp[max(0, j-a)]);
		}
	}
	int ans = dp[h];
	cout << ans << endl;
	return 0;
}