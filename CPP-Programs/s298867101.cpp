//=======================//
// coder: Andy - Tohrumi //
//=======================//

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define int long long
#define maxn 200010
#define pb push_back
#define fi first
#define se second

const int mod = 1e9+7;

typedef vector<int> vi;		typedef vector<int> vl;
typedef pair<int, int> ii; 	typedef vector<ii> vii;

// code start here //

int dp[maxn], pos[maxn], l[maxn], r[maxn];
bool check[maxn];

signed main() {
	fastio;
	int n, k, c;	cin >> n >> k >> c;
	string str;	cin >> str;
	for (int i = 1; i <= n; i++)
	{
		if (str[i-1] == 'o')
		{
			pos[i] = i;
			if (i-1-c < 0)	dp[i] = 1;
			else dp[i] = dp[i-1-c] + 1;
		}
		else 
		{
			pos[i] = pos[i-1];
			dp[i] = dp[i-1];
		}
	}
	if (dp[n] != k)
	{
		return 0;
	}
	vector<int> ans[k+1];
	vector<int> arr[k+1];
	int len = dp[n];
	for (int i = 1; i <= n; i++)
	{
		if (str[i-1] == 'o')
		arr[dp[i]].pb(i);
	}
	for (int i = 0; i <= maxn; i++)	l[i] = mod;
	for (int i = 0; i < arr[len].size(); i++)
	{
		check[arr[len][i]] = true;
		l[len] = min(l[len], arr[len][i]);
		r[len] = max(r[len], arr[len][i]);
	}
	
	for (int i = len-1; i >= 1; i--)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			int u = arr[i][j];
			if (u + c + 1 <= r[i+1])	
			{
				check[u] = true;
				l[i] = min(l[i], u);
				r[i] = max(r[i], u);
			}
			
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i])
		ans[dp[i]].pb(i);
	}
	for (int i = 1; i <= len; i++)
	{
		if (ans[i].size() == 1)	cout << ans[i][0] << endl;
	}
//	sort(ans.begin(), ans.end());
//	for (int i = 0; i < (int)ans.size(); i++)	cout << ans[i] << endl;
}
