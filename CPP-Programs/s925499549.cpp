#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N);
    for (int e = 0, l, r, d; e < M; e++) {
        cin >> l >> r >> d;
        adj[l-1].push_back({ r-1, d });
        adj[r-1].push_back({ l-1, -d });
    }

    vb visit(N);
    vi loc(N);
    for (int i = 0; i < N; i++) if (!visit[i]) {
        visit[i] = true;
        loc[i] = 0;
        for (queue<int> bfs({i}); !bfs.empty(); bfs.pop()) {
            for (auto e : adj[bfs.front()]) {
                if (visit[e.first]) {
                    if (loc[e.first] != loc[bfs.front()] + e.second) {
                        cout << "No\n";
                        return 0;
                    }
                } else {
                    visit[e.first] = true;
                    loc[e.first] = loc[bfs.front()] + e.second;
                    bfs.push(e.first);
                }
            }
        }
    }

    cout << "Yes\n";
    return 0;
}

