#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll> 
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,ans=0;cin>>n;
  lvector A(n,0),B(n,0);
  rep(i,n) cin>>A[i]>>B[i];
  ll pos=n-1,res=0;
  while(pos>-1) {
    res=(A[pos]+ans)%B[pos];
    if(res!=0) ans+=B[pos]-res;
    pos--;
  }
  print(ans);
  return 0;
}