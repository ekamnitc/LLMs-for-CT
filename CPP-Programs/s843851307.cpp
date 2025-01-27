#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
	int h, w, d;
	scanf("%d%d%d", &h, &w, &d);
	map<int, pair<int, int>> mp;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a;
			scanf("%d", &a);
			mp[a] = {i, j};
		}
	}
	vector<int> dist(h * w);
	for (int i = d; i < h * w; i++) {
		dist[i] = dist[i - d] + abs(mp[i + 1].first - mp[i + 1 - d].first)
		          + abs(mp[i + 1].second - mp[i + 1 - d].second);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", dist[r - 1] - dist[l - 1]);
	}
	return 0;
}