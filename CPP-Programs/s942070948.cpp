#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, y;
    cin >> x >> y;
    ll z = abs(x - y);
    if (z <= 1) {
        cout << "Brown" << '\n';
    } else {
        cout << "Alice" << '\n';
    }
    return 0;
}
