#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#pragma GCC optimize(3)
using namespace std;
int n,a[100005],ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
		ans=((a[i]*2<a[i+1])?0:(ans+1));
	}
	cout<<ans<<endl;
}

