#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> vx(n), vy(n);
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    vx[i] = x + y;
    vy[i] = x - y;
  }

  ll vx_max = *max_element(vx.begin(), vx.end());
  ll vx_min = *min_element(vx.begin(), vx.end());
  ll vy_max = *max_element(vy.begin(), vy.end());
  ll vy_min = *min_element(vy.begin(), vy.end());

  cout << max(vx_max - vx_min, vy_max - vy_min) << endl;
}