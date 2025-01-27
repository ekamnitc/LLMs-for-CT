  #include<bits/stdc++.h>
using namespace std;
using ll = long long;


#define debug(x) cout << #x << " = " << x << endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;
const ll mod = 1e9 + 7;

inline int cmp(double x, double y = 0) 
{  
  if(fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

ll exp(ll a, ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

const int maxn = 3e3 + 5;
ll fat[maxn], inv[maxn];

ll C(int n, int k)
{
  if(n < k) 
    return 0;
  if(n < 0 || k < 0) 
    return 0;
  return (((fat[n] * inv[k]) % mod) * inv[n - k]) % mod;
}

void initFactorials()
{
  fat[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < maxn; i++)
  {
    fat[i] = (i * fat[i-1]) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }
}

int n,m;

ll dp[maxn][maxn];

pair<int,int> a[maxn];

ll solve(int pos, int sum)
{
  if(sum >= m)
    return 0;
  if(pos == n )
    return 0;

  ll &ans = dp[pos][sum];
  if(ans != -1)
    return ans;

  ans = -(1LL << 60);
  ans = max(solve(pos + 1, sum), ans);
  ans = max(ans, solve(pos + 1, sum + a[pos].first) + a[pos].second);
  
  return ans;
}


int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
  {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + n);
  MSET(dp, - 1);
  cout << solve(0,0) << endl;
  return 0;
}