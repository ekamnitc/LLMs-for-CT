#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

/*pdf見て解答
コンビネーションかと思ったけど違った
フィボナッチと同じ形式で求めれるのに気づけなかった
DPにしては簡単な部類だった*/

int main(){
    ll n, m; cin >> n >> m;

    vector<ll> oks(n+1,true);
    for(long long i = 0; i < m; i++){
        ll a; cin >> a;
        oks[a] = false;
    }

    vector<ll> dp(n+1);
    dp[0] = 1;
    for(ll now = 0; now < n; ++now){
        for(ll next = now + 1; next <= min(n, now+2); ++next){
            if(oks[next]){
                dp[next] += dp[now];
                dp[next] %= ll(1e9+7);
            }
            //cout << "now:" << now << " dp[now]:" << dp[now] << " next:" << next << " dp[next]:" << dp[next] << endl;
        }
    }

    cout << dp[n] << endl;
}