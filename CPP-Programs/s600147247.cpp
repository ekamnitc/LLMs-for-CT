#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  ll sum = 1;
  vector<ll> vec(N);
  rep(i, N){
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  if(vec.at(0) == 0){
    cout << 0 << endl;
    return 0;
  }else{
    rep(i, N){
      if(sum >= (1000000000000000000 / vec.at(i)) + 1){
        cout << -1 << endl;
        return 0;
      }else{
        sum = sum * vec.at(i);
      }
   }
   cout << sum << endl;
  }
}