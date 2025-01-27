#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

// macros
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const string res[3] = {"Vacant", "Male", "Female"};


bool listen(ll out, vll& c){
  string s;
  cout << out << endl;
  cin >> s;
  REP(i, 3){
    if(res[i] == s){
      if(i == 0)
        return true;
      else if(i == 1)
        c[out] = 1;
      else
        c[out] = -1;
    }
  }

  return false;
}


bool check(vll& c, ll x){
  ll valid;
  if(x%2 == 0)
    valid = c[0];
  else
    valid = c[0]*-1;

  return c[x] == valid;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  //man:1, woman:-1
  vll c(n, 0);

  if(listen(0, c))
    return 0;
  ll ok = 1;
  ll ng = n;
  while(abs(ok-ng) > 1){
    ll mid = (ok+ng)/2;
    if(listen(mid, c))
      return 0;
    if(check(c, mid))
      ok = mid;
    else
      ng = mid;
  }

  if(listen(ok, c))
    return 0;
}
