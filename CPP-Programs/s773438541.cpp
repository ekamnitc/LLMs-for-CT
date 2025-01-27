#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100005;
vector<int> nt[maxn];
int n, sg[maxn];

void dfs(int x, int fa)
{
	for (auto v:nt[x])		if (v!=fa) dfs(v,x), sg[x]^=(sg[v]+1);
}

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n-1; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		nt[x].push_back(y);
		nt[y].push_back(x);
	}
	dfs(1,0);
	if (sg[1]) puts("Alice");else puts("Bob");
}