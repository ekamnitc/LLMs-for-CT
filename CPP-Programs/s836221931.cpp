#include<bits/stdc++.h>
#include <numeric>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    rep(i, n){
        ans += a[i] - 1;
    }
    cout << ans << endl;
}