#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  ll ans = 0;
  ll x;
  cin >> x;
  string s = to_string(x);
  ll n;
  n = s.size() - 1;
  vector<ll> t(n+1);
  rep(i,n+1){
    t[n-i] = x % 10;
    x = x / 10;
  }
  
  for (ll bit = 0; bit < (1<<n); ++bit){
    ll sum = t[0];
    for(ll i = 0; i < n; i++){
     if(bit & (1<<i)){
       ans = ans + sum;
       sum = 0;
       sum = t[i+1];
       
     }
     else{
       
       sum = 10 * sum + t[i+1]; 
     }
    }
    
    ans = ans + sum;
       
        

    }
  cout << ans;
  return 0;
}
