#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

#define get_bit(x, y) ((x >> y) & 1)

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m + 1);
  vector<int> p(m + 1);
  for (int i = 1; i <= m; i++) {
    int k; cin >> k;
    for (int j = 1; j <= k; j++) {
      int t; cin >> t;
      a[i].push_back(t);
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> p[i];
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    int b = 0;
    for (int j = 1; j <= m; j++) {
      int cnt = 0;
      for (auto &k : a[j]) {
        if (get_bit(i, k - 1)) cnt++;
      }
      if (cnt % 2 != p[j]) {
        b = 1;
        break;
      }
    }
    if (b == 0) ans++;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
