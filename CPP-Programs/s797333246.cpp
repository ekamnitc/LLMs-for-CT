#include <cstring>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
const int MAXN = (int)1e5 + 5;

P td[MAXN];
int cnts[MAXN];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int t; ll d;
    cin >> t >> d;
    td[i] = P(d, t);
  }

  sort(td, td + n, greater<P>());

  ll ans = 0, cnt = 0, tmp = 0;
  priority_queue<P, vector<P>, greater<P> > q;
  for (int i = 0; i < k; ++i) {
    tmp += td[i].first;
    if (!cnts[td[i].second])  {
      cnt++;
    } else {
      q.push(td[i]);
    }
    cnts[td[i].second]++;
  }

  ans = tmp + cnt * cnt;
  for (int i = k; i < n; ++i) {
    if (q.empty()) break;
    if (cnts[td[i].second]) continue;
    P c = q.top(); q.pop();
    ll d = c.first;
    int idx = c.second;
    tmp = tmp - d + td[i].first;
    cnt++;
    cnts[idx]--;
    cnts[td[i].second]++;
    ans = max(ans, tmp + cnt * cnt);
  }

  cout << ans << endl;
  return 0;
}
