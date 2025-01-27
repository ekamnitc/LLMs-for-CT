#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-15;
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
const ll MOD1 = 998244353;
//typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int n,k;
vector<int> G[2010];
vector<pair<int,int>> P;
bool used[2010];
pair<int,int> no;

int dfs(int v, int d) {
  if (used[v]) return 0;
  used[v] = 1;
  int ans = (d > k / 2);
  for (int i = 0; i < G[v].size(); i++) {
    if ((v == no.fi && G[v][i] == no.se) || (v == no.se && G[v][i] == no.fi)) continue;
    ans += dfs(G[v][i], d + 1);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  REP(i,n-1) {
    int a,b;
    cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
    if (a > b) swap(a,b);
    P.pb({a,b});
  }

  int ans = inf;
  if (k&1) {
    REP(i,n-1) {
      REP(j,2010) used[j] = 0;
      no = P[i];
      ans = min(ans, dfs(no.fi,0) + dfs(no.se,0));
    }
  } else {
    REP(i,n) {
      REP(j,2010) used[j] = 0;
      ans = min(ans, dfs(i+1,0));
    }
  }

  cout << ans << endl;
  return 0;
}
