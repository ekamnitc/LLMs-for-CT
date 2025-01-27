#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int all = 0;
  rep(i, n) {
    cin >> a[i];
    all ^= a[i];
  }
  rep(i, n) {
    cout << (a[i] ^ all) << ' ';
  }
  cout << '\n';
  return 0;
}
