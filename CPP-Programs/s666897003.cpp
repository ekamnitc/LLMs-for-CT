#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

struct IOSetup{
    IOSetup(){
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout<<fixed<<setprecision(12);
    }
} iosetup;

template<typename T1,typename T2>
ostream &operator<<(ostream &os,const pair<T1,T2>&p){
    os<<p.first<<" "<<p.second;
    return os;
}

template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(int i=0;i<(int)v.size();i++) os<<v[i]<<(i+1==v.size()?"":" ");
    return os;
}


signed main(){
    int n;cin>>n;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u,v;cin>>u>>v;u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> c(n,-1);
    function<void(int,int)> dfs=[&](int pre,int now){
        int b=0;
        for(auto to:g[now])if(pre!=to){
            dfs(now,to);
            if(c[to]==0) b++;
        }

        if(b) c[now]=1;
        else c[now]=0;
    };dfs(-1,0);

    int b=0;
    rep(i,n)if(c[i]==0)b++;
    int w=n-b;
    if(b>w)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}
