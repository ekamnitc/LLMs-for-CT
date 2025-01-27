#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;
//using namespace atcoder;

vector<ll>used,sum;
void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll>p(n+5),c(n+5);
	rep(i,n)cin>>p[i+1];
	rep(i,n)cin>>c[i+1];
	ll ans=-INF;
	int cur;
	for(int ccur=1;ccur<=n;++ccur){
		cur=ccur;
		bool ok=false;
		used=vector<ll>(n+5);
		sum=vector<ll>(n+5);
		ll start,loop;
		for(ll i=1;i<=k;++i){
			cur=p[cur];
			sum[i]=sum[i-1]+c[cur];
			chmax(ans,sum[i]);
			if(i==k){
				ok=true;
				break;
			}
			if(used[cur]>0){
				loop=i-used[cur];
				start=used[cur];
				break;
			}
			used[cur]=i;
		}
		if(ok)continue;
		for(int finish=1;finish<=n;++finish){
			ll res=0;
			if(used[finish]<start)continue;
			if(sum[start+loop]-sum[start]>0){
				ll len=(k-used[finish])/loop;
				res+=len*(sum[start+loop]-sum[start]);
			}
			res+=sum[used[finish]];
			chmax(ans,res);
		}
	}
	cout<<ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
