#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> x(n);
  rep(i,n) cin >> x[i];
  
  ll ans = 0;
  rep(i,n){
    int aMove = x[i]*2;
    int bMove = (k-x[i])*2;
    ans += min(aMove,bMove);
  }
  
  cout << ans << endl;
}