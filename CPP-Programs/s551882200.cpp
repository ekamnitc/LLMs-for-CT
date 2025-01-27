#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, k;
  cin >> a >> b >> k;
  set<int> s;
  for (int i = a; i <= min(a + k - 1, b); i++) s.insert(i);
  for (int i = max(b - k + 1, a); i <= b; i++) s.insert(i);
  for (auto i : s) cout << i << '\n';
}
