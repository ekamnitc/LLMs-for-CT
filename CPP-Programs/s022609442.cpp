#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  int ans[h][w];
  rep(i,h)rep(j,w)ans[i][j]=0;
  rep(i,h-b){
    rep(j,a){
      ans[i][j]=1;
    }
  }
  rep(i,b){
    rep(j,w-a){
      ans[h-i-1][w-1-j]=1;
    }
  }
  rep(i,h){
    rep(j,w)cout << ans[i][j];
    cout << endl;
  }
}
