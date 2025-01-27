//Compiler optimization
#pragma GCC optimize("Ofast")

//include
#include <bits/stdc++.h>
using namespace std;

//typedef
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef string S;
typedef queue<int> qi;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<vl> mat;

//macro
#define reverse(a) reverse(a.begin(),a.end())
#define unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define fr(i,n)for(ll i=0;i<(n);i++)
#define ifr(i,n)for(ll i=(n)-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define each(x, v) for (auto &x : v)

//abbreviation
#define pb push_back
#define elif else if
#define mp make_pair
#define endl '\n'

//debug
#define debug(x) cerr << #x << ": " << x << endl
#define v_debug(v) cerr << #v << endl;fr(i,v.size()) cerr << i << ": " << v[i] << endl

//const
const  ll INF = 1e18;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(20);
    ll n,m,k;cin >> n>> m>> k;
    vl a(n), b(m);
    fr(i,n)cin >> a[i];
    fr(i,m)cin>> b[i];
    vl a_sum(n+1), b_sum(m+1);
    a_sum[0] = b_sum[0] = 0;
    fr(i,n)a_sum[i+1] = a_sum[i] + a[i];
    fr(i,m)b_sum[i+1] = b_sum[i] + b[i];
    ll ans = 0, now = 0;
    ll ok = 0, ng = m, mid;
    fr(i,n+1){
        now = a_sum[i];
        //debug(now);
        if(now + b_sum[m] <= k){
            ans = max(ans, i+m);
            continue;
        }
        if(now > k)break;
        ok = 0;
        ng = m;
        while(ng - ok > 1){
            mid = (ok + ng)/2;
            if(now + b_sum[mid] <= k)ok = mid;
            else ng = mid;
        }
        ans = max(ans, i + ok);
    }
    cout << ans << endl;
}