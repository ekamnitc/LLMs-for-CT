#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  int cnt=0,ans=1e9;
  rep(i,n){
    ans=min(ans,a[i]);
    if(ans==a[i])cnt++;
  }
  cout<<cnt<<endl;
}