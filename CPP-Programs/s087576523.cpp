#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;
using P  = pair<ll,ll>;

int main(){
    int a,b;
    cin >> a >> b;
    int ans = 0;
    
    rep(i,2){
        if(a<b)swap(a,b);
        ans += a;
        a--;
    }
    
    cout << ans << endl;
    
    return 0;
}