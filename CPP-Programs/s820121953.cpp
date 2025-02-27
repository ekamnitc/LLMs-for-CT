#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define BITS(n, num) std::bitset<(n)>((num)).to_string()
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define SP(a) setprecision(a)

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  vl A(N, 0), B(N, 0);
  vvl C = VVL(31, N, 0);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  REP(i, 31) {
    REP(j, N) { C[i][j] = B[j] % (1LL << (i + 1)); }
    sort(ALL(C[i]));
  }
  ll ans = 0;
  REP(i, 31) {
    ll yo = 0;
    // cout << i << endl;
    AUTO(a, A) {
      ll po = a % (1LL << (i + 1));
      auto t1 = lower_bound(ALL(C[i]), (1LL << i) - po);
      auto t2 = lower_bound(ALL(C[i]), 2LL * (1LL << i) - po);
      auto t3 = lower_bound(ALL(C[i]), 3LL * (1LL << i) - po);
      auto t4 = lower_bound(ALL(C[i]), 4LL * (1LL << i) - po);

      ll pos1 = distance(C[i].begin(), t1);
      ll pos2 = distance(C[i].begin(), t2) - 1;
      ll pos3 = distance(C[i].begin(), t3);
      ll pos4 = distance(C[i].begin(), t4) - 1;

      yo = (yo + (pos2 - pos1 + 1) + (pos4 - pos3 + 1)) % 2;
    }
    if (yo % 2 == 1)
      ans += 1LL << i;
  }
  cout << ans << endl;

  return 0;
}
