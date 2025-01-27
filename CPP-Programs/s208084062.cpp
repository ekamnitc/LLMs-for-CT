#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define lld unsigned long long
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
vector<pll> a;
ll n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size(),flag=0;
        for(int i=0;i<(n+1)/2;i++)
        if(s[i]!=s[n-2-i])
        flag=1;
        vector<pii> edges;
        if(s[0]=='0'||flag||s[n-1]=='1')
        {
            cout<<"-1\n";
            continue;
        }
        int root=1,j=2;
        for(int i=0;i<(n+1)/2;i++)
        if(s[i]=='1')
        {
            edges.push_back({root,j});
            root=j;
            j++;
        }
        else
        {
            edges.push_back({root,j});
            j++;
        }
        for(int i=(n+3)/2;i<n;i++)
        {
            edges.push_back({root,j++});
        }
        for(int i=0;i<n-1;i++)
        cout<<edges[i].first<<" "<<edges[i].second<<"\n";
    }
    return 0;
}