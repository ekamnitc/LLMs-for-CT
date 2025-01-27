#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  bool zero = true;
  rep(i, n) {
    ll a;
    cin >> a;
    if(a != 0) zero = false;
    mp[a]++;
  }
  if(zero) {
    cout << "Yes" << endl;
    return 0;
  }
  if(n % 3 != 0 || mp.size() > 3 || mp.size() == 1) {
    cout << "No" << endl;
    return 0;
  }
  if(mp.size() == 3) {
    bool ok = true;
    ll xs = 0;
    for(auto v : mp) {
      xs ^= v.first;
      if(v.second != n / 3) ok = false;
    }
    cout << ((xs == 0) && ok ? "Yes" : "No") << endl;
    return 0;
  }
  ll a, b;
  bool ok = true;
  for(auto v : mp) {
    if(v.second == n / 3 * 2)
      a = v.first;
    else if(v.second == n / 3)
      b = v.first;
    else
      ok = false;
  }
  cout << ((b == 0) && ok ? "Yes" : "No") << endl;
}