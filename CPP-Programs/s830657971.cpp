#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> a(5);
    rep(i, 0, 5) cin >> a[i];
    int ans = (int)INF;
    rep(i, 0, 5)
    {
        int tmp = 0;
        rep(j, 0, 5)
        {
            if (i == j)
                tmp += a[j];
            else
                tmp += (a[j] + 9) / 10 * 10;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
