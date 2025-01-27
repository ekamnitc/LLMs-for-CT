#include <bits/stdc++.h>
using namespace std;

int n,k,hed[100010],cnt,ans,dis[100010],fa[100010];
struct node
{
	int to,next;
}a[200010];
inline void add(int from,int to)
{
	a[++cnt].to=to;
	a[cnt].next=hed[from];
	hed[from]=cnt;
}
inline void dfs(int x)
{
	dis[x]=1;
	for(int i=hed[x];i;i=a[i].next)
	{
		int y=a[i].to;
		if(y==fa[x])
		continue;
		fa[y]=x;
		dfs(y);
		dis[x]=max(dis[x],dis[y]+1);
	}
	if(dis[x]>=k&&fa[x]>1)
	{
		dis[x]=0;
		++ans;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		if(i==1)
		{
			if(x!=1)
			++ans;
		}
		else
		add(x,i);
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}