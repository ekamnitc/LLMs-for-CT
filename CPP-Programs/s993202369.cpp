#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005],b[100005];
inline int read()
{int x=0;
char c=getchar();
while (c<'0'||c>'9') c=getchar();
while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
return x;
}
int main (){
	ll res=0;
	int n,k,i,j,l;
	n=read();k=read();k++;
	for (i=1;i<=n;i++)
	{a[i]=read();
	b[i]=read();
	}
	for (j=30;j>=0;j--)
	{if ((1<<j)&k)
	{int mask=(1<<j);
	for (l=30;l>j;l--)
	{if (!(k&(1<<l)))
	{mask|=(1<<l);}
	}
	ll ans=0;
	for (i=1;i<=n;i++)
	{if (a[i]&mask) {continue;}
	ans+=b[i];
	}
	if (ans>res) res=ans;
	}
	}
	printf ("%lld\n",res);
	return 0;
}
	
	
	