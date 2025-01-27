#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
  ll q,h,s,d;
  cin >> q >> h >> s >> d;
  ll n;
  cin >> n;
  vector<int> a(4);
  a[0] = q*8;
  a[1] = h*4;
  a[2] = s*2;
  a[3] = d;
  ll ans = 0;
  sort(a.begin(), a.end());
  if(a[0] == d && a[1] != d){
    while(n >= 2){
      ans += d;
      n -= 2;
    }
    while(n>0){
      ans += a[1]/2;
      n -= 1;
    }
  } 
  else ans = n * a[0]/2;
  cout << ans << endl;
return 0;
}