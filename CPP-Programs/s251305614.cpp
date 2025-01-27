#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n,0);
  int k;
  for (int i = 0; i < n; i++) {
    cin >> k;
    vec.at(i) += k;
  }
  int now = 1;
  for (int i = 0; i < n; i++) {
    if (now == 2) {
      cout << i << endl;
      break;
    }
    now = vec.at(now-1);
    if (i == n-1) {
      cout << -1 << endl;
    }
  }
}