#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, T; cin >> N >> T;
    int ans = inf;
    for (int i = 0; i < N; i++) {
        int c, t; cin >> c >> t;
        if (t <= T) ans = min(ans, c);
    }
    if (ans == inf) cout << "TLE" << endl;
    else cout << ans << endl;
    return 0;
}