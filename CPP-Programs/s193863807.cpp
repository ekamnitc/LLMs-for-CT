#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int mod = 1000000007;

long long f(int a, int k);

int main()
{
	long long n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<pair<long long, long long>> b(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				b[i].first++;
			}
		}
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				b[i].second++;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += f(b[i].first, k - 1) + f(b[i].second, k);
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}

long long f(int a, int k)
{
	long long calc = (long long)k * (k + 1) / 2;
	calc %= mod;
	calc *= a;
	calc %= mod;

	return calc;
}