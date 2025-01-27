#include <bits/stdc++.h>
using namespace std;


int main() {
  long long N;
  cin >> N;
  long long ans = 0;
  vector<long long> a(N);
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  long long term = 0;
  bool loop_end = false;
  
  
  for (int jsndfjn = 0; jsndfjn <= 100000000000; jsndfjn++) {
    loop_end = true;
    term = 0;
    for (int i=0; i<N; i++) {
      if (a[i] >= N) {
        term += (a[i] / N);
        a[i] -= (N+1) * (a[i]/N);
        loop_end = false;
      }
    }
    cerr << term << endl;
    if (loop_end) {
      break;
    }
    ans += term;
    for (int i=0; i<N; i++) {
      a[i] += term;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}