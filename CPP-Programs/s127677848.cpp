#include<bits/stdc++.h>
using namespace std;
#define maxn 250010
template <typename T>inline T read()
{
    register T sum=0;
    register char cc=getchar();
    int sym=1;
    while(cc!='-'&&(cc>'9'||cc<'0'))cc=getchar();
    if(cc=='-')sym=-1,cc=getchar();
    sum=sum*10+cc-'0';
    cc=getchar();
    while(cc>='0'&&cc<='9')sum=sum*10+cc-'0',cc=getchar();
    return sym*sum;
}
template <typename T>inline T read(T &a)
{
    a=read<T>();
    return a;
}
template <typename T,typename... Others> inline void read(T& a, Others&... b)
{
    a=read(a);
	read(b...);
}
int n,m,a[maxn],cnt[maxn],ans[maxn],pos[maxn];
int main()
{
	read(n);
	m=n*n;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(ans[a[i]])
		{
			puts("No");
			return 0;
		}
		cnt[a[i]]=i;
		ans[a[i]]=i;
		pos[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cnt[i]+=cnt[i-1];
		if(cnt[i]>i)
		{
			puts("No");
			return 0;
		}
	}
	int p=1;
	for(int i=1;i<=m;i++)
	{
		if(pos[i])
		{
			for(int s=ans[i]-1;s;s--)
			{
				while(ans[p])
					p+=1;
				if(p>i)
				{
					puts("No");
					return 0;
				}
				ans[p]=ans[i];
			}
		}
	}
	p=m;
	for(int i=m;i>=1;i--)
	{
		if(pos[i])
		{
			for(int s=n-ans[i];s;s--)
			{
				while(ans[p])
					p-=1;
				if(p<i)
				{
					puts("No");
					return 0;
				}
				ans[p]=ans[i];
			}
		}
	}
	puts("Yes");
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
    return 0;
}
