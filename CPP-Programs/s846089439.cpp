#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >;
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
typedef long long ll;
const int INF = 2000000000;
const ll INF64 = 1000000000000000ll;
const ll MOD = 1000000007LL;

int main(){
    int n;
    std::cin >> n;
    std::vector<ll> a(n),b(n);
    rep(i,n)std::cin >> a[i];
    rep(i,n)std::cin >> b[i];
    if(sum(all(a),0ll)<sum(all(b),0ll)){
        std::cout << -1 << std::endl;
        exit(0);
    }
    std::vector<ll> g;
    ll di=0ll;
    int ans=0;
    rep(i,n){
        if(a[i]>b[i])g.pb(a[i]-b[i]);
        if(a[i]<b[i]){
            ans++;
            di+=b[i]-a[i];
        }
    }
    sort(all(g),greater<ll>());
    int i=0;
    while(di>0ll){
        di-=g[i];
        i++;
        ans++;
    }
    std::cout << ans << std::endl;
}
