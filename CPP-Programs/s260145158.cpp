#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define SUM(c) accumulate(ALL(c), 0)
#define SUMLL(c) accumulate(ALL(c), 0LL)
#define SZ(c) ((int)(c).size())
#define debug(x) cerr << #x << " = " << (x) << '\n';
using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
static const double EPS = 1e-10;
static const double PI  = acos(-1.0);
static const ll MOD = 1000000007;
// static const ll MOD = 998244353;
static const int INF = 1 << 30;
// static const ll INF = 1LL << 62;
// --------------------------------------------------------


VB is_prime_numbers(int N) {
    ll root_n = (ll)(sqrt(N) + 0.5);
    VB is_prime(N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 4; i <= N; i += 2) is_prime[i] = false;
    for(int f = 3; f <= root_n; f += 2) {
        for(int i = 2 * f; i <= N; i += f) is_prime[i] = false;
    }
    return is_prime;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int Q; cin >> Q;

    static const int MAX_N = 1e+5;
    VB is_like_2017(MAX_N + 1, false);
    auto is_prime = is_prime_numbers(MAX_N);
    for (int i = 1; i <= MAX_N; i += 2) {
        if (is_prime[i] && is_prime[(i + 1) / 2]) {
            is_like_2017[i] = true;
        }
    }

    VI S(MAX_N + 1, 0);
    FOR(i, 1, MAX_N + 1) S[i] = S[i - 1] + is_like_2017[i];

    REP(_, Q) {
        int l, r; cin >> l >> r;
        cout << S[r] - S[l - 1] << '\n';
    }

    return 0;
}
