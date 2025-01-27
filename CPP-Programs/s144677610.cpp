#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};

ll F[110][5][2];

int main(){

  int n;
  cin >> n;
  REP(i,n)REP(j,5)REP(k,2)cin >> F[i][j][k];
  vector<vector<ll>> p(100,vector<ll>(11,0));
  REP(i,n)REP(j,11)cin >> p[i][j];
  ll res = (-1ll)*(1ll << 40);
  for(int bit = 0;bit < (1 << 5);bit++){
    vector<bool> b(5,0);
    REP(i,5)if(bit >> i & 1)b[i] = true;
    for(int bits = 0;bits < (1 << 5);bits++){
      if(bit == 0 && bits == 0)continue;
      vector<bool> a(5,0);
      REP(i,5)if(bits >> i & 1)a[i] = true;
      vector<int> many(n,0);
      REP(i,n)REP(j,5)if(b[j] && F[i][j][0])many[i]++;
      REP(i,n)REP(j,5)if(a[j] && F[i][j][1])many[i]++;
      ll sum = 0;
      REP(i,n)sum += p[i][many[i]];
      res = max(res,sum);
    }
  }

  cout << res << endl;





  return 0;
}