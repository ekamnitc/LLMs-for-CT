#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans;
int main()
{
	cin>>n;
	a=n*800;
	for(int i=0;i<8;i++)
	{
		if(i*15<=n&&i*15+15>n)
		{
			b=i;	
		} 
	} 
	ans=a-b*200;
	cout<<ans<<endl;
    return 0;
}