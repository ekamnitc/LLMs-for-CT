#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> vh(n);
  for (int i = 0; i < n; ++i) {
    cin >> vh[i];
  }

  int b = 1000 * (t - a);
  int min_idx = 0, min_n = abs(b - vh.front() * 6);
  for (int i = 0; i < vh.size(); ++i) {
    int c = abs(b - vh[i] * 6);
    if (min_n > c) {
      min_n = c;
      min_idx = i;
    }
  }

  cout << min_idx + 1 << '\n';
}
