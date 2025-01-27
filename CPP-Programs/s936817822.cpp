#include <bits/stdc++.h>
using namespace std;

#undef _GLIBCXX_DEBUG

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true": "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << "\033[33;0m" << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

template <typename T>
void debug_out (T a[], int n) {
	cerr << "{" << to_string(a[0]);
	for (int i = 1; i < n; ++i) cerr << ", " << to_string(a[i]);
	cerr << "}";
	debug_out();
}

#define LOCAL

#ifdef LOCAL
#define dbg(...)  cerr << "\033[33;1m" << "[" << #__VA_ARGS__ << "] : ", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

using LL = long long;
using PII = pair<int,int>;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x.size()))
#define sqr(x) ((x)*(x))

LL powmod (LL a, LL b, LL MOD) {
	LL ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ans % MOD;
}
const int N = 100005, MOD = 1e9+7, INF = 1e9;

// head

//your code goes there

int a, b;
int ma[105][105];
void init () {
	cin >> a >> b;
}
bool vis[105][105];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
void work () {
	bool ok = 0;
	if (a > b) swap (a, b), ok = 1;
	int t = ceil (1.0 * a / 50);
	int placeA = 1, placeB = 1;
	for (int i = 1; i <= 2*t; ++i) 
		for (int j = 1; j <= 100; ++j)
			ma[i][j] = 2;
	for (int i = 1; i <= 2*t; i+=2) {
		for (int j = 1; j <= 100; j += 2) {
			if (placeA+1 <= a) {
				++placeA;
				ma[i][j] = 1;
			}
			if (placeA == a) break;
		}
		if (placeA == a) break;
	}
	for (int i = 2*t+1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j)
			ma[i][j] = 1;
	for (int i = 2*t+2; i <= 100; i+=2) {
			for (int j = 1; j <= 100; j += 2) {
				if (placeB + 1 <= b) placeB++, ma[i][j] = 2;
				if (placeB == b) break;
			}
	}		
	int aa = 0, bb = 0;
	for (int i = 1;i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (!vis[i][j]) {
				vis[i][j] = 1;
				queue <PII> q; q.push(mp(i,j));
				while (!q.empty()) {
					PII t = q.front(); q.pop();
					for (int k = 0; k < 4; ++k) {
						int tx = t.fi + dx[k];
						int ty = t.se + dy[k];
						if (vis[tx][ty] || tx < 1 || ty < 1 || tx > 100 || ty > 100 || ma[tx][ty]!=ma[i][j]) continue;
						q.push(mp(tx,ty));
						vis[tx][ty] = 1;
					}
				}
				if (ma[i][j] == 1) aa++; else bb++;
			}
		}
	}
	printf ("100 100\n");
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (!ok) {
				if (ma[i][j] == 1) printf(".");
				else printf("#");
			} else {
				if (ma[i][j] == 1) printf("#");
				else printf(".");
			}
		}
		printf("\n");
	}

	dbg (aa, bb, a, b);
}
int main () {
	time_t tic = clock();
	int T = 1;
	//scanf("%d",&T);
	while (T--) {
		init ();
		work ();
	}
	time_t toc = clock();
	cerr << "execute time = " << (toc-tic) / CLOCKS_PER_SEC << "ms\n";
	return 0;
}