#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#define rip(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ld long double
#define set setprecision　//小数点以下何位まで知りたいか
#define mod 1000000007
#define pi 3.14159265
#include<numeric>
using namespace std;
int gcd(int a, int b)//最大公約数
{
	if (a % b == 0)	return(b);
	else return(gcd(b, a % b));
}
int lcm(int a, int b)//最小公倍数
{
	return a * b / gcd(a, b);
}
ll pow(ll a, ll b) {
	ll k = b % 30000, h = b / 30000, s = 1;
	rip(i, 30000)s = (s * a) % mod; ll j = 1;
	if (h != 0)rip(i, h)j = j * s % mod;
	if (k != 0)rip(i, k)j = j * a % mod;
	return(j);
}
int  main() {
	int n;
	cin >> n;
	vector<int>a(3 * n);
	rip(i, 3 * n)cin >> a[i];
	sort(a.begin(), a.end());
	ll sum = 0;
	rip(i, n)sum += a[3 * n - (2 * (1+i))];
	cout << sum << endl;
}