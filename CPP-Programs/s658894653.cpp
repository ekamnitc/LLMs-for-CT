#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, ans = 0;
vector<ll> x(1, 0);
vector<vector<vector<ll>>> dp(51, vector<vector<ll>> (51, vector<ll> (2501, 0)));

int main(){
    cin >> n >> a;
    for(int i = 0; i < n; i++){
        ll y;
        cin >> y;
        x.push_back(y);
    }
    sort(x.begin(), x.end());
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j <= n; j++){
            for(ll k = 0; k <= n*max(a, x.back()); k++){
                if(i == 0 && j == 0 && k == 0){
                    dp[i][j][k] = 1;
                }
                else if(i >= 1 && k < x[i]){
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                else if(i >= 1 && j >= 1 && k >= x[i]){
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i]];
                }
                else{
                    dp[i][j][k] = 0;
                }
            }
        }
    }
    for(ll i = 1; i <= n; i++){
        ans += dp[n][i][i*a];
    }
    cout << ans << endl;
}