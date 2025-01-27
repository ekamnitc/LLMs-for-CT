#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

int main() {
    ll N;
    cin >> N;
    ll dp[100005][3];

    fill_n(*dp, 100005 * 3, -LLINF);
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        char op;
        ll A;
        if (i == 0) op = '+';
        else cin >> op;
        cin >> A;
        if (op == '-') A = -A;

        chmax(dp[i + 1][0], dp[i][0] + A);
        chmax(dp[i + 1][1], dp[i][1] - A);
        chmax(dp[i + 1][2], dp[i][2] + A);
        if (op == '-') {
            chmax(dp[i + 1][1], dp[i][0] + A);
            chmax(dp[i + 1][2], dp[i][1] - A);
        }
        chmax(dp[i + 1][1], dp[i][2] + A);
    }
    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    return (0);
}