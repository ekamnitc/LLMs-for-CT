#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>
#include <numeric>
#include <queue>
#include <cmath>
#include <iomanip>
#include <array>
#include <string>
#include <stack>
#include <cassert>
#include <memory>

using namespace std;
int main() {
	int n, k; std::cin >> n >> k;
	vector<int> light(n), sum(n, 0);
	for (auto& l : light) cin >> l;
	for (auto t = 0; t < k; ++t) {
		sum.assign(n, 0);
		for (auto i = 0; i < n; ++i) {
			sum[std::max(i - light[i], 0)]++;
			if (i + light[i] + 1 < n) sum[i + light[i] + 1]--;
		}
		for (auto i = 0; i < n; ++i) {
			if (i > 0) sum[i] += sum[i - 1];
			light[i] = sum[i];
		}
		const auto n_count{ std::count(light.begin(), light.end(), n) };
		if (n_count == n) break;
	}
	for (auto i = 0; i < n; ++i) {
		if (i > 0) std::cout << ' ';
		std::cout << light[i];
	}
}