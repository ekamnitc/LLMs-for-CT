#include <iostream>

typedef long long ll;

ll N;

int main() {
  std::cin >> N;
  ll ans = 0;
  for (ll i = 0; i < N; ++i) {
    ans += (N - i) * (N - i + 1) / 2;
    //std::cout << (N - i) * (N - i + 1) / 2 << "\n";
  }
  for (int i = 0; i < N-1; ++i) {
    ll u, v;  std::cin >> u >> v;
    if (u > v)  std::swap(u, v);
    ans -= u * (N - v + 1);
  }
  std::cout << ans << "\n";

  return 0;
}
