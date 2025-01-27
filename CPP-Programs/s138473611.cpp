/*Ankon Ghosh
  KUET,ECE 2K16*/
#include<bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
///#include <ext/pb_ds/detail/standard_policies.hpp>*/
///using namespace __gnu_pbds;
using namespace std;
using ll=long long;
#define inf 1e16
#define MAX 100005
#define mod 998244353
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define Case(i) printf("Case %lld: ",i)
#define setpre(number) cout<<fixed<<setprecision(10)<<number<<endl
#define pf(a) printf("%lld ",a)
#define pff(a,b) printf("%lld %lld\n",a,b)
#define FOR(i,n) for(ll i=0;i<n;i++)
#define FOR1(i,n) for(ll i=1;i<=n;i++)
#define LOOP(x,y) for(ll i=x;i<=y;i++)
#define RFOR(i,n) for(ll i=n-1;i>=0;i--)
#define RFOR1(i,n) for(ll i=n;i>0;i--)
#define RLOOP(x,y) for(ll i=y;i>=x;i--)
#define m_p make_pair
#define ff first
#define ss second
#define p_b push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define output freopen("output.txt","w",stdout)
map<ll,ll>mp1,mp;
vector<pair<ll,pair<ll,ll> > >vpp1;
vector<pair<ll,ll> >vpp,vp1;
vector<ll>v,v1,v2,fin;
map<pair<ll,ll>,bool>mbb;
map<ll,bool>mb,mb1;
ll a,b,c,n,d,e,f,ta,sum=0,cnt=0,m,l,req,sz,maxi,k;
priority_queue<ll>pq;

int main()
{
    fast;
    cin>>n;
    v.clear();
    FOR(i,n)
    {
        cin>>a;
        v.p_b(a);
    }
    ll now=0,ans=0;
    for(ll i=0;i<n;i++)
    {
        if(v[i]>now)
        {
            ans+=(v[i]-now);
            now=v[i];
        }
        else
        {
            now=v[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}