#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <bitset>

using namespace std;

typedef long long ll;

bitset<2000 * 2000 + 2> b;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  b[0] = 1;
  for (int i = 0; i < n; ++i) {
    b = b | (b << a[i]);
  }

  int i = (sum + 1) / 2;
  while (!b[i]) i++;

  cout << i << endl;

  return 0;
}
