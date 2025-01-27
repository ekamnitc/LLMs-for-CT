#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll a[7];
    for(int i=0;i<7;i++){
    	cin>>a[i];
    }
    ll ans=0;
    ll b=a[0],c=a[3],d=a[4];
    if(b&&c&&d){
    	ans+=3;
    	a[0]--;
    	a[3]--;
    	a[4]--;
    }
    ans+=a[3]-(a[3]&1);
    ans+=a[4]-(a[4]&1);
    ans+=a[0]-(a[0]&1);
    ans=max(ans,2LL*(ll(b/2)+ll(c/2)+ll(d/2)));
    cout << ans+a[1]<<endl;
    return 0;
}
