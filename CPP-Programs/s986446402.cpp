#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	if (x == 0 || y == 0) {
		if (x <= y) ans = y - x;
		else ans = x - y + 1;
	}
	else  if (x * y > 0) {
		if (x <= y) ans = y - x;
		else ans = x - y + 2;
	}
	else {
		if (x >= y) ans = abs(abs(y) - x) + 1;
		else ans = abs(y - abs(x)) + 1;
	}
	cout << ans << endl;
}
