#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433L;

template <class T> vector<T> multivector(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto multivector(size_t N,T... t){return vector<decltype(multivector(t...))>(N,multivector(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}

class BipartiteMatching {
	vector<vector<int>> edge;
	vector<int> match, used;
    size_t N;

    int dfs(int prev) {
        used[prev] = 1;
        for(int curr:edge[prev]){
            int next = match[curr];
            if(next < 0 || (!used[next] && dfs(next)) ) {
                match[prev] = curr;
                match[curr] = prev;
                return 1;
            }
        }
        return 0;
    }

public:

	BipartiteMatching(int N) : N(N), edge(N), match(N,-1), used(N) {
		// do nothing
	}

	void makeEdge(int from, int to) {
		edge[from].push_back(to);
	}

	int maxFlow() {
		int res = 0;
        for(int i = 0; i < N; ++i) {
            if(match[i] < 0) {
                for(int j = 0; j < N; ++j) used[j] = 0;
                if(dfs(i)) res++;
            }
        }
        return res;
	}
};

//verify https://atcoder.jp/contests/arc085/tasks/arc085_c

int main() {
    int N; cin >> N;
    vector<int> xa(N),ya(N),xb(N),yb(N);
    for(int i = 0; i < N; ++i){
        cin >> xa[i] >> ya[i];
    }
    for(int i = 0; i < N; ++i){
        cin >> xb[i] >> yb[i];
    }
    BipartiteMatching d(2*N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(xa[i]<xb[j]&&ya[i]<yb[j]) d.makeEdge(i,N+j),d.makeEdge(N+j,i);
        }
    }
    cout << d.maxFlow() << endl;
    return 0;
}
