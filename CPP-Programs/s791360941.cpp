#include <stdio.h>
int k,n,s,j,a,m=998244353,d[3001];int main(){scanf("%d%d",&n,&s);while(n--){scanf("%d",&a);for(j=s+1;j-->a;)d[j]=(d[j]+d[j-a])%m;d[a]++;d[0]++;k=(k+d[s])%m;}printf("%d",k);}