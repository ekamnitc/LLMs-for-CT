#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int p,q,r;
  cin>>p>>q>>r;
  int ans=0;
  ans=min(p+q,q+r);
  ans=min(ans,r+p);
  cout<<ans<<endl;
  return 0;
}