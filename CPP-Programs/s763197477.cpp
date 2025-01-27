#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  string s;
  cin >> s;
  int N = s.size();
  rep(i,(N-1)/2){
    if(s.at(i) != s.at(N-1-i)){
      cout << "No" << endl;
      return 0;
    }
  }
  rep(i,(N-1)/4){
    if(s.at(i) != s.at((N-1)/2-1-i)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" <<endl;
  return 0;
}