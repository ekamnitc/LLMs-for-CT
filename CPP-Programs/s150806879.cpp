#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  int ans = INF;
  for (int p = 1; p <= 100; p++) {
    int temp = 0;
    for(int x: v) {
      temp += pow((x-p), 2);
    }
    ans = min(ans, temp);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}