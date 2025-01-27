#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pie 3.142857143
#define ll long long int
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define vi vector<int>
#define vlli vector<ll>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fv(i,a) for(auto i:a)
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define frv(i,c) for(auto i = c.begin(); i != c.end(); i++)

void solve()
{
	int n;
	cin >> n;
	int a[n][3];
	fr(i, 0, n)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int d[n][3];
	memset(d,  0, sizeof(d));
	d[0][0] = a[0][0];
	d[0][1] = a[0][1];
	d[0][2] = a[0][2];
	fr(i, 1, n)
	{
		fr(j, 0, 3)
		{
			int x = 0;
			fr(k, 0, 3)
			{
				if (k != j)
				{
					x = max(x, d[i - 1][k]);
				}
			}
			d[i][j] = a[i][j] + x;

		}
	}
	int x = 0;
	fr(i, 0, 3)
	{
		x = max(x, d[n - 1][i]);
	}
	cout << x << endl;


}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	//cin>>t;
	t = 1;
	while (t--)
	{
		solve();
	}


	return 0;
}