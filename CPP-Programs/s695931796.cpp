#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int maxN=40,maxab=10;

int main(){
    int n,ma,mb; cin>>n>>ma>>mb;
    int a[maxN],b[maxN],c[maxN];
    rep(i,n) cin>>a[i]>>b[i]>>c[i];
    int dp[maxN+1][maxN*maxab+1][maxN*maxab+1];

    rep(i,n+1){
        rep(cnta,maxN*maxab+1){
            rep(cntb,maxN*maxab+1){
                dp[i][cnta][cntb] = 1e9;
            }
        }
    }

    dp[0][0][0] = 0;

    rep(i,n){
        rep(cnta,maxN*maxab+1){
            rep(cntb,maxN*maxab+1){
                if(dp[i][cnta][cntb]==1e9) continue;
                chmin(dp[i+1][cnta][cntb],dp[i][cnta][cntb]);
                chmin(dp[i+1][cnta+a[i]][cntb+b[i]], dp[i][cnta][cntb]+c[i]);
            }
        }
    }
    int ans = 1e9;
    for(int cnta=1;cnta<=maxN*maxab;cnta++){
        for(int cntb=1;cntb<=maxN*maxab;cntb++){
            if(cnta*mb==cntb*ma) chmin(ans,dp[n][cnta][cntb]);
        }
    }
    if(ans==1e9) ans=-1;
    cout << ans << endl;
}

