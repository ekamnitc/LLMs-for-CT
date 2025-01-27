#include<bits/stdc++.h> 
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long a[n+1];
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	long long tall=0,ans=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]<tall)
			ans+=tall-a[i];
		tall=max(tall,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}