#include<bits/stdc++.h>
#pragma 03

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repp(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define ll long long


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const long long mod=1000000007;

int n,m,x,y,z,sz;
vector<vi> g;
bool visited[100001];

void dfs(int u) {
	visited[u]=true;
	rep(i,0,(int)g[u].size()-1) {
		int v=g[u][i];
		if(!visited[v]) dfs(v);
	}
}

signed main() {
	   fastio;
	   // freopen(".inp","r",stdin); freopen(".out","w",stdout);
	   cin >> n >> m;
	   g.assign(n+1,vi());
	   memset(visited,false,sizeof(visited));
	   rep(i,1,m) {
	   	cin >> x >> y >> z;
	   		g[x].pb(y);
	   		g[y].pb(x);
	   }
	   sz=0;
		rep(i,1,n) {
			if(!visited[i]) {
				dfs(i);
				sz++;	
			}
		}
	   cout << sz;
}

