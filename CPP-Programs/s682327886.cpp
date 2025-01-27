#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}



int main() {
  int H,W;
  cin >> H >> W;
  vector<string> g(H);
  rep(i,H) cin >> g[i];
  vector<vector<int>> memo(H,vector<int>(W,10000));
  memo[0][0]=0;
  rep(i,H){
    rep(j,W) {
      if (i>0) {if (g[i][j]==g[i-1][j]) chmin(memo[i][j],memo[i-1][j]);
      else chmin(memo[i][j],memo[i-1][j]+1);}
      if (j>0) {if (g[i][j]==g[i][j-1]) chmin(memo[i][j],memo[i][j-1]);
      else chmin(memo[i][j],memo[i][j-1]+1);}
    }
  }
  int res=memo[H-1][W-1];
  if (res%2==1) res = (res+1)/2;
  else if (g[0][0]=='#') res = res/2+1;
  else res/=2;
  cout << res << endl;
}