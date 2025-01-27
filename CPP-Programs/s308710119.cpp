#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> tree[100001];
ll dp[100001][2];
ll solve(ll u,bool constraint,ll parent)
{
	if(dp[u][constraint]!=-1)
		return dp[u][constraint];
	ll ans=0;
	ll ways_with_constraint=1; 
	for(ll child:tree[u])
	{
		if(child!=parent)
		{
			ways_with_constraint=(ways_with_constraint*solve(child,0,u))%1000000007;
		}
	}
	ans+=ways_with_constraint;
	if(!constraint)
	{
		ll ways_without_constraint=1;
		for(ll child:tree[u])
		{
			if(child!=parent)
			{
				ways_without_constraint=(ways_without_constraint*solve(child,1,u))%1000000007;
				//Children cannot be painted Black.
			}
		}
		ans=(ans+ways_without_constraint)%1000000007;
	}
	return dp[u][constraint]=ans;
}
int main()
{
	ll n;
	cin>>n;
	ll edges=n-1;
	memset(dp,-1,sizeof(dp));
	while(edges--)
	{
		ll x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	cout<<solve(1,0,-1);//Parent of Node u is -1.
}