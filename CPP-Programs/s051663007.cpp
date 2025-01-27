#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  map<ll,ll> mp;
  mp[0]++;
  ll s = 0;
  rep(i,n){
    ll a;
    cin >> a;
    s += a;
    mp[s] ++;
  }
  ll ans = 0;
  for(auto p : mp){
    ll q = p.second;
    ans += q*(q-1)/2;
  }
  cout << ans << endl;
}