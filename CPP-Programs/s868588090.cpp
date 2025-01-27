#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void) {
	int n, m, i, a, b, s[100003] = {};

	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		s[a - 1]++;
		s[b - 1]++;
	}

	for (i = 0; i < n; i++) {
		if ((s[i] & 1) == 1) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}