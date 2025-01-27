#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;

int main(){
    ll n, a, b; cin >> n >> a >> b;

    if(a > b) {
        cout << 0 << endl;
        return 0;
    } else if(a < b && n == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll l = b*(n-1) + a, m = a*(n-1) + b;
    if(l < m) swap(l, m);
    cout << (l - m + 1) << endl;

    return 0;
}