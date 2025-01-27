#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  REP(i, A) cin >> a.at(i);
  REP(i, B) cin >> b.at(i);
  int ans = 200000;
  REP(i, M) {
    int x, y, c;
    cin >> x >> y >> c;
    int after_dis = a.at(x-1) + b.at(y-1) - c;
    if (after_dis < ans) ans = after_dis;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int cash = a.at(0) + b.at(0);
  if (cash < ans) ans = cash;
  cout << ans << endl;
  return 0;
}