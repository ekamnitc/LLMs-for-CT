#include <bits/stdc++.h>
using namespace std;

int main() {
  long long H,ans = 0,x=1;
  cin >> H;
  for(long long i=0; i<100; i++){
    if(H == 0){
      cout << ans  << endl;
      return 0;
    }
    else{
    ans += x;
    H /= 2;
    x *= 2;
    }
  }
}
