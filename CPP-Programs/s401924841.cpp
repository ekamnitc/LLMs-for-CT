#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

// void add(ll &a, ll b){
//     a += b;
//     if(a>=MOD) a -= MOD;
// }

// int main(){
//     string S;
//     cin>>S;
//     vector<vector<ll>> dp(S.size()+1,vector<ll>(13,0));
//     dp[0][0] = 1;
//     rep(i,S.size()){
//         rep(j,13){
//             if(S[i]=='?'){
//                 rep(k,10){
//                     add(dp[i+1][(j*10+k)%13],dp[i][j]);
//                 }
//             }else{
//                 int k = S[i] - '0';
//                 add(dp[i+1][(j*10+k)%13],dp[i][j]);
//             }
//         }
//     }
//     cout<<dp[S.size()][5]<<endl;
// }

int main(){
    int a,b;cin>>a>>b;
    int ans = 0;
    int out = 1;
    while(out<b){
        --out;
        out += a;
        ++ans;
    }
    cout<<ans<<endl;
}