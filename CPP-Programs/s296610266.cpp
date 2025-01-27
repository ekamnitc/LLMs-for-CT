#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll X;
  cin >> X;

  if(X <= 3){
    cout << 1 << endl;
    return 0;
  }

  ll sqX = (ll)sqrt(X) + 1;
  ll ans = -1;

  rep2(b, 2, sqX){
    ll num = b;
    while(num < X) num *= b;
    if(num > X) num /= b;
    ans = max(ans, num);
  }

  cout << ans << endl;
  
  return 0;
}
