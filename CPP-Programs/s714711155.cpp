#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <cstdio>
#include <complex>
#include <numeric>
#include <string.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.141592653589793238462643383279;
const double EPS = 1e-9;
const ll MOD = 998244353;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int N, K;
int H[300];
ll dp[300][301][301];
int que_si;
pl que[301];

int main() {
    cin >> N >> K;
    rep(i,N) cin >> H[i];
    vector<int> T(N+1);
    rep(i,N) T[i] = H[i];
    T[N] = 0;
    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());
    rep(i,N) {
        rep(j,T.size()) {
            if (H[i] == T[j]) H[i] = j;
        }
    }
    rep(i,N) rep(j,N+1) rep(k,N+1) dp[i][j][k] = linf;
    dp[0][1][0] = 0;
    dp[0][0][H[0]] = T[H[0]];
    for (int i = 1; i < N; i++) {
        for (int k = 0; k <= K; k++) {
            for (int h = N; h >= 0; h--) {
                if (k) dp[i][k][h] = min(dp[i][k][h], dp[i-1][k-1][h]);
                if (h >= H[i]) dp[i][k][H[i]] = min(dp[i][k][H[i]], dp[i-1][k][h]);
                else dp[i][k][H[i]] = min(dp[i][k][H[i]], dp[i-1][k][h]+T[H[i]]-T[h]);
            }
        }
    }
    ll ans = linf;
    rep(k,K+1) {
        rep(h,N+1) {
            ans = min(ans, dp[N-1][k][h]);
        }
    }
    cout << ans << endl;
}