#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	long long n, i, j, k, ans, s;
	cin >> n;
	vector<long long> a(n * 3), x(n * 3, -1LL << 57), y(n * 3, 1LL << 57);
	for (i = 0; i < n * 3; i++) cin >> a[i];
	s = 0;
	priority_queue<long long> q, qq;
	for (i = 0; i < n; i++) {
		q.push(-a[i]);
		s += a[i];
	}
	x[n - 1] = s;
	for (i = n; i <= 2 * n - 1; i++) {
		q.push(-a[i]);
		s += a[i];
		s += q.top();
		q.pop();
		x[i] = s;
	}

	s = 0;
	for (i = 3 * n - 1; i >= 2 * n; i--) {
		qq.push(a[i]);
		s += a[i];
	}
	y[2 * n] = s;
	for (i = 2 * n - 1; i >= n; i--) {
		qq.push(a[i]);
		s += a[i];
		s -= qq.top();
		qq.pop();
		y[i] = s;
	}

	ans = -1LL<<60;
	for (i = n - 1; i < 2 * n; i++) ans = max(ans, x[i] - y[i + 1]);
	cout << ans << "\n";

	return 0;
}
