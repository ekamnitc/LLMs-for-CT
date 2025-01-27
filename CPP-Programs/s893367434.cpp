#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  bool ok = false;

  for (int i = 0; i <= n; ++i) {
    if (floor(i * 1.08) == n) {
      std::cout << i << std::endl;
      ok = true;
      break;
    }
  }
  if (!ok) {
    std::cout << ":(" << std::endl;
  }
  return 0;
}
