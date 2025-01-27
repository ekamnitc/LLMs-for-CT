#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SZ(x) (int)((x).size())
#define xx first
#define yy second
#define pii pair<int, int>



void solve() {
    int n;
    cin >> n;

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = (n - (n % i)) / i;
        if (!(n % i))
            r--;
        ans += r - l + 1;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
