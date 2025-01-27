#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ld long double
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
// const ll INF = 1LL << 30;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////

// O(N*M)

set<ll> makec(){
    set<ll> c;
    c.insert(1);
    ll a = 6;
    while(a <= 100000){
        c.insert(a);
        a *= 6;
    }
    ll b = 9;
    while(b <= 100000){
        c.insert(b);
        b *= 9;
    }
    return c;
}

int main() {
    ll n; cin >> n;
    set<ll> c = makec();
    Vl dp(n+1, INF);
    dp[0] = 0;
    rep(i, 0, n){
        for(auto j : c){
            if(i + j > n) continue;
            chmin(dp[i+j], dp[i]+1);
        }
    }
    co(dp[n]);

    return 0;
}

