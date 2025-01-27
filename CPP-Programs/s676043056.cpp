#include <bits/stdc++.h>
using namespace std;

typedef ostringstream OSS; typedef istringstream ISS;
typedef long long LL;
typedef pair<int, int> PII;  typedef pair<LL, LL> PLL;
typedef vector<int>    VI;   typedef vector<VI>   VVI;   typedef vector<VVI>   VVVI;
typedef vector<LL>     VLL;  typedef vector<VLL>  VVLL;  typedef vector<VVLL>  VVVLL;
typedef vector<double> VD;   typedef vector<VD>   VVD;   typedef vector<VVD>   VVVD;
typedef vector<string> VS;   typedef vector<VS>   VVS;   typedef vector<VVS>   VVVS;
typedef vector<bool>   VB;   typedef vector<VB>   VVB;   typedef vector<VVB>   VVVB;
typedef vector<PII>    VPII; typedef vector<VPII> VVPII; typedef vector<VVPII> VVVPII;
typedef vector<PLL>    VPLL; typedef vector<VPLL> VVPLL; typedef vector<VVPLL> VVVPLL;

typedef unsigned int  UI;
typedef vector<UI>    VUI;
typedef vector<VUI>   VVUI;

#define fst first
#define snd second
// #define Y first
// #define X second
#define MP make_pair
#define PB push_back
#define EB emplace_back 
#define ALL(x)  (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define RANGEBOX(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))
#define RANGE(x, l, r) ((l) <= (x) && (x) <= (r))
#define rep(i, N)  for (int i = 0; i < (int)(N); i++)
#define rrep(i, N) for (int i = N - 1; i >= 0; i--)
#define REP(i, init, N)  for (int i = (init); i < (int)(N); i++)
#define RREP(i, N, last) for (int i = (init - 1); i >= last; i--)
#define MAXUD(orig, target) orig = max(orig, target)
#define MINUD(orig, target) orig = min(orig, target)
#define DUMP(x) cerr << #x << " = " << (x) << endl

template < typename T > inline T fromString(const string &s) { T res; ISS iss(s); iss >> res; return res; };
template < typename T > inline string toString(const T &a)   { OSS oss; oss << a; return oss.str(); };

template<typename T=int> inline void dump(vector<T> vs, bool ent=false) { rep(i, vs.size()) cout << vs[i] << (i+1==vs.size() ? '\n' : ' '); if (ent) cout << endl; }
template<typename T = int> inline void dump(vector<vector<T>> vs, bool ent=false) { rep(i, vs.size()) dump<T>(vs[i]); if (ent) cout << endl; }

const int    INF  = 0x3f3f3f3f;
const LL     INFL = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = 0x3f3f3f3f;
const int    DX[] = {1,  0, -1, 0};
const int    DY[] = {0, -1,  0, 1};
const double EPS  = 1e-12;
// const double PI   = acos(-1.0);

template<typename T = int> inline T in() { T x; cin >> x; return x; }
template<typename T = int> inline vector<T> in(int n) { vector<T> xs(n); rep(i, n) cin >> xs[i]; return xs; }
template<typename T = int> inline vector<vector<T>> in(int n, int m) { vector<vector<T>> xs(n, vector<T>(m)); rep(i, n) rep(j, m) cin >> xs[i][j]; return xs; }

int main(void) {
    int n, m;
    cin >> n >> m;
    VI counts(100010);
    VI mods(m);
    rep(i, n) {
        int x = in();
        counts[x]++;
        mods[x % m]++;
    }

    int ans = 0;
    VI use(m);
    rep(i, m) {
        int j = (m - i) % m;
        if (j < i) break;
        if (i == j) {
            int k = mods[i] / 2;
            use[i] = k * 2;
            ans += k;
        } else {
            int k = min(mods[i], mods[j]);
            use[i] = k;
            use[j] = k;
            ans += k;
        }
    }

    rep(i, m) {
        for (int j = i; j < 100010; j += m) {
            if (!use[i]) break;
            if (counts[j] && counts[j] % 2) {
                --counts[j];
                --use[i];
            }
        }

        for (int j = i; j < 100010; j += m) {
            if (!use[i]) break;
            if (counts[j]) {
                int r = min(use[i], counts[j]);
                use[i] -= r;
                counts[j] -= r;
            }
        }
    }

    for (auto x : counts) ans += x / 2;
    

    cout << ans << endl;

    return 0;
}

