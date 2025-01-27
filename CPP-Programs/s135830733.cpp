#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  int t;
  cin>>t;
  while(t--){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<b||d<b){
	 cout<<"No"<<endl;
	 continue;
    }
    
    if(c>=b){
	 cout<<"Yes"<<endl;
	 continue;
    }

    ll g=__gcd(b,d);
    if(c<b-g+(a%g))cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
  return 0;
}

