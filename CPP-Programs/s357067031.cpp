#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

typedef struct tagNode_t {
  // このノードから伸びるエッジ情報
  vector<pair<int ,ll>> edges; // 各エッジの接続先のノード番号とコスト

  //ベルマンフォード法のためのデータ
  ll cost; // このノードへの現時点で判明している最小コスト
  int from; // どこから来たのか
} Node_t;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<Node_t> g(n+1);

  // src dst edge cost の順で入力がある
  rep (i, m) {
    int src, dst;
    ll cost;
    cin >> src >> dst >> cost;
    g[src].edges.push_back(make_pair(dst, -cost));
  }

  rep (j, n+1) {
    g[j].cost = LLINF;
    g[j].from = INF;
  }

  // 1番からスタートする
  // 初期化
  g[1].cost = 0;
  g[1].from = 0;

  // ベルマンフォード法
  // 
  // n-1回目でcostが更新された場合、それは負の閉路が有ることを意味している
  //
  // 辺の情報をすべて見ることを１ループとすると、
  // １ループするたびに最低でも１つの頂点についての最短距離は求まるので、
  // 頂点の数をVとするとV−1回のループでグラフ全体の最短距離を求めることができます
  //（V−1になる理由は始点はループする前に0と決定しているため。)
  // そのため、V回目のループで頂点の更新があった場合は
  // そのグラフに負の閉路があることになります。

  vector<bool> hu(n+1, false); // 負の閉路を管理する配列

  rep (i, n) {
    for (int j = 1; j <= n; j++) {
      // costが更新できるかを全ての隣接しているedgeについて調べる
      for (auto e : g[j].edges) {
        int eTo = e.first;
        ll eCost = e.second;
        if (g[eTo].cost > eCost + g[j].cost) {
          // n-1回目のループでの更新があった場合、負の閉路がある
          if (i == n-1) {
            hu[j] = true;
          }
          g[eTo].cost = eCost + g[j].cost;
          g[eTo].from = j;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (hu[j]) {
        for (auto e : g[j].edges) {
          int eTo = e.first;
          hu[eTo] = true;
        }
      }
    }
  }

  if (hu[n]) {
    cout << "inf" << endl;
    return 0;
  }
  cout << -g[n].cost << endl;
}
