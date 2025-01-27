#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  
  vector<string> S(N);
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> S.at(i) >> A.at(i);
  string X;
  cin >> X;
  
  int ans = 0;
  bool fg = false;
  for( int i = 0; i < N; i++ ){
    if( fg ){
      ans += A.at(i);
    }
    if( S.at(i) == X ) fg = true;
  }
  cout << ans << endl;
    
}
  
