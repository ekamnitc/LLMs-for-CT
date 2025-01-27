#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n;
	cin >> n;
	if (n & 1)
		cout << 0 << '\n';
	else
	{
		n >>= 1;
		long long cnt = 0;
		for (long long i = 5; (n / i) >= 1; i*=5)
		{
			cnt += (n / i);
		}
		cout << cnt << '\n';
	}
	return 0;
}