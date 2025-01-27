#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)n; ++i)
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;
}