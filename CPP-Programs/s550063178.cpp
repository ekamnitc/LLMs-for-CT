#include <bits/stdc++.h>
using namespace std;

long long a[200000],sum,ans;

signed main()
{
	long long n,i;
	cin >> n;
	
	for(i=1;i<=n;i++)
		cin >> a[i];

	for(i=2;i<=n;i++)
		sum=(sum+a[i])%1000000007;
		
	for(i=1;i<n;i++)
		ans=(ans+a[i]*sum)%1000000007,sum=((sum-a[i+1])%1000000007+1000000007)%1000000007;
		
		cout << ans << endl;

	return 0;
}