#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    int ls[N + 1];
    ls[0] = 0;

    rep(i, N) cin >> ls[i+1];

    int ans = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i+1; j <= N; ++j)
        {
            ans += ls[i] * ls[j];
        }
    }

cout << ans << endl;
    return 0;
}