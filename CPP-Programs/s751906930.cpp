#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, D;
    cin >> N >> D;
    vector<valarray<int>> X(N, valarray<int>(0, D));
    FOR(n, 0, N) {
        FOR(d, 0, D) {
            cin >> X.at(n)[d];
        }
    }
    int ans = 0;
    FOR(i, 0, N) {
        FOR(j, i + 1, N) {
            float x = sqrt(pow(X.at(i) - X.at(j), 2).sum());
            if (floor(x) == x) { ++ans; }
        }
    }
    cout << ans << endl;
}
