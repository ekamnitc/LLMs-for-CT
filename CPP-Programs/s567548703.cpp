#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

const ll INF = 1e15;

int main() {
  ll m = INF;
  int k, n;
  cin >> k >> n;
  vector<int> as(n);
  rep(i, n) cin >> as[i];

  ll r, l;
  int n0 = k - as[n - 1] + as[0];
  m = l = r = as[n - 1] - as[0];
  for (int i = 1; i < n; i++) {
    r = (as[n - 1] - as[i]) + (as[i - 1] - as[0]) + n0;
    l = (as[n - i - 1] - as[0]) + as[n - 1] - as[n - i] + n0;
    m = min({m, r, l});
  }
  cout << m << endl;
  return 0;
}