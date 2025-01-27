#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define INF 2e9
#define INFLL 4e18
using namespace std;
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
const int upperlimit = 26;
const int mod = 1e9+7;
int dp[1<<upperlimit];
int main() {
	string s;
	cin >> s;
	int mask=0;
	for(int i = 0; i < s.size(); i++){
		mask^=1<<(s[i]-'a');
		for(int j = 0; j < 26; j++){
			int mask2=mask^(1<<j);
			if((dp[mask2]==0)&&(mask2!=0)) continue;
			if((dp[mask]==0)&&(mask!=0)) dp[mask]=dp[mask2]+1;
			else dp[mask]=min(dp[mask],dp[mask2]+1);
		}
	}
	int ans=dp[mask];
	ans=max(ans,1);
	pd(ans);
	return 0;
}