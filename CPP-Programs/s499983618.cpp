#include<bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < q; i++) {
    int j;
    cin >> j;
    a[j-1]++;
  }
  for (int i = 0; i < n; i++) {
    if (k <= q - a[i]) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}