#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int N;
int a[10],b[10],c[10],d[10];


int main()
{
	ios;
	int cnt=1,res,ans,flag=0,ca=0;
	cin>>N;
	for(int i=0;i<N;i++) 
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=0;i<N;i++) cin>>b[i];
	sort(c,c+N);
	do{
		flag=0;
		for(int i=0;i<N;i++)
		{
			if(c[i]!=a[i])
			{
				flag=1;
				break;	
			}
		}
		if(!flag) 
		{
			ans=cnt;
			break;
		}
		cnt++;
	}while(next_permutation(c,c+N));
	
	sort(c,c+N);
	cnt=1;
	
	do{
		ca=0;
		for(int i=0;i<N;i++)
		{
			if(c[i]!=b[i])
			{
				ca=1;
				break;	
			}
		}
		if(!ca) 
		{
			res=cnt;
			break;
		}
		cnt++;
	}while(next_permutation(c,c+N));
	cout<<abs(ans-res)<<"\n";
	return 0;
}