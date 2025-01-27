#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll L[N], R[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> vec;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    ll g = 0;
    for (int i = 0; i < n; i++) {
        g = __gcd(g, vec[i]);
        L[i] = g;
    }
    g = 0;
    for (int i = n - 1; i >= 0; i--) {
        g = __gcd(g, vec[i]);
        R[i] = g;
    }
    ll res = 0;
    for (int i = 1; i < n - 1; i++) {
        res = max(res, __gcd(L[i - 1], R[i + 1]));
    }
    cout << max({res, L[n - 2], R[1]});
    return 0;
}