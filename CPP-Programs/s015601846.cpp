#include<bits/stdc++.h>
using namespace std;

int main(void){
  int x[3], ans;
  for(int i = 0; i < 3; i++)
    cin >> x[i];
  sort(begin(x), end(x));
  ans = x[2] * 10 + x[1] + x[0];
  cout << ans << "\n";
  return 0;
}
