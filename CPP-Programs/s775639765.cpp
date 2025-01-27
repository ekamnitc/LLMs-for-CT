#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll calc (ll n) {
  return n*(n+1)/2;
}

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += i * calc(n/i);
  }
  cout << ans << endl;
  return 0;
}