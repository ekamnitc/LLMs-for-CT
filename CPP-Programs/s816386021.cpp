#include "bits/stdc++.h"

#pragma warning(disable : 4996)

typedef long long ll;
#define all(x) (x).begin(), (x).end()  // sortなどの引数を省略
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define max3(x, y, z) max(x, max(y, z))
#define min3(x, y, z) min(x, min(y, z))

#ifdef _MSC_FULL_VER  //デバッグ出力
#define dout cout
#define debug() if (true)
#define check(x) std::cout << "★" << #x << "の値:" << (x) << endl
#define pass(x) std::cout << "☆" << x << endl
#else
#define dout \
  if (false) cout
#define debug() if (false)
#define check(x) \
  if (false) cout << "★" << #x << "の値:" << (x) << endl
#define pass(x) \
  if (false) cout << "☆" << x << endl
#endif

using namespace std;
//#define int long long;

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
ll idist(ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
using namespace std;

signed main() {
  string a;
  ll c = 0;
  cin >> a;
  rep(i, a.length()) {
    if (a[i] == '0')c += 0;
    if (a[i] == '1')c += 1;
    if (a[i] == '2')c += 2;
    if (a[i] == '3')c += 3;
    if (a[i] == '4')c += 4;
    if (a[i] == '5')c += 5;
    if (a[i] == '6')c += 6;
    if (a[i] == '7')c += 7;
    if (a[i] == '8')c += 8;
    if (a[i] == '9')c += 9;
  }
  if (c % 9 == 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }

}