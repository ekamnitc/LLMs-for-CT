#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n,a[100010],ans[100010]={},m=0;
    vll v;
    map<ll,ll> mp,cnt;
    cin>>n;
    rep(i,n){
        cin>>a[i];
        v.pb(a[i]);
        m=max(m,a[i]);
        cnt[a[i]]++;
        if(mp[a[i]]==0) mp[a[i]]=i+1;
    }
    sort(all(v));
    ERASE(v);
    reverse(all(v));
    if(v[v.size()-1]!=1){
        v.pb(1);
        mp[1]=1;
    }
    ll now=cnt[m],index=mp[m];
    ans[index]+=now;
    rep2(i,1,(ll)v.size()){
        ans[index]+=now*(v[i-1]-v[i]-1);
        index=min(index,mp[v[i]]),now+=cnt[v[i]];
        ans[index]+=now;
        // cout<<v[i]<<" "<<index<<" "<<now<<endl;
    }
    rep2(i,1,n+1){
        cout<<ans[i]<<endl;
    }
  cerr<<0<<endl;
    return 0;
}
