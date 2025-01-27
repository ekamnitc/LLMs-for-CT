#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  int N; cin >> N;
  vector<int> v(N, N+1); v[1] = 1;

  queue<int> z, o;
  z.push(1); o.push(1);
  vector<bool> ok(N,false);
  while(v[0]==N+1) { 
    if (!z.empty()){
      int n = z.front();
      z.pop();
      if (!ok[(n*10)%N]) {
        v[(n*10)%N] = v[n];
        z.push((n*10)%N);
        o.push((n*10)%N);
        ok[n] = true;
      }
    }
    else {
      int n = o.front();
      o.pop();
      if (!ok[(n+1)%N]) {
        v[(n+1)%N] = v[n]+1;
        z.push((n+1)%N);
        o.push((n+1)%N);
        ok[n] = true;
      }
    }
  }

  cout << v[0] << endl;
  return 0;
}