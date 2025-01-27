#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

void addPath(string &path, int n, char direction) {
	for(int i = 0; i < n; ++i) {
		path += direction;
	}
}

int main(void) {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	
	string ans = "";
	addPath(ans, ty - sy, 'U');
	addPath(ans, tx - sx, 'R');
	addPath(ans, ty - sy, 'D');
	addPath(ans, tx - sx, 'L');
	
	ans += 'L';
	
	addPath(ans, ty - sy + 1, 'U');
	addPath(ans, tx - sx + 1, 'R');
	
	ans += "DR";
	
	addPath(ans, ty - sy + 1, 'D');
	addPath(ans, tx - sx + 1, 'L');
	
	ans += 'U';
	
	cout << ans << endl;
	
	return 0;
}
