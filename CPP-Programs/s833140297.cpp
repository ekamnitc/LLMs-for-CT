#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 5005
int n,len,dp[maxn][maxn];
char s[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	len=strlen(s);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(!j) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			if(j!=i) dp[i][j]=1ll*(dp[i][j]+2ll*dp[i-1][j+1])%mod;
			if(j) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
		}
	printf("%d\n",1ll*dp[n][len]%mod);
}