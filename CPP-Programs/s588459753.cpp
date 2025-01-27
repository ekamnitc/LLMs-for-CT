#include <bits/stdc++.h>
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main(){
  int x,y,a,b,c; cin >>x >>y >>a >>b >>c; ll ans=0;
  vector<int>p(a); vector<int>q(b); vector<int>r(x+y+c);
  for(int i=0; i<a; i++) cin >>p[i];
  sort(p.rbegin(),p.rend());
  for(int i=0; i<x; i++) r[i]=p[i];
  for(int i=0; i<b; i++) cin >>q[i];
  sort(q.rbegin(),q.rend());
  for(int i=0; i<y; i++) r[x+i]=q[i];
  for(int i=0; i<c; i++) cin >>r[x+y+i];
  sort(r.rbegin(),r.rend());
  for(int i=0; i<x+y; i++) ans+=r[i];
  cout <<ans;
return 0;}