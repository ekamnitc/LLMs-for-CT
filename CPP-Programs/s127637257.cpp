#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int k; cin >> k;
    vector<ll> a(k);
    for (int i=0; i<k; ++i) {
        cin >> a[i];
    }
    ll mn=2, mx=2;
    for (int i=k-1; i>=0; --i) {
        mn=(mn+a[i]-1)/a[i]*a[i];
        mx=mx/a[i]*a[i]+a[i]-1;
        if (mn>mx) {
            cout << -1;
            return 0;
        }
    }
    cout << mn << ' ' << mx;
    return 0;
}