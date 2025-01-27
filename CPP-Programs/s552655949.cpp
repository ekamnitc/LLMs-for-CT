#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	ll res = 0;

	for (int b = 1; b <= N; b++) {
		if (b - K <= 0)
			continue;
		int p = N / b;
		int r = N % b;
		res += (ll)p * (ll)(b - K);
		if (r - K + 1 >= 0)
			res += (ll)(r - K + 1);
		if (K == 0)
			res--;
	}

	printf("%lld\n", res);

	return 0;
}
