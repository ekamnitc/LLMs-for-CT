#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<ctime>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<(x)<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<(x)<<":"<<#y<<"="<<(y)<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define L long
#define LL long long
#define I inline
#define U unsigned
#define START clock_t __start=clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
#define MAXN 200011
int a[MAXN],n;
bool judge(int k)
{
	for(int i=0;i<n-1;i++)
	{
		if((a[n+i]>k&&a[n+i+1]>k)||(a[n-i]>k&&a[n-i-1]>k))
			return false;
		if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))
			return true;
	}
	return a[1]<=k&&a[1]<=k;;
}



int main()
{
// 	freopen("agc006_d.in","r",stdin);
// 	freopen("agc006_d.out","w",stdout);
	n=read();
	for(int i=1;i<n<<1;a[i++]=read());
	int l=1,r=(n<<1)-1,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(judge(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",r);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}