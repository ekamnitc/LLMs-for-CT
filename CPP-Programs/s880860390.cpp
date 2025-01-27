#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  std::vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  long double total = 0.0;
  rep(i,n) {
    total += 1.0 / a.at(i);
  }
  cout << std::fixed << std::setprecision(12) << 1.0 / total << endl;
}
