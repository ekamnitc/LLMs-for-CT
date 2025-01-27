#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
int pos [MAX_N];

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }

  set<int> seen;
  seen.insert(-1);
  seen.insert(n);

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll nxt = *seen.upper_bound(pos[i]);
    ll prv = *prev(seen.upper_bound(pos[i]));
    ll cur = pos[i];

    ans += (nxt - cur) * (cur - prv) * (ll) i;
    
    seen.insert(pos[i]);
  }

  cout << ans << endl;
}
