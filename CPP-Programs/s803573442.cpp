#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

ll ceil1(ll a,ll b)
{	if(a%b==0)
		return a/b;
	else
		return a/b+1;}


void solve()
{
	ll a,b;
	cin>>a>>b;
	if(a==b)
	{
		cout<<"Draw";
	}
	else if(a==1)
	{
		cout<<"Alice";
	}
	else if(b==1)
		cout<<"Bob";
	else if(a>b)
	{
		cout<<"Alice";
	}
	else
		cout<<"Bob";
	return;
}

int main()
{
	fast;
	ll q=1;
	// cin>>q;
	while(q--)
		solve();
	return 0;
}

