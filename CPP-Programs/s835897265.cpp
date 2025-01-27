#include<bits/stdc++.h>
 
#define fi first
#define se second
 
#define mp make_pair
#define pb push_back
 
#define all(x) (x).begin(), (x).end()
 
#define F return
#define skip continue

#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=a;i>=n;i--)

typedef long long ll;

using namespace std;                             

typedef pair<int, int> pii;
typedef pair<ll, ll> pll; 

 
const int MAXN = 3e5 + 500;
const int INF = 1e9 + 23;
const int MOD = 1e9 + 7;

int n, a, b;
int arr[MAXN];

bool T(ll x) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll mx = max(0ll, arr[i] - (x * 1ll * b));
        ll s = (mx + a - 1) / a;
        cnt += s;
    }
    return cnt <= x;
}

void solve() {                        
    cin >> n >> a >> b;
    a -= b;
    rep(i, 1, n) cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    int l = 0, r = INF + INF, mid;
    while (l + 1 < r) {
        mid = (l + r) >> 1;
        if (T(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r;
}

int main() {                
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
     
    while (tt--) {
        solve();
        cout << '\n';
    }
 
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
*/