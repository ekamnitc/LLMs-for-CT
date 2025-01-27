#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;

int getidx(int x, int n) { return x + n; }

int main() {
  //
  string s;
  cin >> s;
  int n = s.size();
  ll X, Y;
  cin >> X >> Y;
  bool xmove = true;
  vl dx, dy;
  ll cnt = 0;
  rep(i, s.size()) {
    if (s[i] == 'F') {
      cnt++;
    } else {
      if (xmove) {
        // cerr << "dx:" << cnt << endl;
        dx.push_back(cnt);
      } else {
        // cerr << "dy:" << cnt << endl;
        dy.push_back(cnt);
      }
      xmove = !xmove;
      cnt = 0;
    }
  }
  if (cnt > 0) {
    if (xmove) {
      // cerr << "dx:" << cnt << endl;
      dx.push_back(cnt);
    } else {
      // cerr << "dy:" << cnt << endl;
      dy.push_back(cnt);
    }
  }

  vector<vector<bool>> dpx(2, vector<bool>(2 * n + 1, false));
  vector<vector<bool>> dpy(2, vector<bool>(2 * n + 1, false));
  dpx[0][getidx(0, n)] = true;
  if (dx.size() > 0) {
    dpx[1][getidx(dx[0], n)] = true;
    // cerr << getidx(dx[0], n) << endl;
  }
  for (int i = 1; i < dx.size(); i++) {
    for (int x = -n; x <= n; x++) {
      dpx[(i + 1) & 1][getidx(x, n)] = false;
    }
    for (int x = -n; x <= n; x++) {
      if (dpx[i & 1][getidx(x, n)] == true) {
        if (x - dx[i] >= -n) dpx[(i + 1) & 1][getidx(x - dx[i], n)] = true;
        if (x + dx[i] >= -n) dpx[(i + 1) & 1][getidx(x + dx[i], n)] = true;
      }
    }
  }
  // cerr << "!" << endl;
  dpy[0][getidx(0, n)] = true;
  for (int i = 0; i < dy.size(); i++) {
    for (int y = -n; y <= n; y++) {
      dpy[(i + 1) & 1][getidx(y, n)] = false;
    }
    for (int y = -n; y <= n; y++) {
      if (dpy[i & 1][getidx(y, n)] == true) {
        if (y - dy[i] >= -n) dpy[(i + 1) & 1][getidx(y - dy[i], n)] = true;
        if (y + dy[i] >= -n) dpy[(i + 1) & 1][getidx(y + dy[i], n)] = true;
      }
    }
  }
  if (dpx[(dx.size()) & 1][getidx(X, n)] &&
      dpy[(dy.size()) & 1][getidx(Y, n)]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
