#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    ll cnt = 0;
    int idx = 0;
    while(1) {
        ans += v[idx].first * v[idx].second;
        cnt += v[idx].second;
        if (cnt >= m) {
            ans -= v[idx].first * (cnt - m);
            break;
        }
        ++idx;
    }
    cout << ans << endl;
    return 0;
}