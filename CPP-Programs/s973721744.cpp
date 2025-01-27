#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define rad2deg(a) ((a)/M_PI * 180.0)
#define deg2rad(a) ((a)/180.0 * M_PI)
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n+1),b(n);
    rep(i,n+1) std::cin >> a[i];
    rep(i,n) std::cin >> b[i];

    ll ans = 0;
    rep(i,n+1){
        ll mi;
        if(a[i]>b[i]){
            ans += b[i];
        }else{
            if(a[i+1]>b[i]-a[i]){
                ans += a[i] + b[i]-a[i];
                a[i+1] -= b[i]-a[i];
            }else{
                ans += a[i] + a[i+1];
                a[i+1] = 0;
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}