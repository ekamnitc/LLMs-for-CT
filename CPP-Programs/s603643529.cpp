#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int n;
    cin >> n;
    vector<P> p(n);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    rep(i,n){
        int a;cin >> a;
        p.emplace_back(a,i);
    }
    sort(p.rbegin(),p.rend());
    dp[0][0] = 0;
    rep(i,n){
        rep(l,i+1){
            int r = i-l;
            dp[i+1][l+1] = max(dp[i+1][l+1],dp[i][l]+ll(p[i].second+1-(l+1))*p[i].first);
            dp[i+1][l] = max(dp[i+1][l],dp[i][l]+ll(n-r - (p[i].second+1))*p[i].first);
        }
    }

    ll ans = 0;
    rep(i,n+1) ans = max(ans,dp[n][i]);
    cout << ans << endl;
}