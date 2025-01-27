#include<iostream>
#include<algorithm>
using namespace std;
int n;
main()
{
	while(cin>>n,n)
	{
		int a[1111];
		for(int i=0;i<n;i++)cin>>a[i];
		int ans=1e9;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int A=abs(a[i]-a[j]);
				ans=ans<A?ans:A;
			}
		}
		cout<<ans<<endl;
	}
}

