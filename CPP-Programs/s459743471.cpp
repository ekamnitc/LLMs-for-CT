#include <iostream> 
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 +5;
int n, m, tot, head[maxn], color[maxn], ma;
struct edge {
	int to, nxt;
} G[maxn << 1];

inline void add_edge (int u, int v) {
	tot ++;
	G[tot].to = v;
	G[tot].nxt = head[u];
	head[u] = tot;
}

void dfs(int x, int now = 0, int fa = 0) {
	color[x] = now, now ^= 1;
    for (int j = head[x]; j; j = G[j].nxt) {
        if (color[G[j].to] == -1) dfs(G[j].to, now, x);
        if (color[G[j].to] != now) {
        	printf ("%lld\n", (long long)n * (n - 1) / 2 - m);
        	ma = 1;
        	return ;
		}
		if (ma) return ;
    }
}

int main() {
	scanf ("%d %d", &n, &m);
	int u, v;
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d", &u, &v);
		add_edge (u, v); add_edge(v, u);
	}
	memset (color, 255, sizeof (color));
	dfs(1);
	if (ma) return 0;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i]) a++;
		else b++;
	}
	printf ("%lld", (long long)a * b - m);
	return 0;
}