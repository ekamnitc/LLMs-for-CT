#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  string ans="No";
  cin >> n;
  for(long i=0;i<100;i++) {
    for(long j=0;j<100;j++) {
      if(i*4+j*7==n) ans="Yes";
    }
  }
  cout << ans << endl;
}