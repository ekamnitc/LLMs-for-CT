#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <utility>
using namespace std;
using ll = long long int;

int main() {

	int N;
	cin >> N;

	int k = 0;
	for (int i = 1; i < 451; i++) {
		if (i*(i + 1) / 2 != N) {
			continue;
		}
		else {
			cout << "Yes" << endl;
			cout << i+1 << endl;
			k = i;
			break;
		}
	}
	if (!k) { cout << "No"; return 0; }

	vector<pair<int,int>> phase(N+1);
	vector<int> ness(k + 1);
	for (int i = 1; i <= k; i++) {
		ness[i] = ness[i - 1] + k + 1 - i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= k; j++) {
			if (i <= ness[j]) {
				phase[i] = make_pair(j,i-ness[j-1]);
				break;
			}
		}
	}
	for (int i = 0; i <= k; i++) {
		cout << k;
		for (int j = 1; j <= N; j++) {
			int flag = 0;

			//at Si, j cout?
			if (i == phase[j].first - 1)flag++;
			if (i == phase[j].first - 1 + phase[j].second)flag++;

			if (flag) {
				cout << " " << j;
			}
		}
		cout << endl;
	}

	return 0;
}