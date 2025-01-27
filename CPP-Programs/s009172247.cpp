#include <bits/stdc++.h>
using namespace std;

int main() {
  uint64_t x = 100;
  uint64_t a;
  cin >> a;
  
  int cnt = 0;
  while (x < a) {
    x += x / 100;
    ++cnt;
  }
  cout << cnt << endl;
}