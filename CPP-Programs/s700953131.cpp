#include <iostream>
#include <string>
#include<iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include<queue>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include <map>
#include<string.h>
#include<sstream>
#include<stack>
#include<unordered_map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <complex>
#define ll long long
#define  point complex<double>
#define  pi acos(-1)
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define arr2dof vector  vector<vector<int>>dp(N,vector<int>(2, inf));
using namespace std;
const ll N = 2e5 + 5, mod = 1e9 + 7, inff = -1e12, inf = 1e9 + 7;
const double ep = 0.0000000001;
//const double pi = 3.14159265359;

double dot(point a, point b) {
	return  (conj(a)*b).real();
}
double cross(point a, point b) {
	return  (conj(a)*b).imag();
}
double angle(point a, point b)
{
	double dt = dot(a, b);
	dt /= abs(a);
	dt /= abs(b);
	return acos(dt) * 180.0 / pi;
}

bool isrightangel(int ind) {//90 degree
	vector<point>v;
	return(angle(v[ind] - v[(ind + 1) % 3], v[ind] - v[(ind + 2) % 3]) == 90);//bshof hal eldot producty3ny fe
	//dl3en 3moden 3ashn yb2a right trinagle
}

ll fact[1000006], inv[1000006];

ll fp(ll base, ll exp)
{
	if (exp == 0)
		return 1;
	ll ans = fp(base, exp / 2);
	ans = (ans * ans) % mod;
	if (exp % 2 != 0)
		ans = (ans * (base % mod)) % mod;
	return ans;
}

void calcFacAndInv(ll n)
{
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		inv[i] = fp(fact[i], mod - 2);
	}
}

ll ncr(ll n, ll r)
{
	return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
	return (fact[n] * inv[n - r]) % mod;
}

int GCD(int a, int b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}
int LCM(int a, int b) {
	return (a*b) / GCD(a, b);
}

void intersectline(pair<int,int>a, pair<int, int>b, pair<int, int>c, pair<int, int>d) {

	double a1, b1, c1, a2, b2, c2;
	 a1 = b.second - a.second;
	 b1 = a.first - b.first;
	 c1 = (a1 * a.first) + (b1 * a.second);


      a2 = d.second - c.second;
	  b2 = c.first - d.first;
	  c2 = (a2 * c.first) + (b2 * c.second);

	 double dt= a1 * b2 - a2 * b1;
	 double  dy, dx;
	 dx = c1 * b2 - c2 * b1;
	 dy = a1 * c2 - a2 * c1;
	 if (dt==0&&(dx!=0||dy!=0))
         cout << "NONE" << endl;
	 	 else if (dt == 0 && dx == 0&& dy == 0) {
		 cout << "LINE" << endl;
	 }
	 else {
		 double x = (b2*c1 - b1 * c2) / dt;
		 double y = (a1*c2 - a2 * c1) / dt;
		 if (x==0.0)
				cout <<fixed<<setprecision(2)<< "POINT" << " " << x << " " << y<< endl;
		
	 }

}
	
		

	double arr[3005];
	double dp[3005][3005];
int main()
{
	int n;
	memset(dp, 0.0, sizeof dp);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	dp[0][0] = 1.0;
	for (int i = 1; i <= n; ++i) {
		for (int l = 0; l <= i; l++) {
			if (l==0)
				dp[i][l] = dp[i - 1][l] * (1 - arr[i]);
			else
				dp[i][l] = dp[i - 1][l] * (1 - arr[i]) + dp[i - 1][l - 1] * arr[i];
		}
	}
	double ans = 0.0;
	for (int i = (n+1) / 2; i <= n; ++i) {
		ans += dp[n][i];
	}
	cout <<fixed<<setprecision(10)<< ans;
	return 0;
}