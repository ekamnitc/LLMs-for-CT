#include<bits/stdc++.h>
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Freed freopen ("0in.txt","r",stdin);
#define Fout freopen ("0out.txt","w",stdout);
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define Mod 1000000007
#define limit 1000008
using namespace std;
bool vis[limit];
vector<int>g[limit];
void dfs(int u)
{
    vis[u] = 1;
    for(int v:g[u])
    {
        if(!vis[v])
            dfs(v);
    }
}
void solve(int t)
{
    int i,j,n,m,k;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int ct=0;
    dfs(1);
    for(i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            ct++;
            dfs(i);
        }
    }
    cout <<ct<<endl;
    return ;
}
int  main()
{
//    Fast
//    Freed
//    Fout
    int t,tt=1;
  //  cin >> tt;
    for(t=1; t<=tt; t++)
        solve(t);
    return 0;
}

