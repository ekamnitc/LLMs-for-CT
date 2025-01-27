#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define mod 1000000007
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=16,MAX=(ll)-1e15 ;
ll dp[(1<<N)] ;
ll cost[(1<<N)] ;
ll n ;
ll a[N][N] ;
ll fun(ll i)
{
    if(i==0) return 0 ;
    else if(dp[i]!=MAX) return dp[i] ;
    else
    {
        ll mask=i ;
        ll f=0 ;
        ll ans=MAX ;
        while(mask>0)
        {
            ans=max(ans,cost[mask]+fun(i-mask)) ;
            mask=i&(mask-1) ;
        }
        return dp[i]=ans ;
    }
}
int main()
{
    fast ;
    cin>>n ;
    for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) cin>>a[i][j] ;

    for(ll i=0;i<(1<<n);i++) dp[i]=MAX ;

    memset(cost,0,sizeof(cost)) ;

    for(ll mask=0;mask<(1<<n);mask++)
    {
        vector<ll>v ;
        for(ll j=0;j<n;j++)
        {
            ll bit=mask&(1<<j) ;

            if(bit) v.push_back(j) ;
        }
        cost[mask]=0 ;
        for(ll j=0;j<v.size();j++)
        {
            for(ll k=j+1;k<v.size();k++)
            {
                cost[mask]+=a[v[j]][v[k]] ;
            }
        }
    }

    cout<<fun((1<<n)-1) ;






}

