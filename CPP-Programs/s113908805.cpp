#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if(a % 2 != 0 && b % 2 != 0 && c % 2 != 0)
        cout << min(a * b, min(a * c, b * c));
    else
        cout << 0;
    return 0;
}