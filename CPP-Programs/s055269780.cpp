#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> C(N - 1), S(N - 1), F(N - 1);
    REP(i, N - 1) {
        cin >> C[i] >> S[i] >> F[i];
    }
    REP(i, N) {
        if (i == N - 1) {
            cout << 0 << endl;
            break;
        }
        int t = 0;
        FOR(j, i, N - 1) {
            if (t < S[j]) {
                t = S[j];
            }
            t = (t + F[j] - 1) / F[j] * F[j];
            t += C[j];
        }
        cout << t << endl;
    }

    return 0;
}
