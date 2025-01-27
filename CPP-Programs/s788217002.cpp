#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int x,n;
int f[1100];
int main()
{
	cin>>x>>n;
	for (int i=1;i<=n;++i)
	{
		int y;
		cin>>y;
		if (y<0)
		{
			y=abs(y)+100;
		}
		f[y]=1;
	}
	if (f[x]==0)
	{
		cout<<x<<"\n";
		return 0;
	}
	int xiao=x-1;
	while (f[xiao]==1)
	{
		if (xiao>100)
		{
			xiao++;
		}
		else
		{
			xiao--;
		}
		if (xiao<0)
		{
			xiao=abs(xiao)+100;
		}
	}
	int da=x+1;
	while (f[da]==1)
	{
		da++;
	}
	if (xiao>100)
	{
		xiao-=100;
		xiao=-xiao;
	}
	int xc=abs(xiao-x);
	int dc=abs(da-x);
	if (xc<=dc)
	{
		cout<<xiao<<"\n";
	}
	else
	{
		cout<<da<<"\n";
	}
	return 0;
}
