#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define Ans(f, y, n) if(f) cout << y << endl; else cout << n << endl;
#define int long long
#define INF 1000000000000000000
using namespace std;

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
template<typename T>
void debug(vector<vector<T>> m){ REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl;} }

struct edge{int to, cost;};

class Graph
{
public:
    int V;
    vector<vector<edge>> G;

    Graph(int V): V(V){
        G = vector<vector<edge>>(V, vector<edge>(0));
    }

    void add_edge(int from, int to, int cost){
        G[from].push_back(edge({to, cost}));
    }

    void add_edge2(int v1, int v2, int cost){
        add_edge(v1, v2, cost);
        add_edge(v2, v1, cost);
    }

    void dfs(int &n, int &d, bools &used, int v, int g){
        n++;
        d += g;
        used[v] = true;
        REP(k, G[v].size()) if(!used[G[v][k].to]) dfs(n, d, used, G[v][k].to, g + 1);
    }

};

signed main(){

    int N; cin >> N;
    vector<Pii> D(N);
    REP(i, N){
        cin >> D[i].first;
        D[i].second = i;
    }
    Sort(D); Reverse(D);

    vec g(N, -1);
    map<int, set<int>> par;
    vector<Pii> ans(0);
    
    REP(i, N){
        int d = D[i].first;
        int v = D[i].second;
        int cnt = 1;
        for(int c: par[d]){
            cnt += g[c];
            ans.push_back(Pii(v, c));
        }
        g[v] = cnt;
        par[d - (N - 2 * cnt)].insert(v);
    }

    Graph G(N);
    REP(i, ans.size()){
        G.add_edge2(ans[i].first, ans[i].second, 0);
    }
    int n = 0, d = 0;
    bools used(N, false);
    G.dfs(n, d, used, D[0].second, 0);
    if(n == N && ans.size() == N - 1 && D[0].first == d){
        REP(i, N - 1) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }else{
        cout << -1;
    }


    return 0;
}