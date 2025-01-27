#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)
#define fi first
#define se second

using ll = long long;
using v_int = std::vector<int>;
using v2_int = std::vector<v_int>;
using v_ll = std::vector<ll>;
using v2_ll = std::vector<v_ll>;
using v_string = std::vector<std::string>;
using v_bool = std::vector<bool>;
using v2_bool = std::vector<v_bool>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const double PI = 3.1415926535897932;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll MOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p)
{
    return o << "{" << p.first << "," << p.second << "}";
}

template<typename T, typename U, typename V> inline
ostream& operator<<(ostream &o, tuple<T,U,V> &p)
{
    return o << "{" << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << "}";
}

template<typename T> inline
istream& operator>>(istream &is, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) {
        is >> v[i]; 
    }
    return is;
}

template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) { 
        os << v[i];
        if(i != len-1) { os << ","; } 
    } 
    return os;
}

template<typename T> inline
void chmin(T &a, T &b) { a = min(a, b); }

template<typename T> inline
void chmax(T &a, T &b) { a = max(a, b); }

struct Edge {
    int cost, to;
    Edge(int to_, int cost_) : 
        to(to_), cost(cost_) { } 
};

using Graph = vector<vector<Edge> >;

void dijkstra(Graph& g, int s, v_int &dist, v_int &prev)
{
    int n = g.size();
    dist.assign(n, INF);
    priority_queue<pii, vector<pii>, greater<pii> > que;

    dist[s] = 0;
    que.push(pii(s, 0));
    
    while(!que.empty()) {
        pii p = que.top(); que.pop();
        int node = p.fi;
        if(dist[node] < p.se) continue;

        for(auto e : g[node]) {
            if (dist[e.to] > dist[node] + e.cost) {
                dist[e.to] = dist[node] + e.cost;
                que.push(pii(e.to, dist[e.to]));
            }
        }
    }
}

int main(void)
{
    int n, k;
    cin >> n;
    Graph node(n);
    
    irep(i, n-1) {
        node[i].push_back(Edge(i+1, 1));
        node[i+1].push_back(Edge(i, 1));
    }

    int x, y;
    cin >> x >> y;
    node[x-1].push_back(Edge(y-1, 1));
    node[y-1].push_back(Edge(x-1, 1));

    v_int ans(n);
    irep(start, n) {
        v_int prev;
        v_int dist;

        dijkstra(node, start, dist, prev);
        //cout << dist << endl;
        irep(j, n) {
            if(start < j) {
                ans[dist[j]]++;
            }
        }
    }
    for(int i = 1; i < n; i++) { 
        cout << ans[i] << endl;
    }

    return 0;
}

/*atcoder*/
