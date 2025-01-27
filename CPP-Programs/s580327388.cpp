#include <bits/stdc++.h>

using namespace std;

#define int long long
// #define double long double
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORR(i, a, b) for(int i = (a); i > (b); --i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt(x) __builtin_popcount(x)
#define lbit(x) __builtin_ffsll(x)
#define rbit(x) (64 - __builtin_clzll(x))
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
#define rAll(a) (a).rbegin(), (a).rend()
#define sz(s) (ll) s.size()
#define cinfast() cin.tie(0), ios::sync_with_stdio(false)
#define precise(x) cout << fixed << setprecision(x)
#define debug(x) cerr << #x << " = " << (x) << endl;
#define PERM(c)                                                                \
    sort(All(c));                                                              \
    for(bool cp = true; cp; cp = next_permutation(All(c)))
#define COMB(n, k)                                                             \
    for(ll bit = (1LL << k) - 1; bit < (1LL << n); bit = next_combination(bit))
#define PERM2(n, k)                                                            \
    COMB(n, k) {                                                               \
        vector<int> sel;                                                       \
        for(int bitindex = 0; bitindex < n; bitindex++)                        \
            if(bit >> bitindex & 1) sel.emplace_back(bitindex);                \
        PERM(sel) { Printv(sel); }                                             \
    }
#define MKORDER(n)                                                             \
    vector<int> od(n);                                                         \
    iota(All(od), 0LL);

template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
template <class Head> inline void COUT(Head &&head) { cout << (head) << "\n"; }
template <class Head, class... Tail>
inline void COUT(Head &&head, Tail &&... tail) {
    cout << (head) << " ";
    COUT(forward<Tail>(tail)...);
}

#define CCIN(...)                                                              \
    char __VA_ARGS__;                                                          \
    CIN(__VA_ARGS__)
#define DCIN(...)                                                              \
    double __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    long long __VA_ARGS__;                                                     \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Printv(v)                                                              \
    {                                                                          \
        REP(hoge, v.size())                                                    \
        cout << v[hoge] << (hoge == v.size() - 1 ? "" : " ");                  \
        cout << "\n";                                                          \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}

long long next_combination(long long sub) {
    long long x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
template <class T> inline bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

// generic lambdas
template <typename first>
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) &&                                                     \
    (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
    static inline constexpr decltype(auto)
    fix(first &&f) noexcept {
    return [f = std::forward<first>(f)](auto &&... args) {
        return f(f, std::forward<decltype(args)>(args)...);
    };
}

template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<ll, ll> PL;
typedef vector<PL> VPL;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef vector<string> VS;

const int INF = 1e9;
// const int MOD = 1e9 + 7;
const int MOD = 998244353;
const ll LINF = 1e18;
const ll dw[] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dh[] = {0, 1, 1, 1, 0, -1, -1, -1};
#define PI 3.141592653589793230
#define EPS 1e-7

PL dp[1LL << 18];

void chmax(PL &a, PL b) {
    if(b.fi > a.fi) {
        a.se = max(a.fi, b.se);
        a.fi = b.fi;
    } else
        a.se = max(b.fi, a.se);
}

void solve() {
    LCIN(N);
    VL A(1LL << N);
    VECCIN(A);
    REP(i, 1LL << N) dp[i] = PL(A[i], 0);
    REP(i, N) REP(j, 1LL << N) {
        if(j >> i & 1) {
            chmax(dp[j], dp[j & ~(1LL << i)]);
        }
    }
    ll now = 0;
    FOR(i, 1, 1LL << N) {
        now = max(now, dp[i].fi + dp[i].se);
        COUT(now);
    }
}

signed main() {
    cinfast();
    // precise(12);
    // LCIN(loop);while(loop--){solve();}
    solve();
}