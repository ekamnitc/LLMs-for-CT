#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
const int mod=1000000007;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    ll n;cin>>n;
    string s;cin>>s;
    vi d(2*n);
    ll ans=1;
    if(s[0]=='W'||s[sz(s)-1]=='W'){
        cout<<0<<endl;
        return 0;
    }
    rep(i,sz(s)){
        if(i==0)d[i]=1;
        else if(s[i]==s[i-1]){
            if(d[i-1]==0)d[i]=1;
            else d[i]=0;
        }
        else if(s[i]!=s[i-1]){
            d[i]=d[i-1];
        }
    }
    ll cnt=0;
    rep(i,sz(s)){
        if(d[i]==1){
            cnt++;
        }
        else{ans*=cnt;ans%=mod;cnt--;}
        if(cnt<0){
            cout<<0<<endl;
            return 0;
        }
    }
    if(cnt!=0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){ans*=i;ans%=mod;}
    cout<<ans<<endl;
    return 0;
}