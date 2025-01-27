#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    ll n,x;
    cin>>n>>x;
    ll a[n];
    ll mini[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        mini[i] = a[i];
    }
    ll ans = 1e18;
    for(int i=0;i<n;i++){
        ll ret = 0;
        for(int j=0;j<n;j++){
            ret += mini[j];
            mini[j] = min(mini[j], a[(j-i-1+n) % n]);
        }
        
        ans = min(ans, ret + x*i);
    }
    cout << ans << endl;
}