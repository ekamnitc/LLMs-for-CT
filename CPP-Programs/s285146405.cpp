#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

#define int long long

#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define rrep(i, n) for (int i=(int)n-1;i>=0;--i)
#define rrep1(i, n) for (int i=n;i>=1;--i)
#define range(i, l, r) for (int i=l;i<(int)r;++i)
#define rrange(i, l, r) for (int i=(int)r-1;i>=(int)l;--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;
using ld=long double;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}
constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}

const int mod = TEN(9)+7;

int N;
int A, B;
vi v;
int comb[55][55];

void init()
{
	comb[0][0] = 1;
	for (int i = 1; i <= 50; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= 50; ++j) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}

signed main()
{
	cin >> N >> A >> B;
	v.resize(N);

	init();

	map<int, int> counter;
	
	rep(i, N) {
		cin >> v[i];
		counter[v[i]]++;
	}

	sort(all(v), greater<int>());
  
	int ans = 0;
	map<int, int> uses;

	for (int i = A; i <= B; ++i) {
		uses.clear();

		for (int j = 0; j < i; ++j) {
			uses[v[j]]++;
		}

		ans += comb[counter[v[i - 1]]][uses[v[i - 1]]];
		if (v[0] != v[i]) break;
	}

	printf("%.10f\n", (double)accumulate(begin(v), begin(v) + A, 0ll) / A);
	printf("%lld\n", ans);

	// A / i == B / j
}

