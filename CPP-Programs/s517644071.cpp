#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1e12

#define PB push_back
#define PF push_front
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vpi vector<pii>
#define vll vector<ll>
#define vpl vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ud(c, x) distance(c.begin(), upper_bound(all(c), x))
#define ud(c, x) distance(c.begin(), lower_bound(all(c), x))
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, a, b) for (int i = a, i < b; ++i)
#define rep3(i, n) for (int i = n - 1; i >= 0; ++i)
bool odd(int i) { return i % 2; }

#define all(v) v.begin(), v.end()
#define size(x) int(x.size())

int gcd(int a, int b) { return __gcd(a, b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
void solve(void) {
  string s;
  cin >> s;
  int len = s.length();
  int ans = 0;
  rep(i, len) {
    int indx = len - i;
    if (indx < len && !odd(indx)) {
      string x = s.substr(0, indx);
      string l = x.substr(0, indx / 2);
      string r = x.substr(indx / 2, indx / 2);
      if (l == r) ans = max(ans, indx);
    }
  }
  cout << ans << endl;
}
int main(void) { solve(); }
