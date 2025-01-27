#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

const int N=1e6+10;
ll a[N];
int sum[11];
main(){
    ios
    int h,w,n;cin>>h>>w>>n;
    h-=2,w-=2;
    int x,y;
    int cnt=0;
    ll m=(ll)h*w;
    rep(iii,n){
        cin>>x>>y;
        rep(i,3)if( x-i>=1 && x-i<=h){
            rep(j,3)if(y-j>=1 && y-j<=w){
            a[cnt++]=((ll)(x-i)<<32)+(y-j);
            }
        }
    }
    sort(a,a+cnt);
    ll t=1;
    rep(i,cnt){
        if(a[i]==a[i+1])t++;
        else sum[t]++,t=1,m--;
    }
    cout<<m<<" ";
    rep2(i,1,9)cout<<sum[i]<<" ";
}

