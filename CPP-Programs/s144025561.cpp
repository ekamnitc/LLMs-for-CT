#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll x; cin >>x;
	// (2e9)^(1/5) < 200  && 200^5 <2^63
	auto f5=[](ll a){return a*a*a*a*a; };
	rep2(i, -200, 201) rep2(j, -200, 201){
		if(f5(i) - f5(j) == x){
			cout << i <<" "<< j <<"\n"; return 0;
		}
	}
	return 0;
}
