#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const int MAX = 5100000;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}


int main(){
  long long x, y;
  cin >> x >> y;
  
  long long cntx = (2*x-y)/3, cnty = x - 2*cntx;
  if((2*x-y)%3 != 0){
    cout << 0 << endl;
    return 0;
  }
  
  COMinit();
  cout << COM(cntx+cnty, cnty) << endl;
}