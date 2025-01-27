#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s.substr(i,2)=="AC")
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}