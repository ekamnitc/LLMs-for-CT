#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


ll dp[110][5][2];

int main(){
    string N;
    cin >> N;
    int n = N.size();
    int k;
    cin >> k;
    dp[0][0][0] = 1;

    rep(i, n){
        rep(j, k + 1){
            int digit = N[i] - '0';
            rep(t, digit + 1){
                if (t == digit){
                    if (digit == 0) dp[i+1][j][0] += dp[i][j][0];
                    else dp[i+1][j+1][0] += dp[i][j][0];
                }
                else {
                    if (t == 0) dp[i+1][j][1] += dp[i][j][0];
                    else dp[i+1][j+1][1] += dp[i][j][0];
                }
            }
            rep(t, 10){
                if (t == 0) dp[i+1][j][1] += dp[i][j][1];
                else dp[i+1][j+1][1] += dp[i][j][1];
            }
        }
    }

    cout << dp[n][k][0] + dp[n][k][1] << endl;

    return 0;
}