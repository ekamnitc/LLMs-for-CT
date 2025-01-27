#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <ctime> 
using namespace std;

#define pb push_back
#define All(a) a.begin(), a.end()
#define met(a, b) memset(a, b, sizeof(a))
#define rep1(i, l, r) for(int i = l; i <= r; ++i)
#define rep2(i, l, r) for(int i = l; i < r; ++i) 
#define per(i, r, l) for(int i = r; i >= l; --i)
typedef long long ll;
typedef double db;
typedef long double ldb;
const int NIL = -1;
const int oo = 0x3f3f3f3f;
const ll INF = 2e18;
const db eps = 1e-8;
const db PI = acos(-1.0);
const int maxn = 2e5 + 7;

ll T[maxn], S[maxn];

inline int read(void)
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9')	{ if(ch == '-') f = -1; ch = getchar(); } 
	while(ch >= '0' && ch <= '9') {	x = (x << 1) + (x << 3) + ch - '0';	ch = getchar();	}
	return x * f;
}

inline void write(int x)
{
	if(x < 0) { putchar('-'); x = -x; }
    if(x >= 10) write(x/10); 
	putchar(x%10+'0'); 
}

int main(void)
{
	int n = read();
//	int n = 1e5;
	rep1(i, 1, n)
	{
		T[i] = read();
//		T[i] = i;
		S[i] = S[i-1] + T[i];
	}
	ll ans = INF;
	int l = 1, r = 3;
	rep1(i, 2, n-2)
	{
		ll A, B, C, D;
		while(l < i && abs((S[i]-S[l])-(S[l]-S[0])) > abs((S[i]-S[l+1])-(S[l+1]-S[0]))) ++l;
		while(r < n && abs((S[n]-S[r])-(S[r]-S[i])) > abs((S[n]-S[r+1])-(S[r+1]-S[i]))) ++r;
		A = S[l] - S[0];
		B = S[i] - S[l];
		C = S[r] - S[i];
		D = S[n] - S[r];
		ans = min(ans, max(max(A, B), max(C, D)) - min(min(A, B), min(C, D)));
	}
	printf("%lld", ans);
	
	return 0;
} 