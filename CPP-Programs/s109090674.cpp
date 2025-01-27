#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

int arr[305][305], N, M, cnt[305], ans; 
bool del[305];

int main() {
	cin >> N >> M; ans = N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) cin >> arr[i][j];
		++cnt[arr[i][1]];
	}
	for (int i = 1; i <= M; ++i) {
		int mx = 0;
		for (int j = 1; j <= M; ++j) mx = max(mx, cnt[j]);
		ans = min(ans, mx);
		
		for (int j = 1; j <= M; ++j) if (mx == cnt[j]) { del[j] = 1; break; }
		
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= N; ++j) for (int k = 1; k <= M; ++k) if (!del[arr[j][k]]) { ++cnt[arr[j][k]]; break; }
	}
	cout << ans << endl;
	
	return 0;
}