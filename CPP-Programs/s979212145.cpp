#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;

void solve()
{
    LL ans = LLINF;
    LL H;
    cin >> H;
    LL W;
    cin >> W;

    // 縦-縦
    {
        LL p1_w = (W + 1) / 3;
        LL p2_w = (W - p1_w) / 2;
        LL p3_w = W - p1_w - p2_w;
        LL min_w = min(min(p1_w, p2_w), p3_w);
        LL max_w = max(max(p1_w, p2_w), p3_w);
        ans = min_w ? min(ans, H * (max_w - min_w)) : ans;
    }
    // 縦-横
    {
        LL p1_w = (W + 1) / 3;
        LL p2_h = H / 2;
        LL p2_w = W - p1_w;
        LL p3_h = H - p2_h;
        LL p1 = p1_w * H;
        LL p2 = p2_h * p2_w;
        LL p3 = p3_h * p2_w;
        LL p_min = min(min(p1, p2), p3);
        LL p_max = max(max(p1, p2), p3);
        ans = p_min ? min(ans, p_max - p_min) : ans;
    }
    // 横-横
    {
        LL p1_h = (H + 1) / 3;
        LL p2_h = (H - p1_h) / 2;
        LL p3_h = H - p1_h - p2_h;
        LL min_h = min(min(p1_h, p2_h), p3_h);
        LL max_h = max(max(p1_h, p2_h), p3_h);
        ans = min_h ? min(ans, W * (max_h - min_h)) : ans;
    }
    // 横-縦
    {
        LL p1_h = (H + 1) / 3;
        LL p2_w = W / 2;
        LL p2_h = H - p1_h;
        LL p3_w = W - p2_w;
        LL p1 = p1_h * W;
        LL p2 = p2_h * p2_w;
        LL p3 = p2_h * p3_w;
        LL p_min = min(min(p1, p2), p3);
        LL p_max = max(max(p1, p2), p3);
        ans = p_min ? min(ans, p_max - p_min) : ans;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}