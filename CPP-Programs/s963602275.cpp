#include <cstdio>
#define rep(i,n) for(int i=0;i<=n;++i)
int main(){int r,n;while(scanf("%d",&n)!=EOF){r=0;rep(a,9)rep(b,9)rep(c,9)rep(d,9)if(a+b+c+d==n)r++;printf("%d\n",r);}}