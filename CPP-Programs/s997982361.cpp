#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>

using namespace std;
const int maxn = 3e5 + 1e2;
using ll = long long;
array<int, maxn> a;
array<ll, maxn> p;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tot = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int l = a[i - 1], r = a[i];
        r += (l > r) * m;
        tot += r - l;
        if (r - l > 1) {
            ++p[l + 2];
            p[r + 1] -= (r - (l + 2) + 1) + 1;
            p[r + 2] += (r - (l + 2) + 1);
        }
    }
    partial_sum(p.begin() + 1, p.begin() + 2 * m + 1, p.begin() + 1);
    partial_sum(p.begin() + 1, p.begin() + 2 * m + 1, p.begin() + 1);

    ll ans = 0;
    for (int i = 1; i <= m; ++i) ans = max(ans, p[i] + p[i + m]);
    cout << tot - ans << endl;

}