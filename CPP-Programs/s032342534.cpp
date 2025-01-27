#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
/* clang-format on */

const int bits = 35;
const string pat = "LDUR";

int parity(ll x) { return (x % 2 + 2) % 2; }

int main() {
  int N;
  while (cin >> N) {
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    bool ok = true;
    for (int i = 0; i < N; i++)
      ok &= parity(X[i] + Y[i]) == parity(X[0] + Y[0]);
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    vector<ll> d;
    vector<string> w(N);
    if (parity(X[0] + Y[0]) == 0) {
      d.push_back(1);
      for (int i = 0; i < N; i++) {
        w[i] = "L";
        ++X[i];
      }
    }
    ll sum = 0;
    for (int j = 0; j < bits; j++) {
      d.push_back(1ll << j);
      sum += 1ll << j;
    }
    for (int i = 0; i < N; i++) {
      ll u = X[i] + Y[i];
      ll v = X[i] - Y[i];
      ll ur = (u + sum) / 2;
      ll vr = (v + sum) / 2;
      for (int j = 0; j < bits; j++) {
        int uk = (ur >> j) & 1;
        int vk = (vr >> j) & 1;
        int k = (uk << 1) | vk;
        w[i].push_back(pat[k]);
      }
    }
    cout << d.size() << endl;
    for (ll x : d) cout << x << " ";
    cout << endl;
    for (auto& x : w) cout << x << endl;
  }
  return 0;
}
