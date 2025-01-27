#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = INT_MAX / 2;

int main() {
  int N; int M; cin >> N >> M;
  // M = G * (a_1 / G + ... a_N / G)
  // M = G * (1 + 1 + ... + 1 + c_N)
  bool is_prime = 1;
  for (int i = 2; (ll)i * i <= M; i++) {
    if (M % i == 0) {
      is_prime = 0;
      break;
    }
  }
  if (is_prime) {
    cout << 1 << "\n";
    return 0;
  }
  for (int c_N = 1; ; c_N++) {
    if (M % (N - 1 + c_N) == 0) {
      auto G = M / (N - 1 + c_N);
      cout << G << "\n";
      return 0;
    }
  }
}
