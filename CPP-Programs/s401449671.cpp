#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n; cin >> n;
  int k = __lg(n + 1);
  n -= (1LL << k) - 1;
  V<> res;
  for (int i = 0; i < k; i++) {
    if (n & 1) res.push_back(2 * i);
    n >>= 1;
  }
  for (int i = k; i; i--) res.push_back(2 * i - 1);
  for (int i = 99; i >= 0; i--) res.push_back(i);
  int m = res.size();
  cout << m << '\n';
  for (int i = 0; i < m; i++) cout << res[i] + 1 << (i != m - 1 ? ' ' : '\n');
}