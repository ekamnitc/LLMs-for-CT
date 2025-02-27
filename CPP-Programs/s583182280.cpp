#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

vi g[MAXN];

int prv[MAXN], dis[MAXN], sz[MAXN];

void dfs(int s) {
	sz[s] = 1;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (to != prv[s]) {
			prv[to] = s;
			dis[to] = dis[s] + 1;
			dfs(to);
			sz[s] += sz[to];
		}
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	int cur = n;
	REP(i, 0, (dis[n] - 1) / 2) {
		cur = prv[cur];
	}
	if (sz[cur] * 2 < n) {
		printf("Fennec\n");
	} else {
		printf("Snuke\n");
	}
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
