#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int MOD = 998244353;
const int N = 2*1e5;
ll height[N+5]; 

int main(){
    AC
    int n;
    map<ll, ll> M;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>height[i];
        M[(ll)i-height[i]]++;
    }
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans+=M[(ll)i+height[i]];
    }
    cout<<ans<<endl;
}