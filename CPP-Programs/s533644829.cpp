#include <iostream>
#include <algorithm>

using ll = long long int;

int main() {
	int n;
	std::cin >> n;

	long long int d, a;
	std::cin >> d >> a;

	std::pair<std::pair<ll, ll>, ll> monst[200010];
	for (int i = 0; i < n; ++i)
		std::cin >> monst[i].first.first >> monst[i].first.second;

	std::sort(monst, monst + n);

	int i = 0, j = 0;
	ll rollsum = 0;
	ll ans = 0;
	while (i < n) {
		while (monst[j].first.first - monst[i].first.first + 1 <= 2*d + 1 && j < n) {
			++j;
		}
		--j;

	//	std::cout << i << " " << j << "\n";
		rollsum += monst[i].second;
		monst[i].first.second -= rollsum;
		int left = monst[i].first.second;
	//	std::cout << left << "\n";
		if (left > 0) {
			ll nratt = (left + a - 1) / a;
			ans += nratt;
			rollsum += nratt * a;
			monst[j+1].second -= nratt * a;
		}

	//	std::cout << ans << "\n\n";
		++i;
	}

	std::cout << ans;
}