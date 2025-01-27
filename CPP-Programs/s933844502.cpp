#include <bits/stdc++.h>
using namespace std;
int ans;
void check(int n)
{
	int p;	
	while (n>0)
	{
	p=n%10;
	n/=10;
	if (p==2) ans++;	
	}
}
int main()
{
	int n;
	cin >>n;
	check (n);
	cout <<ans<<endl;
	return 0;
}