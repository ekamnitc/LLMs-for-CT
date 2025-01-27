#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

const ld pi = 3.141592653589793;

#ifdef EBUG
#define debug(x) cout << "\033[31m" << #x << ": " << x << "\033[0m\n";
#else
#define debug(x)
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string sd, t;

int main() {
  cin >> sd >> t;
  rep(i, (sd.length() - t.length() + 1)) {
    bool f = false;
    rep(j, t.length()) {
      if (t[j] != sd[sd.length() - t.length() + j - i] && sd[sd.length() - t.length() + j - i] != '?') {
        f = true;
        break;
      }
    }
    if (!f) {
      string ans = "";
      rep(j, sd.length()) {
        if (j == i) {
          ans = t + ans;
          j += t.length() - 1;
        } else {
          if (sd[sd.length() - 1 - j] == '?') {
            ans = "a" + ans;
          } else {
            ans = sd[sd.length() - 1 - j] + ans;
          }
        }
      }
      // rep(k, sd.length()) {
      //   if (sd.length() - t.length() - i > k) {
      //     ans += t;
      //     k += t.length() - 1;
      //   } else {
      //     if (k < sd.length() - t.length()) {
      //       debug("!");
      //       if (sd[k] == '?') {
      //         ans += "a";
      //       } else {
      //         ans += sd[k];
      //       }
      //     } else {
      //       ans += t[k - (sd.length() - t.length())];
      //     }
      //   }
      // }
      cout << ans << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
}