#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	if (n==3)
	{
		cout<<"2 5 63\n";
	}
	else
	{
		vector<int> ans={3,9,2,4};
		n-=4;
		if (n>0)
		{
			for (int i = 1; i < 5000; ++i)
			{
				if (n==1)
				{
					ans.push_back(6);
					n=0;
					break;
				}
				if (n==0)
				{
					break;
				}
				ans.push_back(6*i+2);
				ans.push_back(6*i+4);
				n-=2;
			}
		}
		if (n==1)
		{
			ans.push_back(6);
			n=0;
		}
		if (n>0)
		{
			for (int i = 2; i < 5000; i+=2)
			{
				if (n==1)
				{
					ans.push_back(6);
					n=0;
					break;
				}
				if (n==0)
				{
					break;
				}
				ans.push_back(6*i+3);
				ans.push_back(6*i+9);
				n-=2;
			}
		}
		if (n==1)
		{
			ans.push_back(6);
			n=0;
		}
		if (n>0)
		{
			for (int i = 1; i <= 5000; ++i)
			{
				ans.push_back(6*i);
				--n;
				if (n==0)
				{
					break;
				}
			}
		}
		if (n==0)
		{
			for (auto v:ans)
			{
				if (v==3)
				{
					cout<<3;
				}
				else
				{
					cout<<" "<<v;
				}
			}
		}
	}
	return 0;
}
