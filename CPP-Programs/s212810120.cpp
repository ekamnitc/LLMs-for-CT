#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin >> v[i];
	sort(v.begin(),v.end());

	int ans = INT_MAX;
	for(int i = 0;i<n-k+1;i++)
	{
		ans = min(v[i+k-1]-v[i],ans);
	}
	cout<<ans<<endl;
}