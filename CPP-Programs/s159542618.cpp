#include <iostream>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const ll INF = 1e15;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
typedef pair<ll,ll> P;
const ll MAX = 300010;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> t(n),v(n);
    rep(i,n) cin >> t[i];
    rep(i,n) cin >> v[i];
    vector<vector<double>> dp(40010,vector<double>(210,0));
    rep(i,n){
        t[i] *= 2;
        v[i] *= 2;
    }
    rep(i,n-1) t[i+1] += t[i];
    ll index = 0;
    rep(i,t[n-1]){
        if (i == t[index]) index++;
        rep(j,201){
            if (i != 0 && dp[i][j] == 0) continue;
            if (j > v[index]) continue;
            if (i+1 == t[index]){
                if (j == v[index]){
                    chmax(dp[i+1][j-1],dp[i][j]+(2*j-1.0)/8.0);
                    chmax(dp[i+1][j],dp[i][j]+2*j/8.0);
                    continue;
                }
            }
            if (j == 0){
                chmax(dp[i+1][j],dp[i][j]+2*j/8.0);
                chmax(dp[i+1][j+1],dp[i][j]+(2*j+1.0)/8.0);
                if (i == 0) break;
            }
            else if (j == 200){
                chmax(dp[i+1][j-1],dp[i][j]+(2*j-1.0)/8.0);
                chmax(dp[i+1][j],dp[i][j]+2*j/8.0);
            }
            else{
                chmax(dp[i+1][j-1],dp[i][j]+(2*j-1.0)/8.0);
                chmax(dp[i+1][j],dp[i][j]+2*j/8.0);
                chmax(dp[i+1][j+1],dp[i][j]+(2*j+1.0)/8.0);
            }
        }
    }
    printf("%.10f\n",dp[t[n-1]][0]);
}
