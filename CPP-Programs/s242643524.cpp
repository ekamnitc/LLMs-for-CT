#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }
ll MOD = 1000000007;

int main(void){
  ll n,m; cin >> n >> m;
  ll a[n];
  vector<pair<ll,ll>> ans;
  rep(i,n){
    cin >> a[i];
    ans.push_back(make_pair(a[i],1));
  }
  ll b[m],c[m];
  rep(i,m){
    cin >> b[i] >> c[i];
    ans.push_back(make_pair(c[i],b[i]));
  }
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  ll sum = 0;
  ll true_ans = 0;
  ll i = 0;
  while(sum <= n){
    true_ans += ans.at(i).first * ans.at(i).second;
    sum += ans.at(i).second;
    if(sum >= n) break;
    i++;
  }
  ll x = ans.at(i).first;
  true_ans -= (sum-n)*x;
  cout << true_ans << endl;
  return 0;
}
