#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
vector<bitset<50>> vec;
long long sum[1010] = { 0 };
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		sum[i] += a;
		sum[i] += sum[i - 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			vec.emplace_back(sum[j] - sum[i]);
		}
	}
	long long ans = 0;
	for (int i = 49; i >= 0; i--) {
		int co = 0;
		vector<bitset<50>> vec1;
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j][i]) {
				co++;
				vec1.emplace_back(vec[j]);
			}
		}
		if (co >= k) {
			vec = vec1;
			long long t = 1;
			for (int j = 0; j < i; j++) {
				t *= 2;
			}
			ans += t;
		}
	}
	cout << ans << endl;
}
