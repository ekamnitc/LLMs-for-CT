#include "bits/stdc++.h"

using namespace std;
using ll = long long;

ll calc(ll n, ll x) {
    return (n / x);
}

int main() {
    ll a, b, x; cin >> a >> b >> x;
    ll ans = 0;
    if (a == 0) {
        if (b == 0) ans = 1;
        else ans = calc(b, x) + 1;
    } else {
        ans = calc(b, x) - calc(a - 1, x);
    }
    cout << ans << endl;
}