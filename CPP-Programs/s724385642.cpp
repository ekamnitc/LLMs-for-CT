#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 50;
int n, m;
int br;
std::vector<int> g[N];
int d[N];
bool u[N];

int dfs(int v, int p = -1) 
{
	u[v] = true;
	int md = d[v];
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != p) {
		if (u[g[v][i]]) md = std::min(d[g[v][i]], md);
		else {
			d[g[v][i]] = d[v] + 1;
			int got = dfs(g[v][i], v);
			if (got > d[v]) ++br;
			md = std::min(got, md);
		}
	}
	return md;
}

int main() 
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	printf("%d\n", br);
	return 0;
}
