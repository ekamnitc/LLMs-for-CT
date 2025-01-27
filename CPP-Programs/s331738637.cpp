#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int h, a;
  cin >> h >> a;
  if (h % a == 0) {
    cout << h / a << endl;
  } else {
    cout << h / a + 1 << endl;
  }
  return 0;
}
