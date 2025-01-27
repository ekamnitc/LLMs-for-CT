#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100002,M=998244353;
int n,i,m,tmp,b[N],c[N],cnt,j,a[N],d[N],y;
ll k,sum;
bool v[N];
double x;
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%lf",&x);
		a[i]=x;
		a[i]-=sum;
		sum+=a[i];
		c[i]=i;
	}
	scanf("%d%lld",&m,&k);
	for (i=1;i<=m;i++){
		scanf("%d",&y);
		swap(c[y],c[y+1]);
	}
	for (i=1;i<=n;i++) if (!v[i]){
		cnt=0;
		for (j=i;!v[j];j=c[j]) v[j]=1,b[++cnt]=j;
		tmp=k%cnt;
		for (j=1;j<=cnt;j++) d[b[j]]=a[b[(j+tmp-1)%cnt+1]];
	}
	for (i=1,sum=0;i<=n;i++) sum+=d[i],printf("%lld\n",sum);
}